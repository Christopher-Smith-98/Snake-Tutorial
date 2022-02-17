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

//snake
int nFoodX = 30;
int nFoodY = 15;
int nScore = 0;
int direction = 3;
list<sSnakeSegment> body = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };
bool bDead = false;
bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;




int main()
{
	Input input;
	Graphics graphics;
	Snake snake;


	
	while (1)
	{

		snake.Reset();	
		while (!snake.bDead)
		{
			// Update Snake Direction

			input.UpdateDirection(snake.direction);
			snake.Move();
			snake.CheckCollision();
			//Draw screen
			graphics.DrawBorder();
			graphics.Draw(snake);
		}
		
	}
	return 0;
}

