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

	int n1, n2;
	printf("\nEnter two positive integers: ");
	scanf("%d %d", &n1, &n2);
	int ans = gcd(n1, n2);
	printf("GCD of %d and %d : %d", n1, n2, ans);


	return;
}

// Recursion
// use IF ... to set an exit
int gcd(int n1, int n2)
{	
	if (n2 != 0){
		int x = n1%n2;
		return gcd(n2, n1%n2);
	} 
	else{
		return n1;
	}
}