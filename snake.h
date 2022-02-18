#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "graphics.h"
#include "input.h"
using namespace std;

struct sSnakeSegment
{
	int x;
	int y;
};


class Snake
{
public:
		int nFoodX;
		int nFoodY;
		int nScore;
		int direction;
		bool bDead;
		list<sSnakeSegment> body;

	void Reset()
	{
		nFoodX = 30;
		nFoodY = 15;
		nScore = 0;
		direction = 3;
		body = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };
		bDead = false;
	}

	void Move()
	{
		switch (direction)
		{
			case 0: //UP
				body.push_front({ body.front().x, body.front().y - 1 });
				break;
			case 1: //RIGHT
				body.push_front({ body.front().x + 1, body.front().y });
				break;
			case 2: //DOWN
				body.push_front({ body.front().x, body.front().y + 1 });
				break;
			case 3: //LEFT
				body.push_front({ body.front().x - 1, body.front().y });
				break;
		}
	}

	void CheckCollision(Graphics)
	{
		//Collision Detect Snake V World

		if (body.front().x < 0 || body.front().x >= nScreenWidth)
			bDead = true;
		if (body.front().y < 3 || body.front().y >= nScreenWidth)
			bDead = true;

		// Collision Detect Snake V Food

		if (body.front().x == nFoodX && body.front().y == nFoodY)
		{
			nScore++;
			while (screen[nFoodY * nScreenWidth + nFoodX] != L' ')
			{
				nFoodX = rand() % nScreenWidth;
				nFoodY = (rand() % (nScreenHeight - 3)) + 3;
			}
			for (int i = 0; i < 5; i++)
				body.push_back({ body.back().x, body.back().y });
		}

		//Collision Detect Snake V Snake

		for (list<sSnakeSegment>::iterator i = body.begin(); i != body.end(); i++)
			if (i != body.begin() && i->x == body.front().x && i->y == body.front().y)
				bDead = true;

		//Chop off the snakes tail
		body.pop_back();	
	}










};


