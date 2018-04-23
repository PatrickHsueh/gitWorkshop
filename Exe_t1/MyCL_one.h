#pragma once

#include "..\_contrib\Logging.h"

class MyCL_base
{
//ref: http://www.exforsys.com/tutorials/c-plus-plus/c-pure-virtual-function-and-base-class.html
protected:
	virtual bool validate() const =0;

};


class MyCL_one : public MyCL_base
{
private:
	bool validate() const;

public:
	MyCL_one(void);
	virtual ~MyCL_one(void);

	unsigned ui;		//unsigned index
	virtual void Run_1 (void);
	virtual void Run_2 (void);
	void Run_3 ();

	// test loop
	unsigned int Run_4(void);

	//test int, unsigned ¬Û¥[!
	void Run_5();
	void Run_6();
	void Run_7();

	virtual void Run_8(const wchar_t name[], size_t size);
	virtual void Run_81(const wchar_t *name, size_t size);

	virtual void Run_9(vector<int> &ivec);

	void* Run_10();

};
