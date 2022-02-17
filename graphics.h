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
	void Buffer()
	{
		for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
		SetConsoleActiveScreenBuffer(hConsole);
	}
		
	void Border()
	{
		wchar_t* CreateScreen(int nScreenWidth, int nScreenHeight)
		{
			for (int i = 0; i < nScreenWidth; i++)
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L" T H E - S N A K E - G A M E                               SCORE: %d", nScore);
		}
	}

	void Update()
	{
		
		//clear screen

		for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
	
		//Draw snake body

		for (auto s : body)
			screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';
		
		//Draw snake head

		screen[body.front().y * nScreenWidth + body.front().x] = bDead ? L'X' : L'@';

		//Draw food

		screen[nFoodY * nScreenWidth + nFoodX] = L'%';

		if (bDead)
			wsprintf(&screen[15 * nScreenWidth + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
		
		//Display Frame

		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth* nScreenHeight, { 0,0 }, & dwBytesWritten);
	}
	
};