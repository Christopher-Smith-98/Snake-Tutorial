#pragma once
#include <iostream>
#include <Windows.h>
#include <thread>
#include <list>
#include "snake.h"
#include "input.h"
using namespace std;

class Graphics
{
public:
	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
	int w;
	int h;

	void CreateBuffer(int wIn, int hIn) {
		w = wIn;
		h = hIn;
		screen = new wchar_t[w * h];
		for (int i = 0; i < w * h; i++) screen[i] = L' ';
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		dwBytesWritten = 0;
	}

	void ClearScreen() {
		for (int i = 0; i < w * h; i++) screen[i] = L' ';
	}

	void DrawBorder()
	{
		screen[i] = L'=';
		screen[2 * w + i] = L'=';
		wsprintf(&screen[h + 5], L" T H E - S N A K E - G A M E                               SCORE: %d", nScore);
	}

	void DrawSnake(Snake snake) {
		for (auto s : snake.body)
			screen[s.y * w + s.x] = snake.bDead ? L'+' : L'O';

		screen[body.front().y * w + body.front().x] = bDead ? L'X' : L'@';
	}

	void DrawFood(Snake snake) {
		screen[snake.nFoodY * w + snake.nFoodX] = L'%';
	}

	void DrawPlayAgain(Snake snake) {
		if (snake.bDead)
			wsprintf(&screen[15 * nScreenWidth + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
	}

	void DisplayFrame() {
		WriteConsoleOutputCharacter(hConsole, screen, w * h, { 0,0 }, &dwBytesWritten);
	}

	void Draw(Snake snake)
	{
		ClearScreen();
		DrawBorder();
		DrawSnake(snake);
		DrawFood(snake);
		DrawPlayAgain(snake);
		DisplayFrame();
	}
};





