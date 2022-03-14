#include "../Wanichusik/Kiwii/DatoBased/Simulation/Experiment #1/Exper_1.h"
#include "../Wanichusik/Kiwii/DatoBased/Screench/Screench.h"
#include <iostream>

int main() {
	srand(time(NULL));
	int x = 120;
	int y = 90;
	Exper_1 E;
	Kiwii::Screench uv;
	uv.setup(x, y);

	uint64_t t = 0;
	uint8_t C = true;
	uint8_t SPACE = true;
	uint8_t SHIFT = 0;

	//Kiwii_Experiments::mapf a = new float[x*y];
	//for (int i = 0;i < x;i++) { 
	//	for (int j = 0;j < y;j++) {
	//		a[i + j * x] = -sqrt(pow((i - (x / 2)), 2) + pow(j - (y / 2), 2)) * 0.05f;
	//	}
	//}
	//E.bias(a);
	//E.rain();
	//E.dig();
	//delete[] a;

	double M = 0.0;
	double B = 0.0;
	uint16_t SKIP = 0x10;
	uint8_t flag = 0;

	while (true) {
		if (flag) flag = !flag;

		if (GetAsyncKeyState(VK_ESCAPE)) { break; }
		if (GetAsyncKeyState(' ')) { SPACE = !SPACE; Sleep(100); }
		if (GetAsyncKeyState('C')) { C = !C; Sleep(100); }
		if (GetAsyncKeyState(VK_SHIFT)) { SHIFT++; SHIFT %= 8; Sleep(100); }
		if (GetAsyncKeyState(VK_UP)) { B += 0.001; Sleep(10); }
		if (GetAsyncKeyState(VK_DOWN)) { B -= 0.001; Sleep(10); }
		if (GetAsyncKeyState(VK_LEFT)) { if (SKIP != 1) SKIP--;  Sleep(10); }
		if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_CONTROL)) { flag = !flag; Sleep(100); }
		else if (GetAsyncKeyState(VK_RIGHT)) { SKIP++; Sleep(10); }

		if (!SPACE || flag) {
			E.rain();
			M = E.dig();
			t++;
		}

		if (t % SKIP == 0 || SPACE) {
			double avrg = 0.5;
			if (!C) {
				avrg = 0.0;
				for (int i = 0;i < x * y;i++) {
					avrg += E.map[i];
				}
				avrg /= double(x * y);
			}

			avrg += B;

			for (int i = 0;i < x * y;i++) {
				switch (SHIFT) {
				case 0: {
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
				}
				case 1: {
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
				}
				case 2: {
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
				}
				case 3: {
					if (E.map[i] < avrg * 2.0 / 2.0)
						uv.set_screen(i, ' ');
					else uv.set_screen(i, char(219));
					break;
				}
				case 4: {
					if (E.map[i] < M)
						uv.set_screen(i, '0');
					else if (E.map[i] == 1)
						uv.set_screen(i, '1');
					else if (abs(avrg - E.map[i]) < 0.05)
						uv.set_screen(i, char(219));
					else if (abs(avrg - E.map[i]) < 0.125)
						uv.set_screen(i, char(178));
					else if (abs(avrg - E.map[i]) < 0.25)
						uv.set_screen(i, char(177));
					else if (abs(avrg - E.map[i]) < 0.375)
						uv.set_screen(i, char(176));
					else uv.set_screen(i, ' ');
					break;
				}
				case 5: {
					int Xm = i % x;
					int Ym = i / x;
					int Xl = i % x;
					int Yl = i / x;
					int S = 1;
					double avr = 0;

					if (Xl - 1 >= 0) {
						Xl--;S++;
						if (Yl - 1 >= 0) {
							Yl--;S++;
							avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
							Yl++;
						}
						avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
						if (Yl + 1 < y) {
							Yl++;S++;
							avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
							Yl--;
						}
						Xl++;
					}
					//жжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжж
					if (Yl - 1 >= 0) {
						Yl--;S++;
						avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
						Yl++;
					}
					avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
					if (Yl + 1 < y) {
						Yl++;S++;
						avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
						Yl--;
					}
					//жжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжж
					if (Xl + 1 < x) {
						Xl++;S++;
						if (Yl - 1 >= 0) {
							Yl--;S++;
							avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
							Yl++;
						}
						avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
						if (Yl + 1 < y) {
							Yl++;S++;
							avr += E.map[Xl + Yl * x] - E.map[Xm + Ym * x];
							Yl--;
						}
						Xl--;
					}

					double Q = avr / double(S);

					if (Q < avrg * 2.0 / 5.0 / 5.0 / 5.0)
						uv.set_screen(i, char(219));
					else if (Q < avrg * 2.0 * 2.0 / 5.0 / 5.0 / 5.0)
						uv.set_screen(i, char(178));
					else if (Q < avrg * 2.0 * 3.0 / 5.0 / 5.0 / 5.0)
						uv.set_screen(i, char(177));
					else if (Q < avrg * 2.0 * 4.0 / 5.0 / 5.0 / 5.0)
						uv.set_screen(i, char(176));
					else uv.set_screen(i, ' ');
					break;
				}
				case 6: {
					if (E.slide[i] < avrg * 2.0 / 5.0)
						uv.set_screen(i, ' ');
					else if (E.slide[i] < avrg * 2.0 * 2.0 / 5.0)
						uv.set_screen(i, char(176));
					else if (E.slide[i] < avrg * 2.0 * 3.0 / 5.0)
						uv.set_screen(i, char(177));
					else if (E.slide[i] < avrg * 2.0 * 4.0 / 5.0)
						uv.set_screen(i, char(178));
					else uv.set_screen(i, char(219));
					break;
				}
				case 7: {
					if (E.map[i] < avrg * 2.0 * 1.25 / 5.0)
						uv.set_screen(i, ' ');
					else if (E.map[i] < avrg * 2.0 * 2.5 / 5.0)
						uv.set_screen(i, char(176));
					else if (E.map[i] < avrg * 2.0 * 3.0 / 5.0)
						uv.set_screen(i, char(219));
					else if (E.map[i] < avrg * 2.0 * 3.5 / 5.0)
						uv.set_screen(i, char(178));
					else if (E.map[i] < avrg * 2.0 * 4.0 / 5.0)
						uv.set_screen(i, char(177));
					else if (E.map[i] < avrg * 2.0 * 4.5 / 5.0)
						uv.set_screen(i, char(176));
					else uv.set_screen(i, ' ');
					break;
				}
				}
			}

			uv.insert_hex(x * y - 1, t);
			uv.insert_hex(x * y - 16 - 1 - 1, unsigned short(B * 1000));
			uv.insert_hex(x * y - 20 - 1 - 1 - 1, SHIFT);
			uv.insert_hex(x * y - 22 - 1 - 1 - 1 - 1, SKIP);
			uv.insert_hex(x * y - 26 - 1 - 1 - 1 - 1 - 1, unsigned int(avrg * 1024));
			uv.insert_hex(x * y - 34 - 1 - 1 - 1 - 1 - 1 - 1, C);
			uv.print();
		}

	}

	return 0;
}