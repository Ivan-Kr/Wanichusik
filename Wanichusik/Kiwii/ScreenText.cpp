#include "ScreenText.h"

void kiwii::ScreenText::SetupS(WORD Width, WORD Height)
{
	_width = Width;
	_height = Height;

	SetWindow(_width, _height);

	_hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(_hconsole);

	_aspect = _width / _height;

	_screen = new wchar_t[SQUARE() + 1];
	_screen[SQUARE()] = L'\0';
}

wchar_t kiwii::ScreenText::ScreenL(int index) {
	if (!(index < 0 || index >= SQUARE()))
		return _screen[index];
	else
		return L'\0';
}

void kiwii::ScreenText::ScreenL(int index, wchar_t val) {
	if (!(index < 0 || index >= SQUARE()))
		_screen[index] = val;
}

wchar_t kiwii::ScreenText::ScreenP(int x, int y) {
	if (!(x+y*_width < 0 || x + y * _width >= SQUARE()))
		return _screen[x + y * _width];
	else
		return L'\0';
}

void kiwii::ScreenText::ScreenP(int x, int y, wchar_t val) {
	if (!(x + y * _width < 0 || x + y * _width >= SQUARE()))
		_screen[x + y * _width] = val;
}

void kiwii::ScreenText::Fill(wchar_t val)
{
	for (int i = 0;i < kiwii::ScreenText::SQUARE();i++) {
		_screen[i] = val;
	}
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