#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>

#include "snake.h"
#include "graphics.h"
using namespace std;




class Input
{
public:



	void UpdateDirection(int& direction)
	{
		auto t1 = chrono::system_clock::now();
		while ((chrono::system_clock::now() - t1) < ((direction % 2 == 1) ? 120ms : 200ms))
		{
			bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
			bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;

			if (bKeyRight && !bKeyRightOld)
			{
				direction++;
				if (direction == 4) direction = 0;
			}

			if (bKeyLeft && !bKeyLeftOld)
			{
				direction--;
				if (direction == -1) direction = 3;
			}
			bKeyRightOld = bKeyRight;
			bKeyLeftOld = bKeyLeft;
		}
	}	

	void WaitForRetry() {//wait for space
		while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
	}




};
