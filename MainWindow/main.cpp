#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<cstdio>
#include<iostream>
#include"resource.h"

CONST CHAR g_sz_MY_WINDOW_CLASS[] = "My Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.style = 0;
	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	/*wc.hIcon = (HICON)LoadImage
	(
		hInstance,
		"Ice_cream.ico",
		IMAGE_ICON, 
		LR_DEFAULTSIZE, 
		LR_DEFAULTSIZE, 
		LR_LOADFROMFILE
	);	
	wc.hIconSm = (HICON)LoadImage
	(
		hInstance,
		"Banana.ico",
		IMAGE_ICON, 
		LR_DEFAULTSIZE, 
		LR_DEFAULTSIZE, 
		LR_LOADFROMFILE
	);*/
	wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2));
	wc.hIconSm = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	//wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = (HCURSOR)LoadImage
	(
		hInstance, 
		"cursors\\starcraft-original\\Working In Background.ani", 
		IMAGE_CURSOR, 
		LR_DEFAULTSIZE, 
		LR_DEFAULTSIZE, 
		LR_LOADFROMFILE
	);
	//wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.hInstance = hInstance;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_MY_WINDOW_CLASS;
	wc.lpfnWndProc = (WNDPROC)WndProc;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}

	INT screen_width = GetSystemMetrics(SM_CXSCREEN);
	INT screen_height = GetSystemMetrics(SM_CYSCREEN);

	INT window_width = screen_width * 3 / 4;
	INT window_height = screen_height * .75;

	INT window_start_x = screen_width / 8;
	INT window_start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,                           //ExStyles
		g_sz_MY_WINDOW_CLASS,           //Class name
		g_sz_MY_WINDOW_CLASS,           //Window title
		WS_OVERLAPPEDWINDOW,			//Window style
		window_start_x, window_start_y,   //Window position
		window_width, window_height,	//Window size
		NULL,							//Parent Window
		NULL,							//Main menu ResourceID for MainWindow or ResourceID for ChildWindow
		hInstance, 
		NULL
	);
	ShowWindow(hwnd, nCmdShow); //������ ����� ����������� ����
	UpdateWindow(hwnd);			//������������� ����

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		//TranslateMessage(&msg);
		//DispatchMessage(&msg);		
		IsDialogMessage(hwnd, &msg);
	}

	return msg.message;
}

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		//AllocConsole();
		freopen("CONOUT$", "w", stdout);
		CreateWindowEx
		(
			NULL,
			"Static",
			"����� ����� ���� ���� �������",
			WS_CHILD | WS_VISIBLE,
			10, 10,
			500, 25,
			hwnd,
			(HMENU)IDC_STATIC, 
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Edit",
			"",
			WS_CHILDWINDOW | WS_VISIBLE | WS_BORDER | WS_TABSTOP | WS_GROUP,
			10, 48,
			415, 20,
			hwnd,
			(HMENU)IDC_EDIT,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"���������",
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_GROUP,
			275, 85,
			150, 32,
			hwnd,
			(HMENU)IDC_BUTTON,
			GetModuleHandle(NULL),
			NULL
		);
		break;
	case WM_MOVE:
	case WM_SIZE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		INT window_width = rect.right - rect.left;
		INT window_height = rect.bottom - rect.top;
		CONST INT SIZE = 256;
		CHAR sz_title[SIZE]{};
		sprintf(
			sz_title, 
			"%s - Position: %ix%i;\t\tSize: %ix%i", 
			g_sz_MY_WINDOW_CLASS, 
			rect.left,
			rect.top,
			window_width,
			window_height
		);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_title);
		//printf()
	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			HWND hStatic = GetDlgItem(hwnd, IDC_STATIC);
			HWND hEdit = GetDlgItem(hwnd, IDC_EDIT);
			SendMessage(hEdit, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(GetDlgItem(hwnd, IDC_BUTTON), WM_SETTEXT, 0, (LPARAM)sz_buffer);

			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}