#include "qtapp1.h"
#include <QtWidgets/QApplication>


void test();


int main(int argc, char *argv[])
{
	test();

	QApplication a(argc, argv);
	qtApp1 w;
	w.show();
	return a.exec();
	return 0;
}

void test()
{
	char s[256] = "\0";
	scanf(s, "Input string:");

	char *t = s;
	t[0] = 'D';

	printf("s is now %s:", s);
	
	return;
}