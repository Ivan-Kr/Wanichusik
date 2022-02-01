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
	public:
		static const uint16_t nGenes= 64;

		enum creatures {
			Plants = '1',
			Herbivors = '2',
			Carnivorous = '3',
			Bacteries = '4',
		};

		enum command : uint8_t{
			Nothing = 0,
			EatN = 1,
			EatE = 2,
			EatS = 3,
			EatW = 4,
			MoveN = 5,
			MoveE = 6,
			MoveS = 7,
			MoveW = 8,
			Dublicate = 9

		};

		struct LiveDot {
			Kiwii::Point_Exp point;
			creatures type;
			command gens[nGenes];
			uint8_t active_gen = 0;

			int16_t energy=0;

			LiveDot(int16_t energy) {
				for (int j = 0;j < nGenes;j++) {
					int a = rand() % 10;

					if (a == 0) gens[j] = Nothing;
					else if (a == 1) gens[j] = EatN;
					else if (a == 2) gens[j] = EatE;
					else if (a == 3) gens[j] = EatS;
					else if (a == 4) gens[j] = EatW;
					else if (a == 5) gens[j] = MoveN;
					else if (a == 6) gens[j] = MoveE;
					else if (a == 7) gens[j] = MoveS;
					else if (a == 8) gens[j] = MoveW;
					else  gens[j] = Dublicate;

				}
				this->energy = energy;
			}

			void move() {
				energy--;
				point.move();
			}
		};

		uint8_t xm = 120;
		uint8_t ym = 90;
		std::vector<LiveDot> Dots;
		Kiwii::Map_Exp<char> Map = Kiwii::Map_Exp<char>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(xm, ym);



		Experiment1() {
			for(int j=0;j<ym;j++)
				for (int i = 0;i < xm;i++)
					Map.map[i][j] = '.';
		}

		void GenerateCreature(uint16_t n) {
			Dots.clear();
			for (int i = 0;i < n;i++) {
				Dots.push_back(Kiwii_Experiment::Experiment1::LiveDot(rand()%45));
			
				int ran = rand()%4;
				if (ran == 0) Dots[i].type = Plants;
				else if (ran == 1) Dots[i].type = Herbivors;
				else if (ran == 2) Dots[i].type = Carnivorous;
				else Dots[i].type = Bacteries;

				Dots[i].point.set_pos(rand() % xm, rand() % ym);

				Dots[i].point.set_move((rand() % 3) - 1, (rand() % 3) - 1);
			}
		}

		void GenerateLight() {
			
			Kiwii::Map_Exp<uint8_t> MapSunAlpha = Kiwii::Map_Exp<uint8_t>(xm, ym);
			int min = 128;
			double z = 1;
			double zz = 1;
			const uint8_t a = 7;
			int mas_k[a] = {30,15,10,5,3,2,1 };
			
			for (int s = 0;s < a;s++) {
				
				for (int i = 0;i < MapSunAlpha.x;i += mas_k[s])
					for (int j = 0;j < MapSunAlpha.y;j += mas_k[s]) {
						int8_t NUM = rand();
						NUM = (NUM - min);
						for (int ii = i;ii < i + mas_k[s];ii++)
							for (int ji = j;ji < j + mas_k[s];ji++)
								if(s==0)
									MapSunAlpha.map[ii][ji] = NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));
								else MapSunAlpha.map[ii][ji] += NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));

					}

				for (int i = 0;i < MapSun.x;i += 1)
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
		}

		void GenerateMineral() {

			Kiwii::Map_Exp<uint8_t> MapMineralAlpha = Kiwii::Map_Exp<uint8_t>(xm, ym);
			int min = 128;
			double z = 1;
			double zz = 1;
			const uint8_t a = 7;
			int mas_k[a] = { 30,15,10,5,3,2,1 };

			for (int s = 0;s < a;s++) {

				for (int i = 0;i < MapMineralAlpha.x;i += mas_k[s])
					for (int j = 0;j < MapMineralAlpha.y;j += mas_k[s]) {
						int8_t NUM = rand();
						NUM = (NUM - min);
						for (int ii = i;ii < i + mas_k[s];ii++)
							for (int ji = j;ji < j + mas_k[s];ji++)
								if (s == 0)
									MapMineralAlpha.map[ii][ji] = NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));
								else MapMineralAlpha.map[ii][ji] += NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz));

					}

				for (int i = 0;i < MapSun.x;i += 1)
					for (int j = 0;j < MapSun.y;j += 1) {
						MapMineral.map[i][j] =
							(
								MapMineralAlpha.map[Kiwii::fix<int>(i - 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i + 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j, 0, MapMineralAlpha.y)]
								+
								MapMineralAlpha.map[Kiwii::fix<int>(i - 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i + 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i - 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i + 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapMineralAlpha.y)]
								+
								MapMineralAlpha.map[Kiwii::fix<int>(i + 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i + 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i + 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapMineralAlpha.y)]
								+
								MapMineralAlpha.map[Kiwii::fix<int>(i + 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i - 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 2, 0, MapMineralAlpha.y)]
								+
								MapMineralAlpha.map[Kiwii::fix<int>(i - 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 1, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i - 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i - 2, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j + 1, 0, MapMineralAlpha.y)]
								+
								MapMineralAlpha.map[Kiwii::fix<int>(i + 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapMineralAlpha.y)] +
								MapMineralAlpha.map[Kiwii::fix<int>(i - 1, 0, MapMineralAlpha.x)][Kiwii::fix<int>(j - 2, 0, MapMineralAlpha.y)]
								)
							/ 20;
					}
			}
		}

		void ToMakeMountain(double z) {
			for (int i = 0;i < MapSun.x;i += 1)
				for (int j = 0;j < MapSun.y;j += 1)
					MapSun.map[i][j] = pow(double(MapSun.map[i][j]) / 256.0,z)*256;
			for (int i = 0;i < MapMineral.x;i += 1)
				for (int j = 0;j < MapMineral.y;j += 1)
					MapMineral.map[i][j] = pow(double(MapMineral.map[i][j]) / 256.0, 1.0/z) * 256;
		}

		void Logic(bool is_undead) {
			//gen_move
			{

			}
			//move
			{
				for (int i = 0;i < Dots.size();i++) {
					if (Dots[i].point.x + Dots[i].point.dx >= 0
						&& Dots[i].point.y + Dots[i].point.dy >= 0
						&& Dots[i].point.x + Dots[i].point.dx < xm
						&& Dots[i].point.y + Dots[i].point.dy < ym)
						Dots[i].move();
				}
			}
			//check
			if(!is_undead)
			{
				auto iter = Dots.begin();

				while (iter != Dots.end()) {
					if (iter->energy <= 0) {
						Dots.erase(iter);
						iter = Dots.begin();
					}
					iter++;
				}
			}
			
		}

		void WriteDots() {
			for (int j = 0;j < ym;j++)
				for (int i = 0;i < xm;i++)
					Map.map[i][j] = '.';
			for (int i = 0;i < Dots.size();i++) {
				Map.map[Kiwii::fix<int>(Dots[i].point.x, 0, Map.x)][Kiwii::fix<int>(Dots[i].point.y, 0, Map.y)] = Dots[i].type;
			}
		}
	};

}