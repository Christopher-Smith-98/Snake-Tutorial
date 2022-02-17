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
	int w;
	int h;
	DWORD dwBytesWritten;

	void CreateBuffer(int wIn, int hIn)
	{
		w = wIn;
		h = hIn;
		// Create Screen Buffer
		wchar_t* screen = new wchar_t[w * h];
		for (int i = 0; i < w * h; i++) screen[i] = L' ';
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		dwBytesWritten = 0;

	}
		
	void DrawBorder()
	{
				screen[i] = L'=';
				screen[2 * w + i] = L'=';
				wsprintf(&screen[w + 5], L" T H E - S N A K E - G A M E                               SCORE: %d", nScore);
	}

	void DisplayFrame() {
		WriteConsoleOutputCharacter(hConsole, screen, w* h, { 0,0 }, & dwBytesWritten);
}

	void Draw()
	{
		
		ClearScreen();
		DrawBorder();
		DrawSnake(snake);
		DrawFood(snake);
		DrawPlayAgain(snake);

		for (int i = 0; i < w * h; i++) screen[i] = L' ';
	
		//Draw snake body

		
		
		//Draw snake head

		
		//Draw food
		void DrawFood(Snake snake) {
			screen[nFoodY * w + nFoodX] = L'%';
		}
		if (bDead)

			wsprintf(&screen[15 * w + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
		
		//Display Frame

		void DrawSnake(Snake snake) 
		{
			for (auto s : snake.body)
						screen[s.y * w + s.x] = snake.bDead ? L'+' : L'O';
			
			screen[body.front().y * w + body.front().x] = snake.bDead ? L'X' : L'@';

		}
};