#include "./Kiwii/DatoBased/Spritech/Spritech.h"
#include "./Kiwii/DatoBased/Mathem/Mathem.h"
#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp#1 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include <iostream>

//⠀⠁⠂⠃⠄⠅⠆⠇⠈⠉⠊⠋⠌⠍⠎
//⠏⠐⠑⠒⠓⠔⠕⠖⠗⠘⠙⠚⠛⠜⠝
//⠞⠟⠠⠡⠢⠣⠤⠥⠦⠧⠨⠩⠪⠫⠬
//⠭⠮⠯⠰⠱⠲⠳⠴⠵⠶⠷⠸⠹⠺⠻
//⠼⠽⠾⠿⡀⡁⡂⡃⡄⡅⡆⡇⡈⡉⡊
//⡋⡌⡍⡎⡏⡐⡑⡒⡓⡔⡕⡖⡗⡘⡙
//⡚⡛⡜⡝⡞⡟⡠⡡⡢⡣⡤⡥⡦⡧⡨
//⡩⡪⡫⡬⡭⡮⡯⡰⡱⡲⡳⡴⡵⡶⡷
//⡸⡹⡺⡻⡼⡽⡾⡿⢀⢁⢂⢃⢄⢅⢆
//⢇⢈⢉⢊⢋⢌⢍⢎⢏⢐⢑⢒⢓⢔⢕
//⢖⢗⢘⢙⢚⢛⢜⢝⢞⢟⢠⢡⢢⢣⢤
//⢥⢦⢧⢨⢩⢪⢫⢬⢭⢮⢯⢰⢱⢲⢳
//⢴⢵⢶⢷⢸⢹⢺⢻⢼⢽⢾⢿⣀⣁⣂
//⣃⣄⣅⣆⣇⣈⣉⣊⣋⣌⣍⣎⣏⣐⣑
//⣒⣓⣔⣕⣖⣗⣘⣙⣚⣛⣜⣝⣞⣟⣠
//⣡⣢⣣⣤⣥⣦⣧⣨⣩⣪⣫⣬⣭⣮⣯
//⣰⣱⣲⣳⣴⣵⣶⣷⣸⣹⣺⣻⣼⣽⣾⣿

