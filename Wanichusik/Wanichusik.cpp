﻿#include "./Kiwii/DatoBased/Spritech/Spritech.h"
#include "./Kiwii/DatoBased/Mathem/Mathem.h"
#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include <iostream>
//#include <future>
//#include <functional>

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
	//Kiwii::Screench uv;
	//uv.setup(120, 90);
	Kiwii_Experiment::Experiment1 a;
	srand(0);
	a.generate_light();
	a.generate_mineral();
	a.generate_creature(5);
	//uint8_t Key_ESCAPE = false;
	//uint8_t Key_F1 = false;
	//uint8_t Key_P = false;
	//uint8_t Key_F4 = false;
	//uint8_t Key_F5 = true;
	//uint32_t seed = 1;


	//while (true) {
		//input
		 //{
			//	if (GetAsyncKeyState(VK_ESCAPE)) {
			//		Key_ESCAPE = !Key_ESCAPE;
			//		Sleep(50);
			//		break;
			//	}

			//	if (GetAsyncKeyState(VK_F1)) { Key_F1 = (Key_F1 + 1) % 3; Sleep(50); }
			//	if (GetAsyncKeyState('P')) { Key_P = !Key_P;Sleep(50); }
			//	if (GetAsyncKeyState(VK_F4)) { Key_F4 = !Key_F4;Sleep(500); }
			//	if (GetAsyncKeyState(VK_F5)) { Key_F5 = !Key_F5;Sleep(50); }
			//}

		//if (!Key_P) {
		for (int i = 0;i < 1033;i++) {
			a.logic();
			a.write_dots();

			//for (auto i = a.dots.begin();i != a.dots.end();i++) std::cout <<'\t' << i->energy << '\n';

			std::cout << i << " : " << std::chrono::duration_cast<std::chrono::microseconds>(a.gen2 - a.gen1).count() << ' '
				<< std::chrono::duration_cast<std::chrono::microseconds>(a.do2 - a.do1).count() << ' '
				<< std::chrono::duration_cast<std::chrono::microseconds>(a.check2 - a.check1).count() << '\n';
		}
		//}
		//output

			/*{
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

				if (Key_F1 == 0) uv.set_screen((uv.get_square() - 1), 'V');
				else if (Key_F1 == 1) uv.set_screen((uv.get_square() - 1), 'S');
				else uv.set_screen((uv.get_square() - 1), 'M');

				if (Key_P) uv.set_screen((uv.get_square() - 1) - 1, 'P');
				else uv.set_screen((uv.get_square() - 1) - 1, '-');

				uv.insert_hex((uv.get_square() - 1) - 2, seed);

				if (Key_F5) uv.set_screen((uv.get_square() - 1) - 11, 'S');
				else uv.set_screen((uv.get_square() - 1) - 11, 'H');

				uv.insert_hex((uv.get_square() - 1) - 12, a.hours);
				uv.insert_hex((uv.get_square() - 1) - 14, a.day);
				uv.insert_hex((uv.get_square() - 1) - 17, a.year);

				uv.print();

		}

		if (Key_F5) Sleep(30);
		}*/

		return 0;
	}

