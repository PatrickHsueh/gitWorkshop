// Exe_t1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyCL_one.h"
#include "MyCL_two.h"
#include <WinInet.h>
#include "Test_Polymorphism.h"

#include <intrin.h> //for CPUIP

#include "CS50/test1.h"


void test1();
void test2();
void test3();
void test4();
void test5();

BOOL CheckSysVersion_NewerThanCurrent(TCHAR*);

static int ivar =10; //static 只是不消失在記憶體, 和可視範圍無關!\
                       並限制使其他檔案內無法以 extern 來使用此變數.
//int ivar =10;
CString GetWebPage(CString URL);



//-------------------------------
/*
 *	Test Class set default values in the constructor
 */
class Bar
{
	Bar();
	~Bar();
};

class Foo
{
	bool done;   // always start like this
	int qty;
	Bar * p;

public:
	Foo()                        : qty(0),              p(nullptr)    { }
	Foo(int q, Bar * bp)         : qty(q),              p(bp)         { }
	//explicit Foo(char const * s) : qty(std::strlen(s)), p(new Bar(s)) { }

	// ...
};


int _tmain(int argc, _TCHAR* argv[])
{
	//傳入參數, argv[0], argv[1], ...
	if ( argv[1])
	{
		_tprintf(argv[1]);
	}

	//test1();
	//test2();
	//test3();
	//test4();

	CS50_test1_1();

	MyCL_one mycl;
	//mycl.Run_1();
	//mycl.Run_2();
	//mycl.Run_3();
	//mycl.Run_4();
	//mycl.Run_7();

/*
	wchar_t * pstr = new wchar_t[1000];
	delete [] pstr;
	pstr = 0;
*/
	CString url = _T("http://design.archime.net/cadstore/user/logincheck.aspx?Apps=1006050054049057057048055057052055048048048048048048");
	CString rtn = _T("");
	//rtn=GetWebPage(url);

	BOOL bRet = CheckSysVersion_NewerThanCurrent(_T("windows8"));

	return 0;
}

//- ref tmp3, func_31().
void test1()
{
	wchar_t *psz1 = L"abcde"; //常數指針.
	wchar_t sz2[16] = L"abcde";
	wprintf(psz1);
	wprintf(sz2);

	wcscpy(sz2,  L"ABCDEFG");
	wcscpy(psz1, 0); // 修改常數指針 當機.


	MyCL_two ax;
	ax.x=2;
	ax.f(2)=ax.x+3;

	return;
}

void test2()
{
	int i =0;
	extern int ivar;
	static int ivar1 =5;
	i = ivar+10;
	ivar1 += ivar;

	wchar_t sz2[16] = L"abcde";

	*(sz2+16)=0; //crash

	MyCL_one mycl;
	//_tprintf(_T("\nbefore pass parameter, size of sz2: %u"), sizeof(sz2)); //tmp 是 pointer, size=4
	//mycl.Run_8(sz2, (sizeof(sz2)/sizeof(wchar_t)));
	mycl.Run_10();


	vector<int> ivec;
	for (int i=0;i<10;i++)
	{
		ivec.push_back(11);
	}

	_tprintf(_T("\nbefore pass parameter, size of ivec: %u"), sizeof(ivec)); //wrong
	size_t xx = sizeof(ivec)/sizeof(int); //wrong

	_tprintf(_T("\nbefore pass parameter, size of ivec: %u"), ivec.size()); //correct

	mycl.Run_9(ivec);

	return;
}



void test3()
{
	CA *pA = new CA;
	CA *pB = new CB;

	cout << "\nBefore swap" ;
	cout << "\naddress of pA:" << pA << endl;
	cout << "address of pB:" << pB << endl;
	//swap1(pA, pB);
	swap2(pA, pB);
	//swap3(pA, pB);

	cout << "\nAfter swap" ;
	cout << "\naddress of pA:" << pA << endl;
	cout << "address of pB:" << pB << endl;

	delete pA;
	delete pB;

	return;

}


