#include "stdafx.h"
#include "piorangeconvert.h"

PioRangeConvert::PioRangeConvert(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.folderEdit->setText(QDir::currentPath());
	setAcceptDrops(true);
}

void PioRangeConvert::add_files()
{
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("txt files"), QDir::currentPath(), tr("Piosolver range files (*.txt)"));
	for (auto s : filenames)
		ui.fileList->addItem(s);
}


void PioRangeConvert::clear_list()
{
	ui.fileList->clear();
}


void PioRangeConvert::convert()
{
	FILE* fp=0;
	int overwrite = -1;	// 1 to overwrite, 0, to skip, -1 to ask and set overwrite
	int c = ui.fileList->count();

	ui.status->clear();
	if (c == 0) {
		addStatusText("no files to convert");
		return;
	}

	auto outFolder = ui.folderEdit->text().toStdString();
	for (int i = 0; i < c; ++i) {
		QString s = QString::number(i);
		QModelIndex* model_index = new QModelIndex(ui.fileList->model()->index(i, 0)); //0th column since we have one cloumn in listwidget
		QString q = model_index->data(Qt::DisplayRole).toString();
		auto out = parse_file(q.toStdString());

		auto fname = QUrl(q).fileName().toStdString();
		fname = outFolder + "/" + fname;

		if (out.size() == 0) {
			addStatusText(q + " => " + fname.c_str() + " [FAILED]");
			continue;
		}


		fp = fopen(fname.c_str(), "rt");
		if (fp) {
			if (overwrite == -1) {
				QMessageBox msgBox;
				msgBox.setText(QString("File ") + fname.c_str() + " exists");
				msgBox.setInformativeText("Do you want to overwrite ?");
				msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::YesToAll | QMessageBox::NoToAll);
				msgBox.setDefaultButton(QMessageBox::YesToAll);
				int ret = msgBox.exec();
				if (ret == QMessageBox::No) continue;
				if (ret == QMessageBox::YesToAll) overwrite = 1;
				if (ret == QMessageBox::NoToAll) overwrite = 0;
			}
			if (overwrite == 0) {
				addStatusText(q + " => " + fname.c_str() + " [SKIP]");
				continue;
			}
			fclose(fp);
		}
		
		fp = fopen(fname.c_str(), "wt");
		if (fp) {
			//QMessageBox::question(this, "Test", QString(fname.c_str()), QMessageBox::Ok);
			fprintf(fp, "%s", out.c_str());
			fclose(fp);

			addStatusText(q + " => " + fname.c_str() + " [OK]");
		}
	}
}


void PioRangeConvert::select_output_folder()
{
	QString dirStr = QFileDialog::getExistingDirectory(this, tr("Select output folder"), QDir::currentPath());
	if (dirStr.size() > 0) 
		ui.folderEdit->setText(dirStr);
}


void PioRangeConvert::dropEvent(QDropEvent* e)
{
	foreach(const QUrl & url, e->mimeData()->urls()) {
		QString fileName = url.toLocalFile();
		QFileInfo fileInfo(fileName);
		
		if (fileInfo.isDir()) {
			for (auto fname : QDir(fileName).entryList()) {
				QFileInfo fileInfo(fileName);
				if (fname.toLower().endsWith(".txt"))
					ui.fileList->addItem(fileInfo.absoluteFilePath()+"/"+fname);
			}
		} else if (fileInfo.isFile())
			if (fileName.toLower().endsWith(".txt"))
				ui.fileList->addItem(fileName);
	}
}

void PioRangeConvert::dragEnterEvent(QDragEnterEvent* ev)
{
	ev->acceptProposedAction();
}

void PioRangeConvert::addStatusText(const QString& txt)
{
	ui.status->moveCursor(QTextCursor::End);
	ui.status->insertPlainText(txt + "\n");
	ui.status->moveCursor(QTextCursor::End);
}

void PioRangeConvert::selection_changed()
{
	ui.status->clear();
	for (auto x : ui.fileList->selectedItems()) {
		QString q = x->text();
		auto out = parse_file(q.toStdString());
		if (out.size() == 0) {
			addStatusText(q + " => " + " Not a valid Piosolver range file");
			continue;
		}

		addStatusText(QString("[") + q + "]");
		
		FILE* fp = fopen(q.toStdString().c_str(), "rt");
		if (fp) {
			char buf[4096];
			memset(buf, 0, sizeof(buf));
			fgets(buf, 4096, fp);
			fclose(fp);
			addStatusText(buf);
		}

		addStatusText("------------------------------------------------------");
		
		addStatusText(out.c_str());

	}
}

