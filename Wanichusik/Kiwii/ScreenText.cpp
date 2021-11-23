#include "ScreenText.h"

void kiwii::ScreenText::Setup() {
	HCONSOLE = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(HCONSOLE);
}

void kiwii::ScreenText::SetupS(WORD Width, WORD Height)
{
	WIDTH = Width;
	HEIGHT = Height;

	SetWindow(WIDTH, HEIGHT);

	HCONSOLE = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(HCONSOLE);

	ASPECT = WIDTH / HEIGHT;

	SCREEN = new wchar_t[SQUARE() + 1];
	SCREEN[SQUARE()] = L'\0';
}

wchar_t kiwii::ScreenText::Screen(int index) {
	if (!(index < 0 || index >= SQUARE()))
		return SCREEN[index];
	else
		return L'\0';
}

void kiwii::ScreenText::Screen(int index, wchar_t val) {
	if (!(index < 0 || index >= SQUARE()))
		SCREEN[index] = val;
}

void SetWindow(int Width, int Height) {
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}