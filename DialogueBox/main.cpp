#include<Windows.h>
#include"resource.h"

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
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
		SendMessage(GetDlgItem(hwnd, IDC_EDIT_LOGIN), WM_SETTEXT, 0, (LPARAM)"Введите имя пользователя");				
	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CHAR sz_buffer[256]{};
			SendMessage((HWND)lParam, WM_GETTEXT, 256, (LPARAM)sz_buffer);				

			if (HIWORD(wParam) == EN_SETFOCUS)
				SendMessage((HWND)lParam, WM_SETTEXT, 0, (LPARAM)"");
			if (HIWORD(wParam) == EN_SETFOCUS 
				&& strcmp(sz_buffer, "") != 0
				&& strcmp(sz_buffer, "Введите имя пользователя") != 0)
				SendMessage((HWND)lParam, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_KILLFOCUS 
				&& strcmp(sz_buffer, "") == 0)
				SendMessage((HWND)lParam, WM_SETTEXT, 0, (LPARAM)"Введите имя пользователя");
			if (HIWORD(wParam) == EN_KILLFOCUS 
				&& strcmp(sz_buffer, "") != 0
				&& strcmp(sz_buffer, "Введите имя пользователя") != 0)
				SendMessage((HWND)lParam, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			
		}
		break;
		case IDC_BUTTON_COPY:
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			//SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			//SendMessage(GetDlgItem(hwnd, IDC_BUTTON_COPY), WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
			break;
		case IDOK: MessageBox(hwnd, "Была нажата кнопка окей!!", "Info", MB_OK | MB_ICONINFORMATION); 
			break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	}
	return FALSE;
}
