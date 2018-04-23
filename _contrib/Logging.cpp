// Logging.cpp: implementation of the CLogging class.
//
//////////////////////////////////////////////////////////////////////

/*
 *  [7/17/2010 Patrick]
 *  Upgrading an STL-based application to use Unicode.
 *	http://www.codeproject.com/KB/stl/upgradingstlappstounicode.aspx
 */


#include "stdafx.h"

#if !defined(_CONSOLE)
	#include <direct.h>
#endif

#include "Logging.h"

#ifdef _DEBUG
	#undef THIS_FILE
	static char THIS_FILE[]=__FILE__;
	#if !defined(_CONSOLE)
		#define new DEBUG_NEW
	#endif
#endif

#define MAX_BUFFER_SIZE 4096
/*******************************************************************************
CLogging
================================================================================
Constructor

Opens output streams

*******************************************************************************/

CLogging::CLogging()
{
	nTotalErrors = 0;
	mUserOutput = NULL;
	mofMessage.open(L"log_message.log");
	mofDetailed.open(L"log_detailed.log");
	mofError.open(L"log_error.log");

	// set this to write Chinese with wofstream [3/11/2014 Patrick]
	setlocale(LC_ALL,"");
	//or better to use this!
	//mofMessage.imbue(locale(locale(),"",LC_CTYPE));
}


/*******************************************************************************
~CLogging
================================================================================
Destructor

Closes open streams.

*******************************************************************************/

CLogging::~CLogging()
{
	mofMessage.close();
	mofDetailed.close();
	mofError.close();
}


/*******************************************************************************
message
================================================================================
This function writes messages to stream and user interface.

Parameters
	const wchar_t* 		format string 
	...							optional argument list

*******************************************************************************/

void CLogging::message(const wchar_t* pszFormat, ...)
{
	wchar_t szBuffer[MAX_BUFFER_SIZE];
	va_list argList;
	va_start(argList, pszFormat);
	
	do_vsnprintf(szBuffer, sizeof(szBuffer), pszFormat, argList );
	va_end(argList);
	mofMessage << szBuffer << L"\n";
	mofDetailed << szBuffer << L"\n";
	mofMessage.flush();
	mofDetailed.flush();
	if (mUserOutput != NULL) {
		mUserOutput->AppendText(0, szBuffer);
		mUserOutput->AppendText(0, L"\r\n");
	}
}


/*******************************************************************************
error
================================================================================
This function writes error messages to stream and user interface.

Parameters
	const wchar_t* 		format string 
	...							optional argument list

*******************************************************************************/

void CLogging::error(const wchar_t* pszFormat, ...)
{
	wchar_t szBuffer[MAX_BUFFER_SIZE];
	va_list argList;
	va_start(argList, pszFormat);

	do_vsnprintf(szBuffer, sizeof(szBuffer), pszFormat, argList );
	va_end(argList);
	mofError << L"ERROR: "<< szBuffer << L"\n";
	mofDetailed << L"ERROR: "<< szBuffer << L"\n";
	mofError.flush();
	mofDetailed.flush();
	if (mUserOutput != NULL) {
		mUserOutput->AppendText(0, L"ERROR: ");
		mUserOutput->AppendText(0, szBuffer);
		mUserOutput->AppendText(0, L"\r\n");
	}
	//increase number of errors
	nTotalErrors++;
}


/*******************************************************************************
errorDetailed
================================================================================
This function writes detailed error messages to stream and user interface.

Parameters
	const wchar_t* 		format string 
	...							optional argument list

*******************************************************************************/

void CLogging::errorDetailed(const wchar_t* pszFormat, ...)
{
	wchar_t szBuffer[MAX_BUFFER_SIZE];
	va_list argList;
	va_start(argList, pszFormat);

	do_vsnprintf(szBuffer, sizeof(szBuffer), pszFormat, argList );
	va_end(argList);
	mofDetailed << L"ERROR: "<< szBuffer << L"\n";
	mofDetailed.flush();
	if (mUserOutput != NULL) {
		mUserOutput->AppendText(1, szBuffer);
		mUserOutput->AppendText(1, L"\r\n");
	}
}

/*******************************************************************************
detailed
================================================================================
This function writes detailed messages to stream and user interface.

Parameters
	const wchar_t* 		format string 
	...							optional argument list

*******************************************************************************/

void CLogging::detailed(const wchar_t* pszFormat, ...)
{
	wchar_t szBuffer[MAX_BUFFER_SIZE];
	va_list argList;
	va_start(argList, pszFormat);

	do_vsnprintf(szBuffer, sizeof(szBuffer), pszFormat, argList );
	va_end(argList);
	mofDetailed << szBuffer << L"\n";
	mofDetailed.flush();
	if (mUserOutput != NULL) {
		mUserOutput->AppendText(1, szBuffer);
		mUserOutput->AppendText(1, L"\r\n");
	}
}
