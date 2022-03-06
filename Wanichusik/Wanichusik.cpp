#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>

int main() {
	srand(time(NULL));
	int x = 240;
	int y = 130;
	Kiwii_Experiments::Exper_1 E;
	Kiwii::Screench uv;
	uv.setup(x, y);

	uint64_t t = 0;
	uint8_t C = true;
	uint8_t SPACE = true;
	uint8_t SHIFT = 0;

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {	break;	}
		if (GetAsyncKeyState(' ')) { SPACE = !SPACE; Sleep(100); }
		if (GetAsyncKeyState('C')) { C = !C; Sleep(100); }
		if (GetAsyncKeyState(VK_SHIFT)) { SHIFT++; SHIFT %= 4; Sleep(100); }

		if (!SPACE) {
			E.rain();
		}
		
		if (t % 0x10 == 0) {
			double avrg = 0.5;
			if (!C) {
				avrg = 0.0;
				for (int i = 0;i < x*y;i++) {
					avrg += E.map[i];
				}
				avrg /= double(x * y);
			}

			for (int i = 0;i < x*y;i++) {
				switch (SHIFT) {
				case 0:
					if (E.map[i] < avrg * 2.0 / 5.0)
						uv.set_screen(i, ' ');
					else if (E.map[i] < avrg * 2.0 * 2.0 / 5.0)
						uv.set_screen(i, char(176));
					else if (E.map[i] < avrg * 2.0 * 3.0 / 5.0)
						uv.set_screen(i, char(177));
					else if (E.map[i] < avrg * 2.0 * 4.0 / 5.0)
						uv.set_screen(i, char(178));
					else uv.set_screen(i, char(219));
					break;
				case 1:
					if (E.map[i] < avrg * 2.0 / 5.0)
						uv.set_screen(i, char(219));
					else if (E.map[i] < avrg * 2.0 * 2.0 / 5.0)
						uv.set_screen(i, char(178));
					else if (E.map[i] < avrg * 2.0 * 3.0 / 5.0)
						uv.set_screen(i, char(177));
					else if (E.map[i] < avrg * 2.0 * 4.0 / 5.0)
						uv.set_screen(i, char(176));
					else uv.set_screen(i, ' ');
					break;
				case 2:
					if (E.map[i] < avrg * 2.0 / 16.0)
						uv.set_screen(i, ' ');
					else if (E.map[i] < avrg * 2.0 * 2.0 / 16.0)
						uv.set_screen(i, '.');
					else if (E.map[i] < avrg * 2.0 * 3.0 / 16.0)
						uv.set_screen(i, '-');
					else if (E.map[i] < avrg * 2.0 * 4.0 / 16.0)
						uv.set_screen(i, ':');
					else if (E.map[i] < avrg * 2.0 * 5.0 / 16.0)
						uv.set_screen(i, '"');
					else if (E.map[i] < avrg * 2.0 * 6.0 / 16.0)
						uv.set_screen(i, 'o');
					else if (E.map[i] < avrg * 2.0 * 7.0 / 16.0)
						uv.set_screen(i, 'x');
					else if (E.map[i] < avrg * 2.0 * 8.0 / 16.0)
						uv.set_screen(i, '%');
					else if (E.map[i] < avrg * 2.0 * 9.0 / 16.0)
						uv.set_screen(i, '&');
					else if (E.map[i] < avrg * 2.0 * 10.0 / 16.0)
						uv.set_screen(i, 'A');
					else if (E.map[i] < avrg * 2.0 * 11.0 / 16.0)
						uv.set_screen(i, 'O');
					else if (E.map[i] < avrg * 2.0 * 12.0 / 16.0)
						uv.set_screen(i, 'B');
					else if (E.map[i] < avrg * 2.0 * 13.0 / 16.0)
						uv.set_screen(i, 'Q');
					else if (E.map[i] < avrg * 2.0 * 14.0 / 16.0)
						uv.set_screen(i, 'H');
					else if (E.map[i] < avrg * 2.0 * 15.0 / 16.0)
						uv.set_screen(i, '#');
					else uv.set_screen(i, '@');
					break;
				case 3:
					if (E.map[i] < avrg * 2.0 / 2.0)
						uv.set_screen(i, ' ');
					else uv.set_screen(i, char(219));
					break;
				}
			}

			uv.insert_hex(x * y - 1, t);
			uv.print();
		}
		if (!SPACE) {
			t++;
		}

	}

	return 0;
}
