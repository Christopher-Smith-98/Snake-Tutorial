#pragma once
using namespace std;
typedef chrono::milliseconds ms;
class Input
{
public:
	bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;
	float gameTickRate = 200.0;
	float startingGameTickRate = gameTickRate;
	float aspectratio = 0.6;
	void UpdateDirection(int& direction);
	void WaitForRetry();
	void Reset();
};
