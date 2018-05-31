#include "thirddialog.h"
#include "ui_thirddialog.h"

ThirdDialog::ThirdDialog(QWidget *parent) :
    QDialog(parent),
    m_back_to_which_dialog(2), //When user closes the dialog, go back to the previous/second dialog
    ui(new Ui::ThirdDialog)
{
  ui->setupUi(this);
}

ThirdDialog::~ThirdDialog()
{
  delete ui;
}

void ThirdDialog::closeEvent(QCloseEvent *)
{
  emit close_me();
}

void ThirdDialog::on_button_back_to_first_clicked()
{
  m_back_to_which_dialog = 1;
  close();
}

void ThirdDialog::on_button_back_to_second_clicked()
{
  m_back_to_which_dialog = 2;
  close();
}
