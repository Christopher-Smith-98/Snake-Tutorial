// Includes
#include <iostream>
#include <thread>
#include "snake.h"
#include "graphics.h"
#include "input.h"
#include <list>
using namespace std;

int main()
{
	Graphics graphics;
	Snake snake;
	graphics.Buffer();
	
	while (1)
	{
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

