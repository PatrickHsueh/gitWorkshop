#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

    
public:
    explicit ThirdDialog(QWidget *parent = 0);
    ~ThirdDialog();

    int m_back_to_which_dialog;

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_button_back_to_first_clicked();

    void on_button_back_to_second_clicked();

signals:
  void close_me();

private:
    Ui::ThirdDialog *ui;
};

#endif // THIRDDIALOG_H
