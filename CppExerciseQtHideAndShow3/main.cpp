#include <QtWidgets/QApplication>
#include "firstdialog.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  FirstDialog w;
  w.show();
  a.exec();
}
