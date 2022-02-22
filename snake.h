#pragma once
#include <list>
class Graphics;

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

	void Reset();
	void Move();
	void CheckCollision(Graphics graphics);
};