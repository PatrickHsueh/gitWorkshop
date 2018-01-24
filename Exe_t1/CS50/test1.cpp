#include "stdafx.h"
#include "test1.h"

void CS50_test1_1()
{
	char s[256] = "\0";
	printf("Enter your name: ");
	scanf("%[^\n]s", s);

	char *t = s;
	t[0] = 'D';

	printf("s is now: %s", s);

	return;
}