#include "stdafx.h"
#include "piorangeconvert.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PioRangeConvert w;
	w.show();
	return a.exec();
}
