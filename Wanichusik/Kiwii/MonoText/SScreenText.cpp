#include "SScreenText.h"

void kiwii::SScreenText::SetupS(WORD Width, WORD Height)
{
	_width = Width;
	_height = Height;

	SetWindow(_width, _height);

	_hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(_hconsole);

	_aspect = _width / _height;

	_screen.resize(_width * _height);
}

wchar_t kiwii::SScreenText::ScreenL(int index) {
	if (!(index < 0 || index >= Square()))
		return _screen[index];
	else
		return L'\0';
}

void kiwii::SScreenText::ScreenL(int index, wchar_t val) {
	if (!(index < 0 || index >= Square()))
		_screen[index] = val;
}

wchar_t kiwii::SScreenText::ScreenP(int x, int y) {
	if (!(x + y * _width < 0 || x + y * _width >= Square()))
		return _screen[x + y * _width];
	else
		return L'\0';
}

void kiwii::SScreenText::ScreenP(int x, int y, wchar_t val) {
	if (!(x + y * _width < 0 || x + y * _width >= Square()))
		_screen[x + y * _width] = val;
}

void kiwii::SScreenText::Fill(wchar_t val)
{
	for (int i = 0;i < kiwii::SScreenText::Square();i++) {
		_screen[i] = val;
	}
}
