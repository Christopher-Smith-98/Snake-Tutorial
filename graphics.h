#pragma once
#include <Windows.h>


class Graphics
{
	wchar_t* CreateScreen(int nScreenWidth, int nScreenHeight) {

		// Create Screen Buffer
		wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
		HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		DWORD dwBytesWritten = 0;

		return screen;
	}
	
};