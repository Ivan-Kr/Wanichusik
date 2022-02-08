#pragma once
#include "../_Template/_temp.h"
#include <vector>
#include <list>
#include <iostream>
#include <corecrt_math_defines.h>
#include "../../Mathem/Mathem.h"
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
	
	static Kiwii::Massive_Exp<uint8_t>& Perlin(Kiwii::Massive_Exp<uint8_t> mapp,uint8_t a,int list_a[],uint8_t inter) {
		Kiwii::Massive_Exp<uint8_t> map = mapp;
		Kiwii::Massive_Exp<uint8_t> mapAlpha(map.get_x(), map.get_y());
		for (int i = 0;i < map.get_y(); i++)
			for (int j = 0;j < map.get_x(); j++)
				mapAlpha.set_mas(j,i,0);

		int min = 128;
		double z = 1;
		double zz = 1;
		int* mas_k;
		mas_k=list_a;

		for (int s = 0;s < a;s++) {

			for (int i = 0;i < mapAlpha.get_x();i += mas_k[s]) {
				for (int j = 0;j < mapAlpha.get_y();j += mas_k[s]) {
					int8_t NUM = rand();
					NUM = (NUM - min);
					for (int ii = i;ii < i + mas_k[s];ii++) {
						for (int ji = j;ji < j + mas_k[s];ji++) {
							if (s == 0)
								mapAlpha.set_mas(ii, ji, mapAlpha.get_mas(ii,ji)+NUM * double(pow(mas_k[s], z) / pow(mas_k[0], zz)));
						}
					}

				}
			}
			//for (int i = 0;i < map.x;i += 1) {
			//	for (int j = 0;j < map.y;j += 1) {
			//		map.map[i][j] = mapAlpha.map[Kiwii::fix<int>(i, 0, mapAlpha.x)][Kiwii::fix<int>(j, 0, mapAlpha.y)];
			//	}
			//}
		}

		return map;
	}

	class Experiment0 {
		static const uint16_t nGenes = 16;
		static const uint16_t stealMin = 5;
		static const char emptySpace = '.';
		static const uint16_t DaysPerYear = 365;
		static const uint8_t HoursPerDay = 24;
		static Kiwii::vec2 M;
		uint64_t hour = 0;
		Kiwii::Map_Exp<char> Map = Kiwii::Map_Exp<char>(1,1);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(1, 1);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(1, 1);

		struct creature {
			uint8_t gen[nGenes];
			uint8_t pain[nGenes];
			int16_t energy = 30;
			uint16_t hour = 1;
			uint16_t max_hour = 1;
			uint8_t active_gen=0;
			uint8_t active_pain = 0;
			Kiwii::vec2 point;
			Kiwii::vec3 eater;

			creature() {
				for (uint16_t i = 0;i < nGenes;i++) {
					gen[i] = rand() % 32;
					pain[i] = rand() % 32;
				}

				point.X = rand() % int(M.X);
				point.Y = rand() % int(M.Y);

				eater.X = double(rand() % 1000) / 1000.0;
				eater.Y = double(rand() % 1000) / 1000.0;
				eater.Z = double(rand() % 1000) / 1000.0;
			}
			void live() {
				if (max_hour > hour && energy>0) {
					hour++;
					energy--;
				}
			}
			void move(double dx,double dy) {
				if (energy > 0) {
					energy--;
					point.X += dx;
					point.Y += dy;
				}
			}
			uint8_t get_pain(uint8_t d_active_pain) {
				active_pain += d_active_pain;
				return pain[active_pain];
			}
			uint8_t get_gen(uint8_t d_active_gen) {
				active_gen += d_active_gen;
				return gen [active_gen];
			}
		};

		std::vector<creature> creatures;

	public:



	};

	class Experiment1 {
	public:
		static const uint16_t nGenes = 64;
		static const uint16_t stealMin = 5;
		static const char emptySpace = '.';
		static const uint16_t DaysPerYear = 365;
		static const uint8_t HoursPerDay = 24;

		uint64_t year = 0;
		uint64_t day = 0;
		uint8_t hours = 0;

		enum creatures {
			Plants = '1',
			Herbivors = '2',
			Carnivorous = '3',
			Bacteries = '4',
		};

		enum command : uint8_t {
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
			uint8_t gens[nGenes];
			uint8_t active_gen = 0;

			int16_t energy = 0;

			LiveDot(int16_t energy) {
				for (uint8_t j = 0;j < nGenes;j++) {
					uint8_t a = rand() % 10;

					if (a == 0) gens[j] = Nothing;
					else if (a == 1) gens[j] = EatN;
					else if (a == 2) gens[j] = EatE;
					else if (a == 3) gens[j] = EatS;
					else if (a == 4) gens[j] = EatW;
					else if (a == 5) gens[j] = MoveN;
					else if (a == 6) gens[j] = MoveE;
					else if (a == 7) gens[j] = MoveS;
					else if (a == 8) gens[j] = MoveW;
					else if (a == 9)  gens[j] = Dublicate;

				}
				this->energy = energy;
			}

			void live() {
				energy--;
			}

			void move() {
				energy--;
				point.move();
			}
		};
		bool operator() (LiveDot i, LiveDot j) { return (i.energy < j.energy); }
		bool is_alive(const LiveDot& dot) {
			if (dot.energy < 0) {

				//uint8_t x = dot.point.x;
				//uint8_t y = dot.point.y;

				//if (x + 1 < xm && y + 1 < ym)Kiwii_Experiment::Experiment1::MapMineral.map[x + 1][y + 1] += stealMin * 4 * (1 / M_SQRT2);
				//if (x + 1 < xm)Kiwii_Experiment::Experiment1::MapMineral.map[x + 1][y] += stealMin * 4;
				//if (x + 1 < xm && y - 1 >= 0)Kiwii_Experiment::Experiment1::MapMineral.map[x + 1][y - 1] += stealMin * 4 * (1 / M_SQRT2);
				//if (y + 1 < ym)Kiwii_Experiment::Experiment1::MapMineral.map[x][y + 1] += stealMin * 4;
				//Kiwii_Experiment::Experiment1::MapMineral.map[x][y] += stealMin * 4 * 2;
				//if (x + 1 < xm)Kiwii_Experiment::Experiment1::MapMineral.map[x][y - 1] += stealMin * 4;
				//if (x - 1 >= 0 && y + 1 < ym)Kiwii_Experiment::Experiment1::MapMineral.map[x - 1][y + 1] += stealMin * 4 * (1 / M_SQRT2);
				//if (x - 1 >= 0)Kiwii_Experiment::Experiment1::MapMineral.map[x - 1][y] += stealMin * 4;
				//if (x - 1 >= 0 && y - 1 >= 0)Kiwii_Experiment::Experiment1::MapMineral.map[x - 1][y - 1] += stealMin * 4 * (1 / M_SQRT2);

				return true;
			}
			else return false;
		}

		uint8_t xm = 120;
		uint8_t ym = 90;
		std::list<LiveDot> dots;
		Kiwii::Map_Exp<char> Map = Kiwii::Map_Exp<char>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapSun = Kiwii::Map_Exp<uint8_t>(xm, ym);
		Kiwii::Map_Exp<uint8_t> MapMineral = Kiwii::Map_Exp<uint8_t>(xm, ym);

		TIME_POINT gen1;
		TIME_POINT do1;
		TIME_POINT check1;
		TIME_POINT gen2;
		TIME_POINT do2;
		TIME_POINT check2;

		Experiment1() {
			for (int j = 0;j < ym;j++)
				for (int i = 0;i < xm;i++)
					Map.map[i][j] = emptySpace;
		}

		double get_sun(uint8_t dot, uint64_t hours) {
			double hou = double(hours) / 10;
			return dot * ((sin(M_PI * hours * (2 / HoursPerDay)) * 0.5 + 0.5) * (sin(M_PI * hours * (2 / (DaysPerYear * HoursPerDay))) + 1));
		}

		void generate_creature(uint16_t n) {
			dots.clear();
			for (int i = 0;i < n;i++) {
				dots.push_back(Kiwii_Experiment::Experiment1::LiveDot(rand() % 45));


				int ran = rand() % 4;
				if (ran == 0) dots.back().type = Plants;
				else if (ran == 1) dots.back().type = Herbivors;
				else if (ran == 2) dots.back().type = Carnivorous;
				else dots.back().type = Bacteries;

				dots.back().point.set_pos(rand() % xm, rand() % ym);
			}
		}

		void generate_light() {

			Kiwii::Map_Exp<uint8_t> MapSunAlpha = Kiwii::Map_Exp<uint8_t>(xm, ym);
			int min = 128;
			double z = 1;
			double zz = 1;
			const uint8_t a = 7;
			int mas_k[a] = { 30,15,10,5,3,2,1 };

			for (int s = 0;s < a;s++) {

				for (int i = 0;i < MapSunAlpha.x;i += mas_k[s])
					for (int j = 0;j < MapSunAlpha.y;j += mas_k[s]) {
						int8_t NUM = rand();
						NUM = (NUM - min);
						for (int ii = i;ii < i + mas_k[s];ii++)
							for (int ji = j;ji < j + mas_k[s];ji++)
								if (s == 0)
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
							/ 20;
					}
			}
		}

		void generate_mineral() {

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

		void make_mountain(double z) {
			for (int i = 0;i < MapSun.x;i += 1)
				for (int j = 0;j < MapSun.y;j += 1)
					MapSun.map[i][j] = pow(double(MapSun.map[i][j]) / 256.0, z) * 256;
			for (int i = 0;i < MapMineral.x;i += 1)
				for (int j = 0;j < MapMineral.y;j += 1)
					MapMineral.map[i][j] = pow(double(MapMineral.map[i][j]) / 256.0, 1.0 / z) * 256;
		}

		void logic() {
			//gen_move
			gen1 = NOW;
			{
				for (auto i = dots.begin();i != dots.end();i++) {
					int16_t x = i->point.x;
					int16_t y = i->point.y;

					if (x + 1 < xm) {
						if (Map.map[x + 1][y] == Plants) i->active_gen += 1;
						else if (Map.map[x + 1][y] == Herbivors) i->active_gen += 2;
						else if (Map.map[x + 1][y] == Carnivorous) i->active_gen += 3;
						else if (Map.map[x + 1][y] == Bacteries) i->active_gen += 4;
					}
					if (x - 1 >= 0) {
						if (Map.map[x - 1][y] == Plants) i->active_gen += 1;
						else if (Map.map[x - 1][y] == Herbivors) i->active_gen += 2;
						else if (Map.map[x - 1][y] == Carnivorous) i->active_gen += 3;
						else if (Map.map[x - 1][y] == Bacteries) i->active_gen += 4;
					}
					if (y + 1 < ym) {
						if (Map.map[x][y + 1] == Plants) i->active_gen += 1;
						else if (Map.map[x][y + 1] == Herbivors) i->active_gen += 2;
						else if (Map.map[x][y + 1] == Carnivorous) i->active_gen += 3;
						else if (Map.map[x][y + 1] == Bacteries) i->active_gen += 4;
					}
					if (y - 1 >= 0) {
						if (Map.map[x][y - 1] == Plants) i->active_gen += 1;
						else if (Map.map[x][y - 1] == Herbivors) i->active_gen += 2;
						else if (Map.map[x][y - 1] == Carnivorous) i->active_gen += 3;
						else if (Map.map[x][y - 1] == Bacteries) i->active_gen += 4;
					}
					i->active_gen;

					i->active_gen = (i->active_gen + 1) % nGenes;

					//uint8_t buf = 0;
					//while (Dots[i].gens[Dots[i].active_gen] > 9&&buf<20) {
					//	Dots[i].active_gen = Dots[i].gens[Dots[i].active_gen]-10;
					//	buf++;
					//}
				}
			}
			gen2 = NOW;
			//
			do1 = NOW;
			{
				for (auto i = dots.begin();i != dots.end();i++) {

					int16_t x = i->point.x;
					int16_t y = i->point.y;

					if (i->gens[i->active_gen] == EatN && y - 1 >= 0) {

						y--;

						switch (i->type) {
							//plant must eat sun in current dir
						case Plants:
							i->energy += get_sun(MapSun.map[x][y], hours + day * HoursPerDay + year * DaysPerYear * HoursPerDay);
							break;
						case Herbivors:
							//animal must eat plant in current dir
							if (Map.map[x][y] == Plants) {

								//if there is a plant, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Plants)) iter++;

								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Carnivorous:
							//animal must eat animal in current dir
							if (Map.map[x][y] == Herbivors) {

								//if there is an animal, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && iter->point.x != x && iter->point.y != y && iter->type != Herbivors)
									iter++;
								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Bacteries:
							//bacteria must eat minerals in current dir
							if (MapMineral.map[x][y] > stealMin) {
								MapMineral.map[x][y] -= stealMin;
								i->energy += MapMineral.map[x][y] + stealMin;
							}
							break;
						}
					}
					else if (i->gens[i->active_gen] == EatE && x + 1 < xm) {

						x++;

						switch (i->type) {
							//plant must eat sun in current dir
						case Plants:
							i->energy += get_sun(MapSun.map[x][y], hours + day * HoursPerDay + year * DaysPerYear * HoursPerDay);;
							break;
						case Herbivors:
							//animal must eat plant in current dir
							if (Map.map[x][y] == Plants) {

								//if there is a plant, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Plants)) iter++;

								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Carnivorous:
							//animal must eat animal in current dir
							if (Map.map[x][y] == Herbivors) {

								//if there is an animal, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Herbivors))
									iter++;
								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Bacteries:
							//bacteria must eat minerals in current dir
							if (MapMineral.map[x][y] > stealMin) {
								MapMineral.map[x][y] -= stealMin;
								i->energy += MapMineral.map[x][y] + stealMin;
							}
							break;
						}
					}
					else if (i->gens[i->active_gen] == EatS && y + 1 < ym) {

						y++;

						switch (i->type) {
							//plant must eat sun in current dir
						case Plants:
							i->energy += get_sun(MapSun.map[x][y], hours + day * HoursPerDay + year * DaysPerYear * HoursPerDay);;
							break;
						case Herbivors:
							//animal must eat plant in current dir
							if (Map.map[x][y] == Plants) {

								//if there is a plant, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Plants)) iter++;

								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Carnivorous:
							//animal must eat animal in current dir
							if (Map.map[x][y] == Herbivors) {

								//if there is an animal, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Herbivors))
									iter++;
								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);

							}
							break;
						case Bacteries:
							//bacteria must eat minerals in current dir
							if (MapMineral.map[x][y] > stealMin) {
								MapMineral.map[x][y] -= stealMin;
								i->energy += MapMineral.map[x][y] + stealMin;
							}
							break;
						}
					}
					else if (i->gens[i->active_gen] == EatW && x - 1 >= 0) {
						x--;
						switch (i->type) {
							//plant must eat sun in current dir
						case Plants:
							i->energy += get_sun(MapSun.map[x][y], hours + day * HoursPerDay + year * DaysPerYear * HoursPerDay);;
							break;
						case Herbivors:
							//animal must eat plant in current dir
							if (Map.map[x][y] == Plants) {
								//if there is a plant, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Plants)) iter++;

								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);
							}
							break;
						case Carnivorous:
							//animal must eat animal in current dir
							if (Map.map[x][y] == Herbivors) {
								//if there is an animal, then we search this
								auto iter = dots.begin();
								while (iter != dots.end() && !(iter->point.x != x && iter->point.y != y && iter->type != Herbivors))
									iter++;
								//we are stealing energy and then we are deleting 
								i->energy += iter->energy;
								dots.erase(iter);
							}
							break;
						case Bacteries:
							//bacteria must eat minerals in current dir
							if (MapMineral.map[x][y] > stealMin) {
								MapMineral.map[x][y] -= stealMin;
								i->energy += MapMineral.map[x][y] + stealMin;
							}
							break;
						}
					}
					else if (i->gens[i->active_gen] == MoveN && y - 1 >= 0) {
						y--;
						if (Map.map[x][y] == emptySpace) {
							i->point.y--;
							i->live();
						}
					}
					else if (i->gens[i->active_gen] == MoveE && x + 1 < xm) {
						x++;
						if (Map.map[x][y] == emptySpace) {
							i->point.x++;
							i->live();
						}
					}
					else if (i->gens[i->active_gen] == MoveS && y + 1 < ym) {
						y++;
						if (Map.map[x][y] == emptySpace) {
							i->point.y++;
							i->live();
						}
					}
					else if (i->gens[i->active_gen] == MoveW && x - 1 >= 0) {
						x--;
						if (Map.map[x][y] == emptySpace) {
							i->point.x--;
							i->live();
						}
					}
					else if (i->gens[i->active_gen] == Dublicate) {
						if (x + 1 < xm) {
							if (Map.map[x + 1][y] == emptySpace) {
								i->energy /= 2;
								dots.push_back(*i);
								dots.back().active_gen = 0;
								if (rand() % 5 == 4) dots.back().gens[rand() % 64] = rand() % 10;
								if (rand() % 25 == 24) {
									switch (1 + (rand() % 4)) {
									case 1:
										dots.back().type = Plants;
										break;
									case 2:
										dots.back().type = Herbivors;
										break;
									case 3:
										dots.back().type = Carnivorous;
										break;
									case 4:
										dots.back().type = Bacteries;
										break;
									}

								}
								i->point.x++;
							}
						}
						else if (y - 1 >= 0) {
							if (Map.map[x][y - 1] == emptySpace) {
								i->energy /= 2;
								dots.push_back(*i);
								i->active_gen = 0;
								if (rand() % 5 == 4) dots.back().gens[rand() % 64] = rand() % 10;

								if (rand() % 25 == 24) {
									switch (1 + (rand() % 4)) {
									case 1:
										dots.back().type = Plants;
										break;
									case 2:
										dots.back().type = Herbivors;
										break;
									case 3:
										dots.back().type = Carnivorous;
										break;
									case 4:
										dots.back().type = Bacteries;
										break;
									}

								}
								i->point.y--;
							}
						}
						else if (y + 1 < ym) {
							if (Map.map[x][y + 1] == emptySpace) {
								i->energy /= 2;
								dots.push_back(*i);
								dots.back().active_gen = 0;
								if (rand() % 5 == 4) dots.back().gens[rand() % 64] = rand() % 10;

								if (rand() % 25 == 24) {
									switch (1 + (rand() % 4)) {
									case 1:
										dots.back().type = Plants;
										break;
									case 2:
										dots.back().type = Herbivors;
										break;
									case 3:
										dots.back().type = Carnivorous;
										break;
									case 4:
										dots.back().type = Bacteries;
										break;
									}

								}
								i->point.y++;
							}
						}
						else if (x - 1 >= 0) {
							if (Map.map[x - 1][y] == emptySpace) {
								i->energy /= 2;
								dots.push_back(*i);
								dots.back().active_gen = 0;
								if (rand() % 5 == 4) dots.back().gens[rand() % 64] = rand() % 10;
								if (rand() % 25 == 24) {
									switch (1 + (rand() % 4)) {
									case 1:
										dots.back().type = Plants;
										break;
									case 2:
										dots.back().type = Herbivors;
										break;
									case 3:
										dots.back().type = Carnivorous;
										break;
									case 4:
										dots.back().type = Bacteries;
										break;
									}

								}
								i->point.x--;
							}
						}
					}

					i->live();
				}
			}
			do2 = NOW;
			//check
			check1 = NOW;
			{
				auto iter = dots.begin();
				uint32_t n = 0;

				while (iter != dots.end()) {
					if (iter->energy <= 0) {

						uint8_t x = iter->point.x;
						uint8_t y = iter->point.y;
						dots.erase(iter);
						if (x + 1 < xm && y + 1 < ym)MapMineral.map[x + 1][y + 1] += stealMin * 4 * (1 / sqrt(2));
						if (x + 1 < xm)MapMineral.map[x + 1][y] += stealMin * 4 * (1 / sqrt(1));
						if (x + 1 < xm && y - 1 >= 0)MapMineral.map[x + 1][y - 1] += stealMin * 4 * (1 / sqrt(2));
						if (y + 1 < ym)MapMineral.map[x][y + 1] += stealMin * 4 * (1 / sqrt(1));
						MapMineral.map[x][y] += stealMin * 4 * 2;
						if (x + 1 < xm)MapMineral.map[x][y - 1] += stealMin * 4 * (1 / sqrt(1));
						if (x - 1 >= 0 && y + 1 < ym)MapMineral.map[x - 1][y + 1] += stealMin * 4 * (1 / sqrt(2));
						if (x - 1 >= 0)MapMineral.map[x - 1][y] += stealMin * 4 * (1 / sqrt(1));
						if (x - 1 >= 0 && y - 1 >= 0)MapMineral.map[x - 1][y - 1] += stealMin * 4 * (1 / sqrt(2));
						iter = dots.begin();
						for (int i = 0;i < n;i++) iter++;
					}
						iter++;
						n++;
				}
			}
			check2 = NOW;
		}

		void write_dots() {
			if (dots.size() != 0) {
				for (int16_t j = 0;j < ym;j++)
					for (int16_t i = 0;i < xm;i++)
						Map.map[i][j] = emptySpace;
				for (auto i = dots.begin();i != dots.end();i++) {
					Map.map[Kiwii::fix<int16_t>(i->point.x, 0, Map.x)][Kiwii::fix<int16_t>(i->point.y, 0, Map.y)] = i->type;
				}
				hours++;
				if (hours > HoursPerDay) {
					hours -= HoursPerDay;
					day++;
				}
				if (hours > DaysPerYear) {
					day -= DaysPerYear;
					year++;
				}
			}
		}
	};

}