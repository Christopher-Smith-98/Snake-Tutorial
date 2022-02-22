#pragma once

// includes
#include <Windows.h>

// forward declars
class Snake;

using namespace std;

class Graphics
{
public:
	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	int w;
	int h;

	void CreateBuffer(int wIn, int hIn);
	void ClearScreen();
	void DrawBorder(Snake snake);
	void DrawSnake(Snake snake);
	void DrawFood(Snake snake);
	void DrawPlayAgain(Snake snake);
	void DisplayFrame();
	void Draw(Snake snake);
};





