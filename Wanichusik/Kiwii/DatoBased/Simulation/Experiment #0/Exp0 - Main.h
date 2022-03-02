#pragma once
#include <vector>
#include "../../Mathem/Mathem.h"
#include <iostream>

namespace Kiwii_Experiments {
	typedef float* mapf;
	typedef int* mapi;
	typedef double* mapd;
	typedef unsigned int* mapui;
	typedef unsigned char* mapuc;
	typedef char* mapc;

	static mapf Perlin(uint16_t X = 120, uint16_t Y = 90) {
		mapf map = new float[X * Y];

		int8_t k_null = 1;
		int8_t k = 1;
		float bias = -1351;

		uint16_t resolution = Kiwii::efclide(X, Y);
		uint16_t null_resolution = resolution;

		while (true) {
			if (resolution == 0)
				break;

			int ran;

			for (int i = 0;i < Y;i += resolution) {
				for (int j = 0;j < X;j += resolution) {
					ran = rand();

					float rnd = float(ran);

					rnd += bias;

					for (int ii = i;ii < i + resolution;ii++) 
						for (int ij = j;ij < j + resolution;ij++)
							if(i==0) map[ii * X + ij] += rnd * (float)resolution / (float)null_resolution;
							else map[ii * X + ij] =rnd* (float)resolution/ (float)null_resolution;
				}
			}

			map[0] = 1000/2;
			
			int sq = X * Y;
			map[sq-1] = 1000/2;
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					map[i * X + j] = (float(map[i * X + j]+
						map[Kiwii::fix<int>(i * X + j + 1, 0, sq)] +
						map[Kiwii::fix<int>((i + 1) * X + j, 0, sq)] +
						map[Kiwii::fix<int>(i * X + j - 1, 0, sq)] +
						map[Kiwii::fix<int>((i - 1) * X + j, 0, sq)] +
						map[Kiwii::fix<int>((i + 1) * X + j + 1, 0, sq)] +
						map[Kiwii::fix<int>((i + 1) * X + j - 1, 0, sq)] +
						map[Kiwii::fix<int>((i - 1) * X + j + 1, 0, sq)] +
						map[Kiwii::fix<int>((i - 1) * X + j - 1, 0, sq)] +
						map[Kiwii::fix<int>(i * X + j + 2, 0, sq)] +
						map[Kiwii::fix<int>((i + 1) * X + j + 2, 0, sq)] +
						map[Kiwii::fix<int>((i - 1) * X + j + 2, 0, sq)] +
						map[Kiwii::fix<int>(i * X + j - 2, 0, sq)] +
						map[Kiwii::fix<int>((i + 1) * X + j - 2, 0, sq)] +
						map[Kiwii::fix<int>((i - 1) * X + j - 2, 0, sq)] +
						map[Kiwii::fix<int>((i + 2) * X + j, 0, sq)] +
						map[Kiwii::fix<int>((i + 2) * X + j - 1, 0, sq)] +
						map[Kiwii::fix<int>((i + 2) * X + j + 1, 0, sq)] +
						map[Kiwii::fix<int>((i - 2) * X + j, 0, sq)] +
						map[Kiwii::fix<int>((i - 2) * X + j - 1, 0, sq)] +
						map[Kiwii::fix<int>((i - 2) * X + j + 1, 0, sq)]
						) / 20.0f);
				}
			}

			if (resolution == 1) {
				resolution = 0;
			}
			else {
				for (int i = 0;Kiwii::prime(i) <= resolution;i++) {

					if (resolution % Kiwii::prime(i) == 0) {
						resolution /= Kiwii::prime(i);
						break;
					}

				}
			}

