#pragma once

template <class T>
T square(const T& x) {return x*x ;}

template <class T>
bool bigger(const T& x, T y=0){
	return (x>y? true:false);
}

// my class 2
class MyCL_two
{
private:
	size_t _no;
private:
	int y;

public:
	int x;

public:
	MyCL_two(void);
	virtual ~MyCL_two(void);

	int foo(char* szTmp, char* szTmp1);

	//return sets --> this->x
	int &f (int y)
		{x=y+20; return x;}
	//return sets --> this->y
	int &g()
		{return y;}
	MyCL_two &f2()
		{return *this;}

};


