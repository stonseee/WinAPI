#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include"resource.h"
#include <stdlib.h> 
//#include <iostream>
#include <string>
using namespace std;

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{		
		case IDC_BUTTON_PLUS:
		{
			CONST INT SIZE = 256;
			CHAR edit1[SIZE]{};
			CHAR edit2[SIZE]{};
			CHAR res[SIZE]{};
			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);			
			SendMessage(hEdit1, WM_GETTEXT, SIZE, (LPARAM)edit1);
			SendMessage(hEdit2, WM_GETTEXT, SIZE, (LPARAM)edit2);			
			if (strcmp(edit1, "") == 0 || strcmp(edit2, "") == 0)
				break;
			DOUBLE result = stod(edit1) + stod(edit2);
			string str = to_string(result);
			strcpy(res, str.c_str());
			MessageBox(hwnd, res, "Info", MB_OK | MB_ICONINFORMATION);			
		}
			break;
		case IDC_BUTTON_MINUS:
		{
			CONST INT SIZE = 256;
			CHAR edit1[SIZE]{};
			CHAR edit2[SIZE]{};
			CHAR res[SIZE]{};
			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
			SendMessage(hEdit1, WM_GETTEXT, SIZE, (LPARAM)edit1);
			SendMessage(hEdit2, WM_GETTEXT, SIZE, (LPARAM)edit2);
			if (strcmp(edit1, "") == 0 || strcmp(edit2, "") == 0)
				break;
			DOUBLE result = stod(edit1) - stod(edit2);
			string str = to_string(result);
			strcpy(res, str.c_str());
			MessageBox(hwnd, res, "Info", MB_OK | MB_ICONINFORMATION);
		}
			break;
		case IDC_BUTTON_MULTIPLY:
		{
			CONST INT SIZE = 256;
			CHAR edit1[SIZE]{};
			CHAR edit2[SIZE]{};
			CHAR res[SIZE]{};
			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
			SendMessage(hEdit1, WM_GETTEXT, SIZE, (LPARAM)edit1);
			SendMessage(hEdit2, WM_GETTEXT, SIZE, (LPARAM)edit2);
			if (strcmp(edit1, "") == 0 || strcmp(edit2, "") == 0)
				break;
			DOUBLE result = stod(edit1) * stod(edit2);
			string str = to_string(result);
			strcpy(res, str.c_str());
			MessageBox(hwnd, res, "Info", MB_OK | MB_ICONINFORMATION);
		}
			break;
		case IDC_BUTTON_DIVIDE:
		{
			CONST INT SIZE = 256;
			CHAR edit1[SIZE]{};
			CHAR edit2[SIZE]{};
			CHAR res[SIZE]{};
			HWND hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
			HWND hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
			SendMessage(hEdit1, WM_GETTEXT, SIZE, (LPARAM)edit1);
			SendMessage(hEdit2, WM_GETTEXT, SIZE, (LPARAM)edit2);
			if (strcmp(edit1, "") == 0 || strcmp(edit2, "") == 0)
				break;
			DOUBLE result = stod(edit1) / stod(edit2);
			string str = to_string(result);
			strcpy(res, str.c_str());
			MessageBox(hwnd, res, "Info", MB_OK | MB_ICONINFORMATION);
		}
			break;
		case IDOK:
		{			
			MessageBox(hwnd, "Вы нажали ОК.", "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;		
		case IDCANCEL:
			EndDialog(hwnd, 0);
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}



