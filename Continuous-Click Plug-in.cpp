#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
#include<ctype.h>
#include<Windows.h>
void SetFont(int size = 100)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;

	cfi.dwFontSize.Y = size;  //设置字体大小

	wcscpy_s(cfi.FaceName, L"黑体");  //设置字体，必须是控制台已有的
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}
int main()
{
	system("Mode con cols=50 lines=15");
	SetFont(20);
	SetConsoleTitle(LPCWSTR(L"Continuous-Click Plug-in"));
	while (true)
	{
		system("color b");
		int frequency{};
		int interval{};
		using namespace std;
		cout << "Continuous-Click Plug-in\n\n\n";
		cout << "Common to all games or applications\n";
		system("pause");
		system("cls");
		cout << "You must enter an int number. Don't ask why!\n";
		cout << "How many consecutive clicks?\n";
		cin >> frequency;
		cout << "Interval time (ms)\n";
		cin >> interval;
		system("cls");
		cout << "Please move the mouse out of the window when clicking\n";
		system("pause");
		system("cls");
		for (int i = 0; i < frequency; i++)
		{
			Sleep(interval);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(interval);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			cout << "Continuous clicks" << i + 1 << "frequency" << endl;
		}
		cout << "Funking over" << endl;
		system("pause");
		system("cls");
	}
}