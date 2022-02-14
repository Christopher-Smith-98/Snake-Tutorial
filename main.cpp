// Includes
#include <iostream>
#include <thread>
#include "snake.h"

using namespace std;

// Globals
int nScreenWidth  = 120;
int nScreenHeight = 30;


int main()
{
	wchar_t* screen = CreateScreen(nScreenWidth, nScreenHeight);



	while (1)
	{
		Snake snake = Snake();
		snake.Reset();

		while (!snake.bDead)
		{
			// Update Snake Direction
			UpdateDirection(snake.direction);

			//Move Snake

			//Collision Detection

			//Has Eaton Food


			//Draw screen

			

		}
		//wait for snake
	}






}

