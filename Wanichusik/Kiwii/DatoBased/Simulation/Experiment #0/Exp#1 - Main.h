#pragma once
#include "../_Template/_temp.h"
#include <vector>

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

	class Experiment {
	
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

		std::vector<Kiwii::Point_Exp> Dots;
	public:
		Kiwii::Map_Exp<uint8_t> Map = Kiwii::Map_Exp<uint8_t>(120,90);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(120, 90);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(120, 90);

		void GenerateLight() {
			int k = 30;
			int sk = k;
			int min = 128;
			double z = 2;
			double zz = 1;
			for (int i = 0;i < MapSun.x;i+=k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();

					for (int ii = i;ii < i+k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] = NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 15;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM- min) ;
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k,z) / pow( sk,zz));

				}
			}
			k = 10;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 5;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 2;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + k;ii++)
						for (int ji = j;ji < j + k;ji++)
							MapSun.map[ii][ji] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
			k = 1;
			for (int i = 0;i < MapSun.x;i += k) {
				for (int j = 0;j < MapSun.y;j += k) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					MapSun.map[i][j] += NUM * double(pow(k, z) / pow(sk, zz));

				}
			}
		}

	};

}