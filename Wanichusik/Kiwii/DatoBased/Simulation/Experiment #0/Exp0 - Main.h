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
	typedef short* maps;
	typedef unsigned short* mapus;
	typedef long long* mapll;
	typedef unsigned long long* mapull;

	static mapf Perlin(uint16_t X = 120,uint16_t Y = 90,int scale = 0) {
		mapf map = new float[X * Y];
		int8_t k_null = 1;
		int8_t k = 1;
		float bias = -1351;

		uint16_t resolution = Kiwii::efclide(X, Y);

		std::vector<int> all_resol;
		all_resol.push_back(resolution);
		for (int s = 0;s < all_resol.size();s++) {
			for (int i = 0;Kiwii::prime(i) <= all_resol[s];i++) {

				if (all_resol[s] % Kiwii::prime(i) == 0) {
					bool is_unique = true;
					int res = all_resol[s] / Kiwii::prime(i);
					for (int ss = 0;ss < all_resol.size();ss++) if (all_resol[ss] == res) is_unique = false;
					if (is_unique && scale<=res) all_resol.push_back(res);
					break;
				}

			}
		}

		for (int s = 0;s < all_resol.size();s++) {

			int ran;

			for (int i = 0;i < Y;i += all_resol[s]) {
				for (int j = 0;j < X;j += all_resol[s]) {
					ran = rand();

					float rnd = float(ran);

					rnd += bias;

					for (int ii = i;ii < i + all_resol[s];ii++)
						for (int ij = j;ij < j + all_resol[s];ij++)
							if(i==0) map[ii * X + ij] += rnd * (float)all_resol[s] / (float)resolution;
							else map[ii * X + ij] =rnd* (float)all_resol[s] / (float)resolution;
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
						) / 10.0f);
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

	class Exper_2 {
	public:
		Kiwii::vec2 size;
		mapc scr;


		Exper_2(Kiwii::vec2 size) {
			scr = new char[int(size.X * size.Y)];

			for (int i = 0;i<int(size.X * size.Y);i++)scr[i] = ' ';

			this->size = size;
		}
		void Segment(int x1, int y1, int x2, int y2, int c)
		{
			int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
			dx = x2 - x1;
			dy = y2 - y1;
			dx1 = fabs(dx);
			dy1 = fabs(dy);
			px = 2 * dy1 - dx1;
			py = 2 * dx1 - dy1;
			if (dy1 <= dx1)
			{
				if (dx >= 0)
				{
					x = x1;
					y = y1;
					xe = x2;
				}
				else
				{
					x = x2;
					y = y2;
					xe = x1;
				}
				scr[x + y * int(size.X)] = '#';
				for (i = 0;x < xe;i++)
				{
					x = x + 1;
					if (px < 0)
					{
						px = px + 2 * dy1;
					}
					else
					{
						if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						{
							y = y + 1;
						}
						else
						{
							y = y - 1;
						}
						px = px + 2 * (dy1 - dx1);
					}
					scr[x + y * int(size.X)] = '#';
				}
			}
			else
			{
				if (dy >= 0)
				{
					x = x1;
					y = y1;
					ye = y2;
				}
				else
				{
					x = x2;
					y = y2;
					ye = y1;
				}
				scr[x + y * int(size.X)] = '#';
				for (i = 0;y < ye;i++)
				{
					y = y + 1;
					if (py <= 0)
					{
						py = py + 2 * dx1;
					}
					else
					{
						if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
						{
							x = x + 1;
						}
						else
						{
							x = x - 1;
						}
						py = py + 2 * (dx1 - dy1);
					}
					scr[x + y * int(size.X)] = '#';
				}
			}
		}
	};

	class Exper_1 {
	public:
		static const uint8_t X = 240;
		static const uint8_t Y = 130;
		static const int force = 5000;

		mapf map;
		Exper_1() {
			map = Perlin(X,Y,3);
		}

		void rain() {
			Kiwii::vec2 dot(rand() % X, rand() % Y);

			std::vector<Kiwii::vec2> list;
			for (int i = 0;i < 128;i++) {
				int Xl = dot.X;
				int Yl = dot.Y;

				float mn = map[Xl + Yl * X];
				Kiwii::vec2 min_d = dot;

				if (Xl - 1 >= 0) {
					Xl--;
					if (Yl - 1 >= 0) {
						Yl--;
						if (map[Xl + Yl * X] + 1.0f/float(force) < mn) {
							min_d.X = Xl;
							min_d.Y = Yl;
							mn = map[Xl + Yl * X];
						}
						Yl++;
					}				
					if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
						min_d.X = Xl;
						min_d.Y = Yl;
						mn = map[Xl + Yl * X];
					}

					if (Yl + 1 < Y) {
						Yl++;
						if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
							min_d.X = Xl;
							min_d.Y = Yl;
							mn = map[Xl + Yl * X];
						}
						Yl--;
					}
					Xl++;
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Yl - 1 >= 0) {
					Yl--;
					if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
						min_d.X = Xl;
						min_d.Y = Yl;
						mn = map[Xl + Yl * X];
					}
					Yl++;
				}
				if (Yl + 1 < Y) {
					Yl++;
					if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
						min_d.X = Xl;
						min_d.Y = Yl;
						mn = map[Xl + Yl * X];
					}
					Yl--;
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Xl + 1 < X) {
					Xl++;
					if (Yl - 1 >= 0) {
						Yl--;
						if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
							min_d.X = Xl;
							min_d.Y = Yl;
							mn = map[Xl + Yl * X];
						}
						Yl++;
					}
					if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
						min_d.X = Xl;
						min_d.Y = Yl;
						mn = map[Xl + Yl * X];
					}
					if (Yl + 1 < Y) {
						Yl++;
						if (map[Xl + Yl * X] + 1.0f / float(force) < mn) {
							min_d.X = Xl;
							min_d.Y = Yl;
							mn = map[Xl + Yl * X];
						}
						Yl--;
					}
					Xl--;
				}

				bool is_unique = true;
				for (int i = 0;i < list.size();i++) {
					if (list[i].X == dot.X && list[i].Y == dot.Y) is_unique = false;
				}
				if (is_unique) list.push_back(dot);

				if (min_d.X == dot.X && min_d.Y == dot.Y && !is_unique) {
					break;
				}
				else {
					if(map[Xl + Yl * X]>=0.0f + 1.0f / float(force))
					map[Xl + Yl * X] -= 1.0f / float(force) * pow(map[Xl + Yl * X],0.5);
					dot = min_d;
				}
			}
			if (list.size() > 1) {
				int Xl = list[list.size() - 1].X;
				int Yl = list[list.size() - 1].Y;
				int Xj = list[list.size() - 2].X;
				int Yj = list[list.size() - 2].Y;

				if (Xl - 1 >= 0) {
					Xl--;
					if (Yl - 1 >= 0) {
						Yl--;
						if (!(Xl == Xj && Yl == Yj))
							map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						Yl++;
					}
					if (!(Xl == Xj && Yl == Yj))
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (Yl + 1 < Y) {
						Yl++;
						if (!(Xl == Xj && Yl == Yj))
							map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						Yl--;
					}
					Xl++;
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Yl - 1 >= 0) {
					Yl--;
					if (!(Xl == Xj && Yl == Yj))
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					Yl++;
				}
				if (Yl + 1 < Y) {
					Yl++;
					if (!(Xl == Xj && Yl == Yj))
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					Yl--;
				}
				//æææææææææææææææææææææææææææææææææææææææææææææææææææ
				if (Xl + 1 < X) {
					Xl++;
					if (Yl - 1 >= 0) {
						Yl--;
						if (!(Xl == Xj && Yl == Yj))
							map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						Yl++;
					}
					if (!(Xl == Xj && Yl == Yj))
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (Yl + 1 < Y) {
						Yl++;
						if (!(Xl == Xj && Yl == Yj))
							map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						Yl--;
					}
					Xl--;
				}
			}

			float mx = -INFINITY;
			float mn = INFINITY;
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					mx = max(mx, map[i * X + j]);
					mn = min(mn, map[i * X + j]);
				}
			}
			mn -= 1.0f / float(force);

			for (int i = 0;i < Y;i++)
				for (int j = 0;j < X;j++)
					map[i * X + j] = Kiwii::normalize(map[i * X + j], mn, mx);

			for (int Yl = 0;Yl < Y;Yl++) {
				for (int Xl = 0;Xl < X;Xl++) {
					int Xm = Xl;
					int Ym = Yl;
					double avr = 0.0;
					int S = 0;

					if (Xl - 1 >= 0) {
						Xl--;
						if (Yl - 1 >= 0) {
							Yl--;
							S++;
							avr += map[Xl + Yl * X];
							Yl++;
						}S++;
						avr += map[Xl + Yl * X];
						if (Yl + 1 < Y) {
							Yl++;S++;
							avr += map[Xl + Yl * X];
							Yl--;
						}
						Xl++;
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (Yl - 1 >= 0) {
						Yl--;S++;
						avr += map[Xl + Yl * X];
						Yl++;
					}
					if (Yl + 1 < Y) {
						Yl++;S++;
						avr += map[Xl + Yl * X];
						Yl--;
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (Xl + 1 < X) {
						Xl++;
						if (Yl - 1 >= 0) {
							Yl--;S++;
							avr += map[Xl + Yl * X];
							Yl++;
						}S++;
						avr += map[Xl + Yl * X];
						if (Yl + 1 < Y) {
							Yl++;S++;
							avr += map[Xl + Yl * X];
							Yl--;
						}
						Xl--;
					}
					avr /= S;
					map[Xl + Yl * X] += avr*0.00001;
				}
			}
		}
	};

	static const float nminerals = 0.05f;
	class Exper_0 {
	public:
		static const uint8_t X = 120;
		static const uint8_t Y = 90;
		static const uint8_t ngen = 64;
		static const uint8_t day = 24;
		static const uint16_t year = 365;
		static const uint8_t chance_mutant = 200;


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

				if (dir.X + dir.Y + dir.Z >= 2.0) skin = 'A';

				act = 0;
				energy = (rand()%500)+100;
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

				if (dir.X + dir.Y + dir.Z >= 2.0) skin = 'A';

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

			sunnn = new float[X*Y];
			miner = new float[X * Y];

			for (int i = 0;i < X * Y;i++) sunnn[i] = 0.0f;
			for (int i = 0;i < X * Y;i++) miner[i] = 0.0f;

			mappp = new char[int(X) * int(Y)];

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
					Yl++;
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
				case 0: if (exist[i].pos.Y - 1 >= 0) if(mappp[int((exist[i].pos.Y - 1)*X+ exist[i].pos.X)]=='.') exist[i].pos.Y--; break;
				case 1: if (exist[i].pos.X + 1 < X * Y) if (mappp[int((exist[i].pos.Y) * X + exist[i].pos.X+1)] == '.') exist[i].pos.X++; break;
				case 2: if (exist[i].pos.Y + 1 < X * Y) if (mappp[int((exist[i].pos.Y + 1) * X + exist[i].pos.X)] == '.') exist[i].pos.Y++; break;
				case 3: if (exist[i].pos.X - 1 >= 0) if (mappp[int((exist[i].pos.Y) * X + exist[i].pos.X-1)] == '.')exist[i].pos.X--; break;
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
						Yl++;
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

			for (int i = 0;i < exist.size();i++) 
				mappp[int(exist[i].pos.X) + int(exist[i].pos.Y)* X] = exist[i].skin;

			time += 1.0 / float(day);
		}

		~Exper_0() {
			exist.~vector();
			delete[] sunnn;
			delete[] miner;
			delete[] mappp;
		}
	};
}
