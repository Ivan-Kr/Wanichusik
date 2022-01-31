#pragma once
#include "../_Template/_temp.h"
#include <vector>
#include <iostream>

//є мапа, в якому живуть організми
//сама карта порожня, тільки організми
//але світло буде нерозподілена рівномірно (із-за гірських тіней)(плавно)
//так само і органічні речовини (ерозія)

//є 4 клана живих організмів, "рослини", "травоїдні", "м'ясоїдні" й "бактерії"
//вони виділяють 1,2,3 і 0 органічних речовин відповідно після смерті
//в кожному організмі є 64 ячеєк пам'яті
//"поглинути джерело енергії"(0-3), "дублюватися"(8), "рухатися"(4-7) і "бездіювати"(9)
// але ще є й посилання на ячейки, які переправвляють читатор на конкретну ячейку - 10 (10-73)
// читатор буде переступати на стільки ячеєк, за які, знаходяться кожна клітина, і за його типом
// вверх +1, вправо +2,...
// якщо це буде клітина "рослина", то +1, "травоїдне", +2,...
// на порожнечу буде реакція 1
//під час дублювання, виникає помилка в геномі з шансом 1/5 і змінює його випадковим образом
//(спеціально для м'ясоїдних) вони будуть бачити геном, і якщо у них не співпадає геном з чужим геномом на 3 ячейки і якщо воно буде травоїдною, то воно буде поїдати
//(спеціально для травоідних) вони будуть визначати чи це рослина, якщо це так, то воно її поїдає
//у кожного буде ще й рахунок енергії, якщо вона буде < 1, то воно буде анігільована
//організми можуть поглинати що небудь й получати за це енергію, і вони будуть тратити їх за всякі команди, за виключенням бездіяльності

namespace Kiwii_Experiment {

	class Experiment1 {
	
		enum creatures {
			Plants,
			Herbivors,
			Carnivorous,
			Bacteries,
		};

		struct LiveDot {
			Kiwii::Point_Exp point;
			creatures type;
		};
		uint8_t xm = 120;
		uint8_t ym = 90;
		std::vector<Kiwii::Point_Exp> Dots;
	public:
		Kiwii::Map_Exp<uint8_t> Map = Kiwii::Map_Exp<uint8_t>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(xm, ym);

		void GenerateLight() {
			
			Kiwii::Map_Exp<uint8_t> MapSunAlpha = Kiwii::Map_Exp<uint8_t>(xm, ym);
			int min = 128;
			double z = 1;
			double zz = 1;
			const uint8_t a = 7;
			int mas_k[a] = {30,15,10,5,3,2,1 };
			
			for (int s = 0;s < a;s++) {
				
				for (int i = 0;i < MapSunAlpha.x;i += mas_k[s]) {
					for (int j = 0;j < MapSunAlpha.y;j += mas_k[s]) {
						int8_t NUM = rand();
						NUM = (NUM - min);
						for (int ii = i;ii < i + mas_k[s];ii++)
							for (int ji = j;ji < j + mas_k[s];ji++)
								if(s==0)
									MapSunAlpha.map[ii][ji] = NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));
								else MapSunAlpha.map[ii][ji] += NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));

					}
				}

				for (int i = 0;i < MapSun.x;i += 1) {
					for (int j = 0;j < MapSun.y;j += 1) {
						MapSun.map[i][j] =
							(
								MapSunAlpha.map[Kiwii::fix<int>(i - 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i + 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j, 0, MapSunAlpha.y)] 
								+
								MapSunAlpha.map[Kiwii::fix<int>(i - 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i + 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i - 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i + 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapSunAlpha.y)] 
								+
								MapSunAlpha.map[Kiwii::fix<int>(i + 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i + 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i + 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapSunAlpha.y)]
								+
								MapSunAlpha.map[Kiwii::fix<int>(i + 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i - 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapSunAlpha.y)]
								+
								MapSunAlpha.map[Kiwii::fix<int>(i - 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i - 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i - 2, 0, MapSunAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapSunAlpha.y)]
								+
								MapSunAlpha.map[Kiwii::fix<int>(i + 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapSunAlpha.y)] +
								MapSunAlpha.map[Kiwii::fix<int>(i - 1, 0, MapSunAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapSunAlpha.y)]
								)
								/20;
					}

				}
					for (int i = 0;i < MapSun.y;i++) {
						for (int j = 0;j < MapSun.x;j++) {

							if (MapSun.map[j][i] < 51.2)
								std::cout << ' ';
							else if (MapSun.map[j][i] < 51.2 * 2)
								std::cout << char(176);
							else if (MapSun.map[j][i] < 51.2 * 3)
								std::cout << char(177);
							else if (MapSun.map[j][i] < 51.2 * 4)
								std::cout << char(178);
							else std::cout << char(219);


							//if (s < 32)
								//std::wcout << '0';
							//if (s < 64)
								//std::wcout << '1';
							//else if (s < 96)
								//std::wcout << '2';
							//else if (s < 128)
								//std::wcout << '3';
							//else if (s < 160)
								//std::wcout << '4';
							//else if (s < 192)
								//std::wcout << '5';
							//else if (s < 224)
								//std::wcout << '6';
							//else std::wcout << '7';

						}
						std::cout << '\n';

					}
					std::cout << '\n';
			}
		}

		void ToMakeMountain(double z) {
			for (int i = 0;i < MapSun.x;i += 1)
				for (int j = 0;j < MapSun.y;j += 1)
					MapSun.map[i][j] = pow(double(MapSun.map[i][j]) / 256.0,z)*256;
		}

	};

}