			float mx = float(-INFINITY);
			float mn = float(INFINITY);
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					mx = max(mx, map[i * X + j]);
					mn = min(mn, map[i * X + j]);
				}
			}
			for (int i = 0;i < Y;i++)
				for (int j = 0;j < X;j++)
					map[i * X + j] = float(map[i * X + j] - mn) / float(mx - mn);
		}

		return map;
	}

	class Exper_0 {
	public:
		static const uint8_t X = 120;
		static const uint8_t Y = 90;
		static const uint8_t ngen = 64;
		static const uint8_t day = 24;
		static const uint16_t year = 365;
		static const uint8_t chance_mutant = 200;
		static const uint8_t nminerals = 5;

		static enum command {
			nothing = 0,
			duplicate_n = 1,
			duplicate_e = 2,
			duplicate_s = 3,
			duplicate_w = 4,
			move_n = 5,
			move_e = 6,
			move_s = 7,
			move_w = 8,
			eat_s_n = 9,
			eat_s_e = 10,
			eat_s_s = 11,
			eat_s_w = 12,
			eat_m_n = 13,
			eat_m_e = 14,
			eat_m_s = 15,
			eat_m_w = 16,
			eat_h_n = 17,
			eat_h_e = 18,
			eat_h_s = 19,
			eat_h_w = 20
			//less that 20 + ngen
		};

		struct creature {
			char skin;
			Kiwii::vec2 pos;
			Kiwii::vec3 dir;
			int16_t energy;
			uint8_t act;
			uint8_t gens[ngen];

			creature() {
				for (uint8_t i = 0;i < ngen;i++)
					gens[i] = rand() % (20+ngen);

				dir.X = float(rand()) / float(0x7fffffff);
				dir.Y = float(rand()) / float(0x7fffffff);
				dir.Z = float(rand()) / float(0x7fffffff);

				pos.X = rand() % X;
				pos.Y = rand() % Y;

				if (dir.X > dir.Y && dir.X > dir.Z) skin = 'S';
				else if (dir.Y > dir.X && dir.Y > dir.Z) skin = 'M';
				else skin = 'H';

				if (dir.X + dir.Y + dir.Z >= 2.5) skin = 'A';

				act = 0;
				energy = (rand()%50)+100;
			}

			void reset(creature& parent) {
				for (uint8_t i = 0;i < ngen;i++)
					gens[i] = parent.gens[i];

				if (rand() % 1000 < chance_mutant) {
					gens[rand() % ngen] = rand() % (20 + ngen);
				}

				dir.X = parent.dir.X + (float(rand()) / float(0x7fffffff)) * (float(chance_mutant) / 1000.0);
				dir.Y = parent.dir.Y + (float(rand()) / float(0x7fffffff)) * (float(chance_mutant) / 1000.0);
				dir.Z = parent.dir.Z + (float(rand()) / float(0x7fffffff)) * (float(chance_mutant) / 1000.0);

				if (dir.X > dir.Y && dir.X > dir.Z) skin = 'S';
				else if (dir.Y > dir.X && dir.Y > dir.Z) skin = 'M';
				else skin = 'H';

				if (dir.X + dir.Y + dir.Z >= 2.5) skin = 'A';

				pos.X = parent.pos.X;
				pos.Y = parent.pos.Y;

				switch (parent.gens[parent.act]) {
				case duplicate_n:
					parent.pos.Y--;
					break;
				case duplicate_e:
					parent.pos.X++;
					break;
				case duplicate_s:
					parent.pos.Y++;
					break;
				case duplicate_w:
					parent.pos.X--;
					break;
				}

				energy = parent.energy / 2;
				parent.energy /= 2;
				act = 0;
			}
		};

		double get_sun(float x) {
			if (Kiwii::cosinus(time, 1, 0, 1, 0) * Kiwii::sinus(time, 2.0 / double(year), 0, 15, 0) >= 0) return Kiwii::cosinus(time, 1, 0, 1, 0) * Kiwii::sinus(time, 2.0 / double(year), 0, 15, 0)*x;
			else return 0.0;
		}

		mapc mappp;
		mapf sunnn;
		mapf miner;
		std::vector<creature> exist;
		double time;

		Exper_0(uint16_t n) {
			sunnn = Perlin(X, Y);
			miner = Perlin(X, Y);

			mappp = new char[X * Y];

			for (int i = 0;i < n;i++)
				exist.push_back(creature());
		}

		void logic_actmove() {
			int sq = X * Y;
			for (int i = 0;i < exist.size();i++) {
				creature& creat = exist[i];
				int biaser = 0;
				int Xl = creat.pos.X;
				int Yl = creat.pos.Y;

				if (Xl - 1 >= 0) {
					if (Yl - 1 >= 0) {
						Xl--; Yl--;
						if (mappp[Yl * X + Xl] == 'S') biaser += 1;
						else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
						else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
						else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
						else biaser += 0;
						Xl++; Yl++;
					}
					Xl--;
					if (mappp[Yl * X + Xl] == 'S') biaser += 1;
					else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
					else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
					else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
					else biaser += 0;
					Xl++;
					if (Yl + 1 < sq) {
						Xl--; Yl++;
						if (mappp[Yl * X + Xl] == 'S') biaser += 1;
						else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
						else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
						else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
						else biaser += 0;
						Xl++; Yl--;
					}
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Yl - 1 >= 0) {
					Yl--;
					if (mappp[Yl * X + Xl] == 'S') biaser += 1;
					else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
					else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
					else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
					else biaser += 0;
					Xl++; Yl++;
				}
				if (Yl + 1 < sq) {
					Yl++;
					if (mappp[Yl * X + Xl] == 'S') biaser += 1;
					else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
					else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
					else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
					else biaser += 0;
					Yl--;
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Xl + 1 < sq) {
					if (Yl - 1 >= 0) {
						Xl++; Yl--;
						if (mappp[Yl * X + Xl] == 'S') biaser += 1;
						else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
						else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
						else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
						else biaser += 0;
						Xl--; Yl++;
					}
					Xl++;
					if (mappp[Yl * X + Xl] == 'S') biaser += 1;
					else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
					else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
					else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
					else biaser += 0;
					Xl--;
					if (Yl + 1 < sq) {
						Xl++; Yl++;
						if (mappp[Yl * X + Xl] == 'S') biaser += 1;
						else if (mappp[Yl * X + Xl] == 'M')biaser += 2;
						else if (mappp[Yl * X + Xl] == 'H')biaser += 3;
						else if (mappp[Yl * X + Xl] == 'A')biaser += 4;
						else biaser += 0;
						Xl--; Yl--;
					}
				}

				creat.act = (creat.act + biaser) % ngen;
				for (int i = 0;!(creat.gens[creat.act] < 21) && i < 10;i++) creat.act = (creat.act + creat.gens[creat.act]) % ngen;
			}
		}

		void logic_action() {
			for (int i = 0;i < exist.size();i++) {
				switch (rand()%4) {
				case 0: if (exist[i].pos.Y - 1 >= 0) exist[i].pos.Y--; break;
				case 1: if (exist[i].pos.X + 1 < X * Y) exist[i].pos.X++; break;
				case 2: if (exist[i].pos.Y + 1 < X * Y) exist[i].pos.Y++; break;
				case 3: if (exist[i].pos.X - 1 >= 0) exist[i].pos.X--; break;
				}

				exist[i].energy--;
			}
		}

		void logic_death() {
			int sq = X * Y;
			for(int i=exist.size()-1;i>=0;i--){
				if (exist[i].energy < 0) {
					int Xl = exist[i].pos.X;
					int Yl = exist[i].pos.Y;

					if (Xl - 1 >= 0) {
						if (Yl - 1 >= 0) {
							Xl--; Yl--;
							miner[Yl * X + Xl] += nminerals;
							Xl++; Yl++;
						}
						Xl--;
						miner[Yl * X + Xl] += nminerals;
						Xl++;
						if (Yl + 1 < sq) {
							Xl--; Yl++;
							miner[Yl * X + Xl] += nminerals;
							Xl++; Yl--;
						}
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (Yl - 1 >= 0) {
						Yl--;
						miner[Yl * X + Xl] += nminerals;
						Xl++; Yl++;
					}
					if (Yl + 1 < sq) {
						Yl++;
						miner[Yl * X + Xl] += nminerals;
						Yl--;
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (Xl + 1 < sq) {
						if (Yl - 1 >= 0) {
							Xl++; Yl--;
							miner[Yl * X + Xl] += nminerals;
							Xl--; Yl++;
						}
						Xl++;
						miner[Yl * X + Xl] += nminerals;
						Xl--;
						if (Yl + 1 < sq) {
							Xl++; Yl++;
							miner[Yl * X + Xl] += nminerals;
							Xl--; Yl--;
						}
					}

					exist.erase(exist.begin()+i);
				}
			}
		}

		void write() {
			for (int i = 0;i < X * Y;i++) mappp[i] = '.';

			for (int i = 0;i < exist.size();i++) mappp[int(exist[i].pos.X + exist[i].pos.Y * X)] = exist[i].skin;

			time += 1.0 / float(day);
		}

		~Exper_0() {
			delete[] mappp, sunnn, miner;
		}
	};
}
