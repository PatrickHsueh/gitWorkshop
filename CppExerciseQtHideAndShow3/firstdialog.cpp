#include "seconddialog.h"
#include "firstdialog.h"
#include "ui_firstdialog.h"

FirstDialog::FirstDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstDialog),
    m_show_child(false)
{
  ui->setupUi(this);
}

FirstDialog::~FirstDialog()
{
  delete ui;
}

void FirstDialog::close_child()
{
  m_show_child = false;
}

void FirstDialog::on_pushButton_clicked()
{
  SecondDialog d;
  this->hide();
  QObject::connect(&d,SIGNAL(close_me()),this,SLOT(close_child()));
  m_show_child = true;
  while (m_show_child)
  {
    d.exec();
  }
  this->show();
}
