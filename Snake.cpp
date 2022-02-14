#include <iostream>
#include <list>
#include <thread>
using namespace std;

#include <Windows.h>

int nScreenWidth = 120;
int nScreenHeight = 30;

struct sSnakeSegment
{
	int x;
	int y;
};




int main()
{
	// Create Screen Buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0; 

	while (1)
	{

		list<sSnakeSegment> snake = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nSnakeDirection = 3;
		bool bDead = false;
		bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;


		while (!bDead)
		{
			//Timing and Input
		
			//Get Input
			auto t1 = chrono::system_clock::now();
			while ((chrono::system_clock::now() - t1) < ((nSnakeDirection % 2 == 1) ? 120ms : 200ms))
			{
				bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
				bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;

				if (bKeyRight && !bKeyRightOld)
				{
					nSnakeDirection++;
					if (nSnakeDirection == 4) nSnakeDirection = 0;
				}

				if (bKeyLeft && !bKeyLeftOld)
				{
					nSnakeDirection--;
					if (nSnakeDirection == -1) nSnakeDirection = 3;
				}
				bKeyRightOld = bKeyRight;
				bKeyLeftOld = bKeyLeft;
			}
			//Game Logic
			//Update Snake Postion
			switch (nSnakeDirection)
			{
			case 0: //UP
				snake.push_front({ snake.front().x, snake.front().y - 1 });
				break;
			case 1: //RIGHT
				snake.push_front({ snake.front().x + 1, snake.front().y });
				break;
			case 2: //DOWN
				snake.push_front({ snake.front().x, snake.front().y + 1 });
				break;
			case 3: //LEFT
				snake.push_front({ snake.front().x - 1, snake.front().y });
				break;
			}

			//Collision Detection
			//Collision Detect Snake V World
			if (snake.front().x < 0 || snake.front().x >= nScreenWidth)
				bDead = true;
			if (snake.front().y < 3 || snake.front().y >= nScreenWidth)
				bDead = true;


			// Collision Detect Snake V Food
			if (snake.front().x == nFoodX && snake.front().y == nFoodY)
			{
				nScore++;
				while (screen[nFoodY * nScreenWidth + nFoodX] != L' ')
				{
					nFoodX = rand() % nScreenWidth;
					nFoodY = (rand() % (nScreenHeight - 3)) + 3;
				}

				for (int i = 0; i < 5; i++)
					snake.push_back({ snake.back().x, snake.back().y });
			}

			//Collistion Detect Snake V Snake
			for (list<sSnakeSegment>::iterator i = snake.begin(); i != snake.end(); i++)
				if (i != snake.begin() && i->x == snake.front().x && i->y == snake.front().y)
					bDead = true;
			//Chop off the snakes tail
			snake.pop_back();

			//Display to player
			for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';

			//Draw Stats and Border
			for (int i = 0; i < nScreenWidth; i++)
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L" T H E - S N A K E - G A M E                               SCORE: %d", nScore);

			//Draw snake body
			for (auto s : snake)
				screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';

			//Draw snake head
			screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

			//Draw food
			screen[nFoodY * nScreenWidth + nFoodX] = L'%';

			if (bDead)
				wsprintf(&screen[15 * nScreenWidth + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
			//Display Frame
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
		}

		//Wait for player to press space
		while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
	}
		return 0;
}
