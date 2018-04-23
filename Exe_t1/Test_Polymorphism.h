#pragma once

#include <iostream>
using namespace std;

//Base class
class Test_Polymorphism
{
public:
	Test_Polymorphism(void);
	virtual ~Test_Polymorphism(void);

public:
	int attackPower;
	virtual void setAttackPower(int i){};
	virtual void attack(){};
	
	//virtual void foo() = 0;
	virtual void foo(){};
	
};


class Test_boy: public Test_Polymorphism
{
public:
	void setAttackPower(int i)
	{
		attackPower = i;
	}
		
	void attack()
	{
		cout << "boy attack:" << attackPower << endl;
	}
	
	void foo()
	{

	}
	void foo_1()
	{
		attackPower = 33;
		cout << "boy::foo_1()" << attackPower << endl;
	}
	
	
};

class Test_girl: public Test_Polymorphism
{
public:
	void setAttackPower(int i)
	{
		attackPower = i;
	}

	void attack()
	{
		cout << "girl attack:" << attackPower << endl;
	}

	void foo()
	{

	}

};