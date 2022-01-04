#include "Screench.h"

void Kiwii::Screench::set_screen(WORD width, WORD height,bool need_adapt=false) {
	try {
		_width = width;
		_height = height;

		_aspect = _width / height;

		if (_aspect > 3 || _aspect < (double)1 / 3) throw true;

		_hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(_hconsole);

		SO_set_window(_width, _height);

		_screen = new char[_width * _height + 1];
		_screen[_width * _height] = 0;
		throw false;
	}
	catch (bool a) {
		if(a) std::abort();
	}
}