//utf-16
//14 04 30 04 32 04 3D 04 38 04 3C 04 20 00 34 04 30 04 32 04 3D 04 3E 04 2C 00 20 00 31 04 43 04 32 04 20 00 41 04 42 04 30 04 40 04 35 04 46 04 4C 04 2D 00 3E 04 45 04 3E 04 40 04 3E 04 3D 04 35 04 46 04 4C 04 2C 00 20 00 32 04 56 04 3D 04 20 00 41 04 42 04 35 04 40 04 56 04 33 04 20 00 56 04 20 00 37 04 31 04 35 04 40 04 56 04 33 04 30 04 32 04 20 00 37 04 35 04 3C 04 3B 04 56 04 20 00 1A 04 56 04 31 04 35 04 40 04 3D 04 35 04 42 04 38 04 3A 04 38 04 2C 00 20 00 3E 04 42 04 36 04 35 04 2C 00 20 00 32 04 56 04 3D 04 20 00 31 04 43 04 32 04 20 00 3D 04 30 04 48 04 38 04 3C 04 20 00 41 04 3F 04 30 04 41 04 38 04 42 04 35 04 3B 04 35 04 3C 04 2E 00 20 00 1E 04 34 04 3D 04 3E 04 33 04 3E 04 20 00 34 04 3D 04 4F 04 2C 00 20 00 37 04 27 00 4F 04 32 04 38 04 3B 04 30 04 41 04 4F 04 20 00 12 04 1E 04 1D 04 10 04 2C 00 20 00 1A 04 3E 04 40 04 3E 04 3B 04 35 04 32 04 30 04 2E 00 20 00 12 04 3E 04 3D 04 30 04 20 00 3F 04 3E 04 47 04 38 04 3D 04 30 04 3B 04 30 04 20 00 42 04 32 04 35 04 40 04 34 04 38 04 42 04 38 04 20 00 41 04 32 04 3E 04 57 04 20 00 42 04 3E 04 47 04 3A 04 38 04 20 00 37 04 3E 04 40 04 43 04 2C 00 20 00 49 04 3E 04 20 00 42 04 40 04 35 04 31 04 30 04 20 00 3D 04 35 04 3C 04 3E 04 32 04 20 00 22 00 40 04 35 04 41 04 43 04 40 04 41 04 38 04 20 00 34 04 3B 04 4F 04 20 00 34 04 3E 04 3B 04 30 04 3D 04 3D 04 4F 04 20 00 3C 04 43 04 3A 04 20 00 42 04 32 04 3E 04 40 04 46 04 4F 04 22 00 2C 00 20 00 30 04 3B 04 35 04 20 00 3C 04 38 04 20 00 3D 04 35 04 20 00 37 04 3D 04 30 04 3B 04 38 04 20 00 3F 04 40 04 3E 04 20 00 3D 04 4C 04 3E 04 33 04 3E 04 2C 00 20 00 56 04 20 00 42 04 32 04 35 04 40 04 34 04 38 04 3B 04 38 04 20 00 41 04 32 04 3E 04 54 04 2E 00 20 00 1E 04 42 04 36 04 35 04 20 00 3D 04 35 04 20 00 3A 04 3E 04 40 04 38 04 3B 04 38 04 41 04 4F 04 20 00 3C 04 38 04 20 00 57 04 39 04 20 00 3F 04 56 04 34 04 30 04 3D 04 3D 04 4F 04 2C 00 20 00 56 04 20 00 32 04 3E 04 3D 04 30 04 20 00 3F 04 3E 04 47 04 30 04 3B 04 30 04 20 00 32 04 32 04 3E 04 34 04 38 04 42 04 38 04 20 00 41 04 32 04 3E 04 57 04 20 00 32 04 56 04 39 04 41 04 4C 04 3A 04 30 04 20 00 56 04 20 00 32 04 38 04 42 04 56 04 41 04 3D 04 4E 04 32 04 30 04 42 04 38 04 20 00 3D 04 30 04 41 04 2E 00 20 00 1D 04 30 04 32 04 56 04 42 04 4C 04 20 00 3D 04 30 04 48 04 3E 04 33 04 3E 04 20 00 41 04 3F 04 30 04 41 04 38 04 42 04 35 04 3B 04 4F 04 20 00 3F 04 3E 04 33 04 43 04 31 04 38 04 3B 04 30 04 2C 00 20 00 30 04 3B 04 35 04 20 00 3C 04 38 04 2C 00 20 00 41 04 38 04 3F 04 30 04 40 04 30 04 42 04 38 04 41 04 42 04 38 04 2C 00 20 00 41 04 42 04 30 04 40 04 30 04 54 04 3C 04 41 04 4F 04 20 00 3F 04 56 04 34 04 42 04 40 04 38 04 3C 04 43 04 32 04 30 04 42 04 38 04 20 00 3F 04 30 04 41 04 42 04 3A 04 38 04 20 00 39 04 20 00 3F 04 38 04 41 04 30 04 42 04 38 04 20 00 40 04 56 04 34 04 3D 04 3E 04 4E 04 20 00 3C 04 3E 04 32 04 3E 04 4E 04 2C 00 20 00 30 04 20 00 32 04 3E 04 3D 04 30 04 20 00 31 04 43 04 3B 04 30 04 20 00 3D 04 35 04 20 00 32 04 41 04 56 04 3C 04 20 00 37 04 40 04 3E 04 37 04 43 04 3C 04 56 04 3B 04 30 04 2C 00 20 00 42 04 30 04 20 00 39 04 20 00 3A 04 3E 04 40 04 3E 04 3B 04 35 04 32 04 30 04 20 00 37 04 30 04 4F 04 32 04 3B 04 4F 04 3B 04 30 04 2C 00 20 00 49 04 3E 04 20 00 3D 04 30 04 48 04 30 04 20 00 3C 04 3E 04 32 04 30 04 20 00 3D 04 35 04 37 04 40 04 3E 04 37 04 43 04 3C 04 56 04 3B 04 30 04 2C 00 20 00 42 04 3E 04 3C 04 43 04 20 00 3C 04 38 04 20 00 3A 04 3E 04 40 04 38 04 41 04 42 04 43 04 54 04 3C 04 3E 04 41 04 4F 04 20 00 3D 04 35 04 4E 04 2E 00 20 00 10 04 3B 04 35 04 20 00 39 04 20 00 46 04 56 04 54 04 57 04 20 00 48 04 3A 04 3E 04 34 04 38 04 20 00 3D 04 30 04 3C 04 20 00 31 04 43 04 3B 04 3E 04 20 00 3C 04 30 04 3B 04 3E 04 2C 00 20 00 32 04 3E 04 3D 04 30 04 20 00 3F 04 3E 04 47 04 30 04 3B 04 30 04 20 00 3F 04 40 04 3E 04 3F 04 3E 04 3D 04 43 04 32 04 30 04 42 04 38 04 20 00 41 04 3B 04 43 04 36 04 38 04 42 04 38 04 20 00 57 04 57 04 20 00 30 04 40 04 3C 04 56 04 57 04 20 00 37 04 30 04 20 00 34 04 3E 04 32 04 3E 04 3B 04 56 04 20 00 32 04 38 04 33 04 56 04 34 04 3D 04 56 04 20 00 43 04 3C 04 3E 04 32 04 38 04 2C 00 20 00 3E 04 42 04 36 04 35 04 20 00 42 04 3E 04 3B 04 3A 04 20 00 46 04 4C 04 3E 04 3C 04 43 04 20 00 31 04 35 04 37 04 34 04 43 04 3C 04 3D 04 3E 04 3C 04 43 04 20 00 3D 04 30 04 40 04 3E 04 34 04 43 04 2E 00 20 00 1D 04 35 04 3D 04 4C 04 3A 04 30 04 20 00 11 04 30 04 42 04 4C 04 3A 04 56 04 32 04 49 04 38 04 3D 04 30 04 20 00 3D 04 30 04 48 04 30 04 20 00 33 04 38 04 3D 04 35 04 2C 00 20 00 30 04 20 00 32 04 3E 04 3D 04 38 04 20 00 46 04 43 04 40 04 30 04 4E 04 42 04 4C 04 20 00 3D 04 30 04 48 04 56 04 20 00 37 04 32 04 38 04 47 04 30 04 57 04 20 00 39 04 20 00 3D 04 30 04 48 04 35 04 20 00 3F 04 38 04 41 04 4C 04 3C 04 3E 04 2C 00 20 00 42 04 35 04 3F 04 35 04 40 04 2C 00 20 00 3C 04 3E 04 36 04 3B 04 38 04 32 04 3E 04 2C 00 20 00 3C 04 38 04 20 00 34 04 30 04 3B 04 56 04 20 00 3D 04 35 04 20 00 3C 04 3E 04 36 04 35 04 3C 04 3E 04 20 00 3F 04 56 04 34 04 42 04 40 04 38 04 3C 04 43 04 32 04 30 04 42 04 38 04 20 00 42 04 30 04 3A 04 38 04 39 04 20 00 3F 04 40 04 30 04 32 04 3E 04 3F 04 38 04 41 04 2E 00 20 00 06 04 20 00 4F 04 3A 04 49 04 3E 04 20 00 3D 04 30 04 32 04 56 04 42 04 4C 04 20 00 45 04 42 04 3E 04 41 04 4C 04 20 00 40 04 3E 04 37 04 48 04 38 04 44 04 40 04 43 04 54 04 20 00 46 04 35 04 2C 00 20 00 42 04 3E 04 20 00 3C 04 3E 04 36 04 3B 04 38 04 32 04 3E 04 20 00 3C 04 38 04 20 00 42 04 40 04 38 04 3C 04 30 04 3B 04 38 04 46 04 4F 04 20 00 34 04 3E 04 20 00 3A 04 56 04 3D 04 46 04 4F 04 20 00 56 04 20 00 37 04 40 04 56 04 32 04 3D 04 38 04 3B 04 38 04 41 04 4F 04 20 00 37 04 20 00 37 04 35 04 3C 04 3B 04 35 04 4E 04 20 00 3C 04 38 04 2E 00

