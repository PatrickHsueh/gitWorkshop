#include "qtapp1.h"
#include <QtCore/QTime>
#include <QtWidgets/QDialog>

// this is Ver: 1+1 = 2
// home, v2.5
// v3 from office.

qtApp1::qtApp1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.buttonCancel, SIGNAL(clicked()), this, SLOT(btnCancel()));
	connect(ui.buttonOK, SIGNAL(clicked()), this, SLOT(updateProgressBar()));
	
}

qtApp1::~qtApp1()
{

}

void delay()
{
	QTime dieTime= QTime::currentTime().addSecs(1);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void qtApp1::updateProgressBar()
{
	//QProgressBar bar;
	int j=1;
	for (; j<3;j++)
	{
		for(int i = 0; i <= 100; i+=10)
		{
			delay();
			ui.progressBar->setValue(i);
		}
	}
	return;
}

void qtApp1::btnCancel()
{
	close();

}