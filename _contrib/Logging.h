// Logging.h: interface for the CLogging class.
//
//////////////////////////////////////////////////////////////////////

#if defined(_WIN32)
#pragma warning(disable:4996)  // disable deprecation warning in VS2005
#endif 

#include <fstream>
using namespace std;

#include <stdio.h>

#define ANSI            /* Comment out for UNIX version     */
#ifdef ANSI             /* ANSI compatible version          */
#include <stdarg.h>
//int average( int first, ... );
#else                   /* UNIX compatible version          */
#include <varargs.h>
//int average( va_list );
#endif

// different handling for Win and other OS
#ifdef _WIN32						
  #define do_vsnprintf(buffer, count, format, argptr) \
	  _vsnwprintf(buffer, count, format, argptr)
#else
  #define do_vsnprintf(buffer, count, format, argptr) \
	  vsnprintf(buffer, count, format, argptr)
#endif // _WIN32


#if !defined(__LOGGING_H__)
#define __LOGGING_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COutput
{
public:
	virtual ~COutput(){}
	virtual void SetText(int iLoglevel, const wchar_t *pszText){}
	virtual void AppendText(int iLoglevel, const wchar_t *pszText){}
};

class CLogging  
{
public:
	int nTotalErrors;
	CLogging();
	virtual ~CLogging();
	void message(const wchar_t* pszFormat, ...);
	void detailed(const wchar_t* pszFormat, ...);
	void errorDetailed(const wchar_t* pszFormat, ...);
	void error(const wchar_t* pszFormat, ...);
	COutput *mUserOutput;

protected:
	wofstream mofDetailed;
	wofstream mofError;
	wofstream mofMessage;
};


#endif // !defined(__LOGGING_H__)
