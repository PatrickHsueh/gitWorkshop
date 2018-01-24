#pragma once

#include "stdafx.h"

//-------------- test for pointer and reference
class CA			//base
{
public:
	CA(){m=1,n=2;};
protected:
	int m,n;
};

class CB :public CA	//derived
{
public:
	CB(){m=3,n=4;};
};


//call by ptr, 2 temp ptr are created.
//ptr itself is not changed, only the value which ptr points to is changed.
template <class T>
void swap1(T *a, T *b)
{
	T tmp = *a;  //member value
	*a = *b;
	*b = tmp;
}

template <class T>
void swap2(T *&a, T *&b)
{
	T *tmp = a;
	a = b;
	b = tmp;
}

template <class T>
void swap3(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}