CString GetWebPage(CString URL){
	int rtncode=0; CString result=_T("");
	CStringA sContent,sData;
	//--
	HINTERNET hSession = InternetOpen(_T("INGET"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hSession == NULL){ rtncode=1;
	}else{
		//--
		HINTERNET hHttpFile = InternetOpenUrl(hSession, URL, NULL, 0, INTERNET_FLAG_DONT_CACHE, 0);
		if (hHttpFile == NULL){ rtncode=2;
		}else{
			ULONG Number = 0; int const BLOCK=1024; char buf[BLOCK+1]={0};
			ZeroMemory(buf,BLOCK+1);
			InternetReadFile(hHttpFile, buf, BLOCK, &Number);
			while (Number > 0){
				sData.Format("%s",buf);
				sContent+=sData;
				//--
				ZeroMemory(buf,BLOCK+1);
				InternetReadFile(hHttpFile, buf, BLOCK, &Number);
			}
			InternetCloseHandle(hHttpFile); hHttpFile = NULL;
		}
		InternetCloseHandle(hSession); hSession = NULL;
	}
	//--
	if(rtncode>0) {
		result.Format(_T("ERR#%d"),rtncode);
	}else{
		result=sContent;
	}
	//--
	return result;
}

BOOL CheckSysVersion_NewerThanCurrent(TCHAR *maxVer)
{
	OSVERSIONINFO	osvi;
	BOOL			bIsNextWindows	= false; //version greater than Vista/Win7 6/6.1

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

	if (_tcsicmp(_T("windows8"), maxVer) == 0)
	{
		bIsNextWindows =
			( (osvi.dwMajorVersion > 6) ||
			( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >=2) ));
	}
	else
	{
	}

/*
	switch (iCurrentWinVer)
	{
	case 5: //Win2000,XP,server 2003
		bIsNextWindows =
			( (osvi.dwMajorVersion > 5) ||
			( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 0) ));
		break;
	case 6: //Vista, server 2008, Win7
		bIsNextWindows =
			( (osvi.dwMajorVersion > 6) ||
			( (osvi.dwMajorVersion == 7) && (osvi.dwMinorVersion >= 0) ));
		break;
	default:
		bIsNextWindows = true;
		break;
	}
*/
	if (bIsNextWindows)
	{
		::MessageBox(NULL, _T("This is Windows 8"), _T(""), MB_OK);
	}

	return  bIsNextWindows;
}

void test4()
{
	Test_boy boy;
	Test_girl girl;

	Test_Polymorphism *test1 = static_cast<Test_Polymorphism *>(&boy); //Safe, upcast to base.
	//Test_Polymorphism *test1 = new Test_boy; similar as above.

	Test_Polymorphism *test2 = &girl;

	test1->setAttackPower(50);
	test2->setAttackPower(3);

	test1->attack();
	test2->attack();


	try
	{
		Test_Polymorphism testx;
		Test_boy *pboyx;


		//pboyx = dynamic_cast<Test_boy *>(&testx);
		//pboyx = (Test_boy *)&testx;
		pboyx = static_cast<Test_boy *>(&testx); //Danger!!

		if (pboyx != NULL)
		{
			pboyx->setAttackPower(99);
			//pboyx->attack();
			pboyx->foo_1();
		}
		else
		{
			throw(0);
		}
	}
	catch (...)
	{
		cout << "dynamic_cast exception" << endl;

	}


	return;
}

/*
 *	PI and float
 */
void test5()
{
    const double PI = 4 * atan(1.0);
    //printf("output = %.1f\n", 8.0/5.0);
	printf("\noutput float = %.2f", PI);
	printf("\noutput double = %lf", PI);
	printf("\n");
    return;
}




/*
 *	Check if in VM
 */
/*
int cpuid_check()
{
	unsigned int eax, ebx, ecx, edx;
	char hyper_vendor_id[13];

	cpuid(0x1, &eax, &ebx, &ecx, &edx);
	if  (bit 31 of ecx is set) {
		cpuid(0x40000000, &eax, &ebx, &ecx, &edx);
		memcpy(hyper_vendor_id + 0, &ebx, 4);
		memcpy(hyper_vendor_id + 4, &ecx, 4);
		memcpy(hyper_vendor_id + 8, &edx, 4);
		hyper_vendor_id[12] = '\0';
		if (!strcmp(hyper_vendor_id, "VMwareVMware"))
			return 1;               // Success - running under VMware
	}
	return 0;
}

int dmi_check(void)
{
	char string[10];
	GET_BIOS_SERIAL(string);

	if (!memcmp(string, "VMware-", 7) || !memcmp(string, "VMW", 3))
		return 1;                       // DMI contains VMware specific string.
	else
		return 0;
}

#define VMWARE_HYPERVISOR_MAGIC 0x564D5868
#define VMWARE_HYPERVISOR_PORT  0x5658

#define VMWARE_PORT_CMD_GETVERSION      10

#define VMWARE_PORT(cmd, eax, ebx, ecx, edx)                            \
	__asm__("inl (%%dx)" :                                          \
	"=a"(eax), "=c"(ecx), "=d"(edx), "=b"(ebx) :    \
	"0"(VMWARE_HYPERVISOR_MAGIC),                   \
	"1"(VMWARE_PORT_CMD_##cmd),                     \
	"2"(VMWARE_HYPERVISOR_PORT), "3"(UINT_MAX) :    \
	"memory");

int hypervisor_port_check(void)
{
	uint32_t eax, ebx, ecx, edx;
	VMWARE_PORT(GETVERSION, eax, ebx, ecx, edx);
	if (ebx == VMWARE_HYPERVISOR_MAGIC)
		return 1;               // Success - running under VMware
	else
		return 0;
}

int Detect_VMware(void)
{
	if (cpuid_check())
		return 1;               // Success running under VMware.
	else if (dmi_check() && hypervisor_port_check())
		return 1;
	return 0;
}

*/




//#include <intrin.h>
//This C function will detect VM Guest OS: (Tested on Windows, compiled with Visual Studio)
bool isGuestOSVM()
{
	unsigned int cpuInfo[4];
	__cpuid((int*)cpuInfo,1);
	return ((cpuInfo[2] >> 31) & 1) == 1;
}