int main() {
	std::cout << Kiwii::efclide(15, 9);
	std::cin.get();
	Kiwii_Experiment::Experiment1 a;
	Kiwii::Screench uv;

	uv.setup(120, 90);

	srand(0);

	a.GenerateLight();
	a.GenerateMineral();
	a.GenerateCreature(360);

	uint8_t Key_ESCAPE = false;
	uint8_t Key_F1 = false;
	uint8_t Key_F2 = false;
	uint8_t Key_P = false;
	uint8_t Key_LPARENTHESIS = false;
	uint8_t Key_RPARENTHESIS = false;
	uint8_t Key_F4 = false;
	uint8_t Key_F5 = true;

	uint32_t seed = 0;
	uint32_t next_seed = 0;

	uint64_t t = 0;

	while (true) {
		//input
		{
			if (GetAsyncKeyState(VK_ESCAPE)) {
				Key_ESCAPE = !Key_ESCAPE;
				break;
			}

			if (GetAsyncKeyState(VK_F1)) Key_F1 = (Key_F1 + 1) % 3;
			if (GetAsyncKeyState(VK_F2)) Key_F2 = !Key_F2;
			if (GetAsyncKeyState('P')) Key_P = !Key_P;
			if (GetAsyncKeyState('9')) Key_LPARENTHESIS = !Key_LPARENTHESIS;
			if (GetAsyncKeyState('0')) Key_RPARENTHESIS = !Key_RPARENTHESIS;
			if (GetAsyncKeyState(VK_F4)) Key_F4 = !Key_F4;
			if (GetAsyncKeyState(VK_F5)) Key_F5 = !Key_F5;
		}

		if (!Key_P) {
			a.Logic(Key_F2);
			a.WriteDots();
		}

		//output
		{
			if (Key_F5) {
				for (int i = 0;i < a.Map.y;i++) {
					for (int j = 0;j < a.Map.x;j++) {
						if (a.Map.map[j][i] == '.') {
							if (Key_F1 == 1) {
								if (a.MapSun.map[j][i] < 51.2)
									uv.set_screen(j, i, ' ');
								else if (a.MapSun.map[j][i] < 51.2 * 2)
									uv.set_screen(j, i, char(176));
								else if (a.MapSun.map[j][i] < 51.2 * 3)
									uv.set_screen(j, i, char(177));
								else if (a.MapSun.map[j][i] < 51.2 * 4)
									uv.set_screen(j, i, char(178));
								else uv.set_screen(j, i, char(219));
							}
							else if (Key_F1 == 2) {
								if (a.MapMineral.map[j][i] < 51.2)
									uv.set_screen(j, i, ' ');
								else if (a.MapMineral.map[j][i] < 51.2 * 2)
									uv.set_screen(j, i, char(176));
								else if (a.MapMineral.map[j][i] < 51.2 * 3)
									uv.set_screen(j, i, char(177));
								else if (a.MapMineral.map[j][i] < 51.2 * 4)
									uv.set_screen(j, i, char(178));
								else uv.set_screen(j, i, char(219));
							}
							else uv.set_screen(j, i, a.Map.map[j][i]);
						}
						else uv.set_screen(j, i, a.Map.map[j][i]);

					}
				}
			}

			if (Key_ESCAPE) uv.set_screen((uv.get_square() - 1), 'e');
			else uv.set_screen((uv.get_square() - 1), ' ');

			if (Key_F1 == 0) uv.set_screen((uv.get_square() - 1) - 1, 'V');
			else if (Key_F1 == 1) uv.set_screen((uv.get_square() - 1) - 1, 'S');
			else uv.set_screen((uv.get_square() - 1) - 1, 'M');

			if (Key_F2) uv.set_screen((uv.get_square() - 1) - 2, 'u');
			else uv.set_screen((uv.get_square() - 1) - 2, 'd');

			if (Key_P) uv.set_screen((uv.get_square() - 1) - 3, 'P');
			else uv.set_screen((uv.get_square() - 1) - 3, '-');

			uv.set_screen((uv.get_square() - 1) - 4, Kiwii::get_hex(seed, 0));
			uv.set_screen((uv.get_square() - 1) - 5, Kiwii::get_hex(seed, 1));
			uv.set_screen((uv.get_square() - 1) - 6, Kiwii::get_hex((seed / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 7, Kiwii::get_hex((seed / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 8, Kiwii::get_hex((seed / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 9, Kiwii::get_hex((seed / 256 / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 10, Kiwii::get_hex((seed / 256 / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 11, Kiwii::get_hex((seed / 256 / 256 / 256), 1));

			uv.set_screen((uv.get_square() - 1) -12, Kiwii::get_hex(next_seed, 0));
			uv.set_screen((uv.get_square() - 1) - 13, Kiwii::get_hex(next_seed, 1));
			uv.set_screen((uv.get_square() - 1) - 14, Kiwii::get_hex((next_seed / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 15, Kiwii::get_hex((next_seed / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 16, Kiwii::get_hex((next_seed / 256 /256) , 0));
			uv.set_screen((uv.get_square() - 1) - 17, Kiwii::get_hex((next_seed / 256 / 256) , 1));
			uv.set_screen((uv.get_square() - 1) - 18, Kiwii::get_hex((next_seed / 256 / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 19, Kiwii::get_hex((next_seed / 256 / 256 / 256), 1));



			if (Key_F5) uv.set_screen((uv.get_square() - 1) - 20, 'S');
			else uv.set_screen((uv.get_square() - 1) - 20, 'H');

			uv.set_screen((uv.get_square() - 1) - 21, Kiwii::get_hex(t, 0));
			uv.set_screen((uv.get_square() - 1) - 22, Kiwii::get_hex(t, 1));
			uv.set_screen((uv.get_square() - 1) - 23, Kiwii::get_hex((t / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 24, Kiwii::get_hex((t / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 25, Kiwii::get_hex((t / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 26, Kiwii::get_hex((t / 256 / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 27, Kiwii::get_hex((t / 256 / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 28, Kiwii::get_hex((t / 256 / 256 / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 29, Kiwii::get_hex((t / 256 / 256 / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 30, Kiwii::get_hex((t / 256 / 256 / 256 / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 31, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 32, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 33, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 34, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256 / 256), 1));
			uv.set_screen((uv.get_square() - 1) - 35, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256 / 256 / 256), 0));
			uv.set_screen((uv.get_square() - 1) - 36, Kiwii::get_hex(((t / 256 / 256 / 256 / 256) / 256 / 256 / 256), 1));

			if (Key_LPARENTHESIS) { 
				next_seed--;
				Key_LPARENTHESIS= !Key_LPARENTHESIS;
			}

			if (Key_RPARENTHESIS) {
				next_seed++;
				Key_RPARENTHESIS = !Key_RPARENTHESIS;
			}	

			if (Key_F4) {
				srand(next_seed);
				seed = next_seed;
				a.GenerateLight();
				a.GenerateMineral();
				a.GenerateCreature(360);
				Key_F4 = !Key_F4;
			}
			
			uv.print();
		}
		if (Key_F5) {
			Sleep(100);
		}
		t++;
	}
	return 0;
}
