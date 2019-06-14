// dtfol.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "../lsMisc/GetDesktopDir.h"
#include "../lsMisc/tstring.h"
#include "../lsMisc/stdosd/stdosd.h"
#include "../lsMisc/OpenCommon.h"

using namespace Ambiesoft;
using namespace Ambiesoft::stdosd;

#pragma comment(lib,"shlwapi.lib")

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	TCHAR szYear[32];
	TCHAR szMonth[32];
	TCHAR szDay[32];

	wsprintf(szYear, _T("%d"), st.wYear);
	wsprintf(szMonth, _T("%02d"), st.wMonth);
	wsprintf(szDay, _T("%02d"), st.wDay);

	TCHAR szAll[32];
	wsprintf(szAll, _T("%s-%s-%s"), szYear,szMonth,szDay);

	TCHAR szTarget[MAX_PATH];
	if(!GetDesktopDir(szTarget, MAX_PATH))
	{
		MessageBox(NULL, _T("No Desktop dir"), _T("dtfol"), MB_ICONERROR);
		return 1;
	}

	PathAddBackslash(szTarget);
	lstrcat(szTarget, szAll);

	if (PathIsDirectory(szTarget))
	{
		tstring message = stdFormat(_T("Directory \"%s\" already exists."), szTarget);
		MessageBox(NULL, message.c_str(), APPNAME, MB_ICONASTERISK);
	}
	else
	{
		if (!CreateDirectory(szTarget, NULL))
		{
			tstring message = stdFormat(_T("Failed to create directory \"%s\"."), szTarget);
			MessageBox(NULL, message.c_str(), APPNAME, MB_ICONERROR);
			return 1;
		}
	}
	
	if (!OpenCommon(NULL, szTarget))
	{
		tstring message = stdFormat(_T("Failed to open directory \"%s\"."), szTarget);
		MessageBox(NULL, message.c_str(), APPNAME, MB_ICONERROR);
		return 1;
	}
	return 0;
}



