// dtfol.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

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
	wsprintf(szAll, _T("%s/%s/%s"), szYear,szMonth,szDay);

	SHGetSpecialFolderLocation(
	return 0;
}



