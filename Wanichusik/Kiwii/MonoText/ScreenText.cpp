#include "ScreenText.h"

void Kiwii::monotext::ScreenText::SetupS(WORD Width, WORD Height)
{
	_width = Width;
	_height = Height;

	SetWindow(_width, _height);

	_hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(_hconsole);

	_aspect = _width / _height;

	_screen = new wchar_t[Square() + 1];
	_screen[Square()] = L'\0';
}

wchar_t Kiwii::monotext::ScreenText::ScreenL(int index) {
	if (!(index < 0 || index >= Square()))
		return _screen[index];
	else
		return L'\0';
}

void Kiwii::monotext::ScreenText::ScreenL(int index, wchar_t val) {
	if (!(index < 0 || index >= Square()))
		_screen[index] = val;
}

wchar_t Kiwii::monotext::ScreenText::ScreenP(int x, int y) {
	if (!(x+y*_width < 0 || x + y * _width >= Square()))
		return _screen[x + y * _width];
	else
		return L'\0';
}

void Kiwii::monotext::ScreenText::ScreenP(int x, int y, wchar_t val) {
	if (!(x + y * _width < 0 || x + y * _width >= Square()))
		_screen[x + y * _width] = val;
}

void Kiwii::monotext::ScreenText::Fill(wchar_t val)
{
	for (int i = 0;i < Square();i++) {
		_screen[i] = val;
	}
}
