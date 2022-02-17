// Includes
#include <iostream>
#include <thread>
#include <list>
#include <Windows.h>
#include "snake.h"
#include "graphics.h"
#include "input.h"
using namespace std;


int nScreenWidth = 120;
int nScreenHeight = 30;


int nFoodX = 30;
int nFoodY = 15;
int nScore = 0;
int direction = 3;
list<sSnakeSegment> body = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };
bool bDead = false;
bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;




int main()
{

	Graphics graphics;
	Snake snake;
	graphics.Buffer();
	
	while (1)
	{
		// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

		snake.Reset();	
		while (!snake.bDead)
		{
			// Update Snake Direction
			Input input;
			input.UpdateDirection(direction);
			snake.Move();
			snake.Collision();
			//Draw screen
			graphics.Border();
			graphics.Update();
		}
		//wait for space
		while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
	}
	return 0;
}

