#pragma once
#include <vector>
#include "../../Mathem/Mathem.h"
#include "../_Template/_temp.h"

class Exper_2 {
public:
	Kiwii::vec2 size;
	Kiwii::mapc scr;

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

			if (dir.X + dir.Y + dir.Z >= 1.5) skin = 'A';

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

	Kiwii::mapc mappp;
	Kiwii::mapf sunnn;
	Kiwii::mapf miner;
	Kiwii::mapf landscape;
	std::vector<creature> exist;
	double time;

	Exper_0(uint16_t n) {

		sunnn = Kiwii::Perlin(X, Y,4);
		miner = Kiwii::Perlin(X, Y,4);
		landscape = Kiwii::Perlin(X, Y,4);

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
			creature& cre = exist[i];
			uint8_t& gen = cre.gens[exist[i].act];
			int x = cre.pos.X;
			int y = cre.pos.Y;

			switch (gen) {
			case nothing:
				break;
			case duplicate_n: 
				exist.push_back(creature());
				exist[exist.size() - 1].reset(cre);
				break;
			case duplicate_e:
				exist.push_back(creature());
				exist[exist.size() - 1].reset(cre);
				break;
			case duplicate_s:
				exist.push_back(creature());
				exist[exist.size() - 1].reset(cre);
				break;
			case duplicate_w:
				exist.push_back(creature());
				exist[exist.size() - 1].reset(cre);
				break;
			case move_n: 
				if (cre.pos.Y - 1 >= 0)
					if (mappp[(y - 1) * X + x] == '.')
						cre.pos.Y--;
					cre.energy -= pow(landscape[(y - 1) * X + x] + 1, 2);
				break;
			case move_e:
				if (cre.pos.X + 1 < X)
					if (mappp[y * X + x+1] == '.')
						cre.pos.X++;
				cre.energy -= pow(landscape[(y - 1) * X + x] + 1, 2);
				break;
			case move_s:
				if (cre.pos.Y + 1 < Y)
					if (mappp[(y + 1) * X + x] == '.')
						cre.pos.Y++;
				cre.energy -= pow(landscape[(y - 1) * X + x] + 1, 2);
				break;
			case move_w: 
				if (cre.pos.X - 1 >= 0) 
					if (mappp[y * X + x-1] == '.')
						exist[i].pos.X--; 
				cre.energy -= pow(landscape[(y - 1) * X + x] + 1, 2);
				break;
			case eat_s_n:
				if (cre.pos.Y - 1 >= 0)
					cre.energy += get_sun(sunnn[(y - 1) * X + x]);
				break;
			case eat_s_e:
				if (cre.pos.X + 1 >= 0)
					cre.energy += get_sun(sunnn[(y) * X + x+1]);
				break;
			case eat_s_s:
				if (cre.pos.Y + 1 >= 0)
					cre.energy += get_sun(sunnn[(y + 1) * X + x]);
				break;
			case eat_s_w:
				if (cre.pos.X - 1 >= 0)
					cre.energy += get_sun(sunnn[(y)*X + x - 1]);
				break;

			case eat_m_n:
				if (cre.pos.Y - 1 >= 0)
					cre.energy += miner[(y-1)*X + x] * 1.0 / nminerals;
				miner[(y-1)*X + x] -= nminerals;
				break;
			case eat_m_e:
				if (cre.pos.X + 1 >= 0)
					cre.energy += miner[(y)*X + x + 1]*1.0 / nminerals;
				miner[(y)*X + x + 1] -= nminerals;
				break;
			case eat_m_s:
				if (cre.pos.Y + 1 >= 0)
					cre.energy += miner[(y+ 1)*X + x ] * 1.0 / nminerals;
				miner[(y+ 1)*X + x ] -= nminerals;
				break;
			case eat_m_w:
				if (cre.pos.X - 1 >= 0)
					cre.energy += miner[(y)*X + x - 1] * 1.0 / nminerals;
				miner[(y)*X + x - 1] -= nminerals;
				break;
			}

			cre.energy--;
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
