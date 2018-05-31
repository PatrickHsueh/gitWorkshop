#ifndef QTAPP1_H
#define QTAPP1_H

#include <QtWidgets/QMainWindow>
#include "ui_qtapp1.h"

class qtApp1 : public QMainWindow
{
	Q_OBJECT

public:
	qtApp1(QWidget *parent = 0);
	~qtApp1();

private:
	Ui::qtApp1Class ui;

private slots:
	void updateProgressBar();
	void btnCancel();
	
};

#endif // QTAPP1_H
