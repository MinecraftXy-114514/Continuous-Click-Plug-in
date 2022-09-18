#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:6031)
#include<cstdio>
#include<cstdlib>
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
	system("color b");
	system("Mode con cols=50 lines=15");
	SetFont(20);
	SetConsoleTitle(LPCWSTR(L"连点器"));
	printf("%s", "连点次数\n");
	int ldn{};
	scanf("%d", &ldn);
	int ldt{};
	printf("%s", "连点间隔\n");
	scanf("%d", &ldt);
	printf("%s","请把鼠标移出窗口\n");
	system("pause");
	for (int i = 0; i < ldn; ++i)
	{
		Sleep(ldt);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(ldt);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		printf("%s", "连点了一次\n");
	}
	printf("连点完毕!\n");
	system("pause");
	return 114514;
}