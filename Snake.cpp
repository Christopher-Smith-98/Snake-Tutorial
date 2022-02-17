
int nScreenWidth = 120;
int nScreenHeight = 30;

// Create Screen Buffer
wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
SetConsoleActiveScreenBuffer(hConsole);
DWORD dwBytesWritten = 0;

int nFoodX = 30;
int nFoodY = 15;
int nScore = 0;
int direction = 3;
list<sSnakeSegment> body = { {60,15}, {61,15}, {62, 15}, {63,15}, {64, 15}, {65,15}, {66,15}, {67, 15}, {68,15}, {69, 15} };
bool bDead = false;
bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;
		
