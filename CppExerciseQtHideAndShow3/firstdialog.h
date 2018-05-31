#ifndef FIRSTDIALOG_H
#define FIRSTDIALOG_H

#include <QDialog>

namespace Ui {
class FirstDialog;
}

class FirstDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FirstDialog(QWidget *parent = 0);
    ~FirstDialog();
    
private slots:
    void close_child();
    void on_pushButton_clicked();

private:
    Ui::FirstDialog *ui;
    bool m_show_child;
};

#endif // FIRSTDIALOG_H
