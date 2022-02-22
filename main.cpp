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

int main()
{
	Input input;
	Graphics graphics;
	Snake snake;

	graphics.CreateBuffer(nScreenWidth, nScreenHeight);
	
	while (1)
	{

		snake.Reset();	
		while (!snake.bDead)
		{
			// Update Snake Direction
			input.UpdateDirection(snake.direction);
			snake.Move();
			snake.CheckCollision(graphics, input);
			
			// Draw screen
			graphics.Draw(snake);
		}
		input.WaitForRetry();
		input.Reset();
	}
	return 0;
}

