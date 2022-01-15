#include "Screench.h"

void Kiwii::Screench::setup(uint16_t width, uint16_t height, bool need_adapt)
{
	try {
		_width = width;
		_height = height;

		_aspect = (double)_width / height;

		if (_aspect > 3 || _aspect < (double)1 / 3) throw true;
		if (_width == 0 || _height == 0) throw true;

		_hconsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(_hconsole);

		if (need_adapt)SO_set_window(_width, _height);

		_screen = new SYM[_width * _height + 1];
		_screen[_width * _height] = 0;
		is_decleared = true;
		throw false;
	}
	catch (bool a) {
		if (a) std::abort();
	}
}

void Kiwii::Screench::_info_r(std::string _name_r) {
	std::ofstream file("./Kiwii/DatoBased/Info/" + _name_r + ".txt", std::ios::out);
	file << "Info in \"" << _name_r << ".txt\"\n";
	//////////////////////////

	file << "\t" << "_pointer" << " : " << &_pointer << "\n";
	file << "\t" << "_name" << " : " << _name << "\n";
	
	file << "\t_screen = \n";
	if (is_decleared) {
		for (uint16_t i = 0;i < _height;i++) {
			for (uint16_t j = 0;j < _width;j++)
				file << _screen[_width * i + j];
			file << '\n';
		}
	}
	else file << false<<'\n';
	

	//////////////////////////
	file.close();
}
