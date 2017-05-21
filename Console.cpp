#include "Console.h"


HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{

	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(hOutput, c);
}

void SetColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(hOutput, (WORD)((background << 4) | text));
}

void ClearScr(int a, int b) {

	int x = a;
	int y = b;
	SetColor(Black, Black);
	gotoxy(x, y);
	cout << ' ';
	SetColor(LightGray, Black);
}