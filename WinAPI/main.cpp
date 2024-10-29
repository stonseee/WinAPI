#include<Windows.h>

//#define MESSAGE_BOX

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
#ifdef MESSAGE_BOX
	MessageBox
	(
		NULL,
		"Hello WinAPI!!\nЭто MessageBox, сучка.",
		NULL,
		MB_YESNOCANCEL | MB_ICONQUESTION | MB_HELP | MB_DEFBUTTON4 | MB_SYSTEMMODAL
	);
	return 0;
#endif // MESSAGE_BOX

}