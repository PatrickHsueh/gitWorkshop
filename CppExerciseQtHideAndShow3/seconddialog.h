#ifndef SECONDDIALOG_H
#define SECONDDIALOG_H

#include <QDialog>

namespace Ui {
class SecondDialog;
}

class SecondDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SecondDialog(QWidget *parent = 0);
    ~SecondDialog();
    
private slots:
    void close_child();

    void on_button_goto_third_clicked();

    void on_button_back_to_first_clicked();

protected:
    void closeEvent(QCloseEvent *);

signals:
    void close_me();

private:
    Ui::SecondDialog *ui;
    bool m_show_child;
};

#endif // SECONDDIALOG_H
