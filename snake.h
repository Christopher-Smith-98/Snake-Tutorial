#pragma once
#include <list>

struct sSnakeSegment
{
	int x;
	int y;
};

class Snake
{
	int nFoodX = 30;
	int nFoodY = 15;
	int nScore = 0;
	int direction = 3;
	bool bDead = false;
	list<sSnakeSegment> body = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };

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
};


