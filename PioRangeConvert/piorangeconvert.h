#pragma once

#include <QtWidgets/QDialog>
#include <QMimeData>
#include "ui_piorangeconvert.h"

class PioRangeConvert : public QDialog
{
	Q_OBJECT

public:
	PioRangeConvert(QWidget *parent = Q_NULLPTR);

private:
	Ui::PioRangeConvertClass ui;

	void addStatusText(const QString& txt);

private slots:
	void add_files();
	void clear_list();
	void convert();
	void select_output_folder();
	void selection_changed();

protected:
	void dropEvent(QDropEvent* e) override;
	void dragEnterEvent(QDragEnterEvent* ev) override;
};
