#include <cassert>
#include "seconddialog.h"
#include "ui_seconddialog.h"
#include "thirddialog.h"

SecondDialog::SecondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondDialog),
    m_show_child(false)
{
  ui->setupUi(this);
}

SecondDialog::~SecondDialog()
{
  delete ui;
}

void SecondDialog::close_child()
{
  m_show_child = false;
}

void SecondDialog::closeEvent(QCloseEvent *)
{
  emit close_me();
}

void SecondDialog::on_button_back_to_first_clicked()
{
  close();
}

void SecondDialog::on_button_goto_third_clicked()
{
  ThirdDialog d;
  this->hide();
  QObject::connect(&d,SIGNAL(close_me()),this,SLOT(close_child()));
  m_show_child = true;
  while (m_show_child)
  {
    d.exec();
  }
  if (d.m_back_to_which_dialog == 1)
  {
    this->close();
  }
  else
  {
    this->show();
  }
}
