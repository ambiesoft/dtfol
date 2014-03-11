// dtfol.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "../MyUtility/GetDesktopDir.h"
#pragma comment(lib,"shlwapi.lib")

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	SYSTEMTIME st;
	GetLocalTime(&st);

	TCHAR szYear[32];
	TCHAR szMonth[32];
	TCHAR szDay[32];

	wsprintf(szYear, _T("%d"), st.wYear);
	wsprintf(szMonth, _T("%02d"), st.wMonth);
	wsprintf(szDay, _T("%0d"), st.wDay);

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

	CreateDirectory(szTarget, NULL);
//	ShellExecute(NULL, _T("open"), _T("C:\\LegacyPrograms\\mdie\\MDIE.exe"),
//		szTarget, NULL, SW_SHOW);
	return 0;
}



