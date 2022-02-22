#include <iostream>
#include <thread>
#include <list>
#include "graphics.h"
#include "snake.h"
#include "input.h"
using namespace std;

void Graphics::CreateBuffer(int wIn, int hIn) {
	w = wIn;
	h = hIn;
	screen = new wchar_t[w * h];
	for (int i = 0; i < w * h; i++) screen[i] = L' ';
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;
}

void Graphics::ClearScreen() {
	for (int i = 0; i < w * h; i++) screen[i] = L' ';
}

void Graphics::DrawBorder(Snake snake)
{
	for (int i = 0; i < w; i++)
	{
		screen[i] = L'=';
		screen[2 * w + i] = L'=';
	}
	wsprintf(&screen[h + 5], L" T H E - S N A K E - G A M E                               SCORE: %d", snake.nScore);
}

void Graphics::DrawSnake(Snake snake) {
	for (auto s : snake.body)
		screen[s.y * w + s.x] = snake.bDead ? L'+' : L'O';

	screen[snake.body.front().y * w + snake.body.front().x] = snake.bDead ? L'X' : L'@';
}

void Graphics::DrawFood(Snake snake) {
	screen[snake.nFoodY * w + snake.nFoodX] = L'%';
}

void Graphics::DrawPlayAgain(Snake snake) {
	if (snake.bDead)
		wsprintf(&screen[15 * w + 40], L"    PRESS 'SPACE' TO PLAY AGAIN!    ");
}

void Graphics::DisplayFrame() {
	WriteConsoleOutputCharacter(hConsole, screen, w * h, { 0,0 }, &dwBytesWritten);
}

void Graphics::Draw(Snake snake)
{
	ClearScreen();
	DrawBorder(snake);
	DrawSnake(snake);
	DrawFood(snake);
	DrawPlayAgain(snake);
	DisplayFrame();
}





