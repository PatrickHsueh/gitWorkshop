#include "StdAfx.h"
#include "MyCL_one.h"
#include <fstream>
#include "lexical_cast.hpp"

extern int ivar;

#define INT_MAX1  32767
#define INT_MIN1 -32768
int my_atoi(const char * str)
{
	if(!str) return 0;  
	int result = 0;  
	int sign = 1;  
	//提取+ -号  
	if(*str == '-' || *str == '+')  
	{  
		if(*str =='-')
		{  
			sign = -1;  
		}  
		str++;  
	}  
	while('0'<*str && *str<'9')  
	{  
		int digit = *str - '0';  
		if(result > INT_MAX || (sign > 0?(result == INT_MAX/10 &&digit > INT_MAX%10):(result == (unsigned int)(INT_MAX+1)/10 && digit > (unsigned int)(INT_MAX+1) % 10)))  
		{  
			return  sign>0? INT_MAX : INT_MIN;  
		}  
		result = result*10+digit;  
		str++;  
	}  
	return result*sign;  
}

MyCL_one::MyCL_one(void)
{
}

MyCL_one::~MyCL_one(void)
{
}

bool MyCL_one::validate(void) const
{
	return false;
}

//Vector test
void MyCL_one::Run_1(void)
{
	CLogging logxx;

	vector<int> v;
	v.push_back(11);
	v.push_back(222);

	vector<int>::iterator i = v.begin();
	cout << "\n v.begin -> i = " << *i << endl;
	logxx.message(L"Test %d", *i);
	//logxx.message(L"中文字測試 %d", *i);

	return;
}

void MyCL_one::Run_2(void)
{
	static int foo =1;
	cin >> foo;
	cout << foo << endl;

	wfstream wfo;

	return;
}

//ofstream
void MyCL_one::Run_3(void)
{
	ofstream foo("data.tmp", ios_base::out | ios_base::binary);

	for (int i=1100; i<1110; ++i)
		foo.write(reinterpret_cast<char*>(&i), sizeof(i));
	foo.close();

	return;
	
}

//test loop for my strcat
/*
 * 設定指標 save 成 source，再將 s 指標指向最後，
 * 接下來根據 append 字串一個一個往後串接，直到碰到 \0 終止 while 迴圈，
 * 最後在將指標 *save 回傳即可	
 */
char* test_strcat(char *szSource, const char *szAppend)
{
	char *szSave = szSource;
	for (; *szSource; ++szSource);
	while((*szSource++ = *szAppend++));

	return szSave;
}

void test()
{
	static unsigned int ixx=0;
	ixx++;
	++ixx;
	return;	
}

// test loop
unsigned int MyCL_one::Run_4(void)
{
	test();
	test();
	//ixx++; //static not defined locally.

	//為了怕它的內容是亂碼，我們可以在宣告時，就把字元陣列裡每個字元設為\0。
	//將{0}設成字元陣列的初始值就可以做到這樣子。
	char str[80]={0};
	TCHAR sttr[80]={0};
	wchar_t wstr[80]={0};

	strcpy_s(str, sizeof(str), "Start");
	test_strcat(str, " second");
	test_strcat(str, " third.");

	cout <<str<<endl;
	return 0;
}


//unsigned int, int 相加時, int 會被轉為 unsigned. Ref: 二補數
void MyCL_one::Run_5()
{
	unsigned uix = 5u;
	unsigned uix2 = 0;
	int ix = -10;
	uix2 = static_cast<unsigned> (ix);

	cout <<"\nanswer: " << (uix + ix) << endl;
	return;
}


void MyCL_one::Run_6()
{
	string in;
	
	while (cin >> in)
	{
		cout << in << endl;
		in = "kopwejrkp";
		printf_s("input is: %s", in.c_str());//轉為 char[]
	}

	//size_t 用法
	size_t i,j;
	int k =0;
	const size_t rsize = 3; 
	const size_t csize = 4; 
	int A[rsize][csize]; 
	for ( i=0; i!=rsize;i++) {
		for( j=0;j!=csize;j++) {
			A[i][j]=k++;
			cout << A[i][j] << endl;
		}
	}
	return;
}

/* linux version
# cat simple.cpp
#include <stdio.h>

#include <string>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	printf("Hello!\n");
	string in;
	while (cin >> in)
	{
		cout << in << endl;
		in = "Test test...";
		printf("input is: %s", in.c_str());
	}
	return 0;
}

build
# g++ -Wall -g -o simple simple.cpp

*/

/*
 *	test printf format specifier
 *  http://msdn.microsoft.com/en-us/library/wc7014hz%28VS.71%29.aspx
 */
void MyCL_one::Run_7()
{
	wstring wstr = L"my wstring";
	int		count = -136;
	int		count1 = 136;	
	UINT	ui	= 136285u;
	long	la	= -136285l;
	double	fp	= 1362.6285;
	float   fa	= 5897E-2f;
	int		count2 = 0;

	printf( "Integer formats of \"int count\":\n"
		"\tDecimal: %d  Justified: %.6d  Justified: %6d  "
		"Unsigned: %u\n",
		count, count, count,count);
	printf("Decimal %d as:\n	Hex: %Xh	C hex: 0x%x	Octal: %o\n",
		count, count, count);
	//display real number
	printf("Real numbers:\n	%f  %.2f  %e  %E\n",fp,fp,fp,fp);
	
	//wchar_t tmp[]=L"2619907947";	
	//count2 = _wtoi(tmp); //overflow.
	char tmp[]="261990794"; //might overflow too.
	// convert the character to a string then to an integer, boost::lexical_cast is slower than atoi.
	int digit = boost::lexical_cast<int>(std::string(tmp));

	printf("\n");
	printf("digit, Decimal %d as:\n	Hex: %Xh	C hex: 0x%x	Octal: %o\n",
		digit, digit, digit);

	return;
}

// 傳入的 wchar 陣列 name, 成為 name 指針.
// pass by pointer.
// 傳入的陣列都變成指針!
void MyCL_one::Run_8(const wchar_t name[], size_t size)
{
	wchar_t *tmp=new wchar_t[size];
	_tcscpy_s(tmp,size,name);

	_tprintf(_T("\nsize of name: %u"), sizeof(name)); //tmp 是 pointer, size=4
	_tprintf(_T("\nsize of tmp: %u"),  sizeof(tmp)); //tmp 是 pointer, size=4
	_tprintf(_T("\ntest: %s"), tmp);

	delete [] tmp;

	return;
}

//等同上式
void MyCL_one::Run_81(const wchar_t *name, size_t size)
{

	return;
}

void MyCL_one::Run_9(vector<int> &ivec)
{
	_tprintf(_T("\nsize of ivec passed in: %u"), sizeof(ivec)); //tmp 是 pointer, size=4
	return;
}

void* MyCL_one::Run_10()
{
	int i=0;
	//extern int ivar1;
	//extern int ivar;
	//i = ivar;
	return &i;
}

