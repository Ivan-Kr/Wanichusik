#pragma once
#include "../_Template/_temp.h"

class Exper_1 {
public:
	static const uint8_t X = 90;
	static const uint8_t Y = 30;
	static const int force = 10000;
	static const int inter_force = 100000;

	Kiwii::mapf map;
	Kiwii::mapf slide;
	Exper_1() {
		map = Kiwii::Perlin(X, Y,5);
		slide = new float[X * Y];

		for (int i = 0;i < X * Y;i++) {
			slide[i] = 0.0f;
		}
	}

	void bias(Kiwii::mapf what) {
		for (int i = 0;i < X * Y;i++) map[i] += what[i];

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
				if (map[Xl + Yl * X] >= 0.0f + 1.0f / float(force))
					map[Xl + Yl * X] -= 1.0f / float(force) * pow(map[Xl + Yl * X],0.5);
				if (slide[Xl + Yl * X] + list.size() / 16.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0;

				int Xm = min_d.X;
				int Ym = min_d.Y;

				if(map[(Xl+(Xl-Xm)) + (Yl + (Yl - Ym)) * X] - map[Xl + Yl * X]>0.1 && map[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X] >= 0.0f + 1.0f / float(force))
					map[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X] -= 1.0f / float(force) * pow(map[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X], 0.5);

				if (map[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X] - map[Xl + Yl * X] > 0.1 && slide[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X] + list.size() / 16.0 < 1)
					slide[(Xl + (Xl - Xm)) + (Yl + (Yl - Ym)) * X] += list.size() / 16.0;

				if (map[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] - map[Xl + Yl * X] > 0.1 && map[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] >= 0.0f + 1.0f / float(force))
					map[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] -= 1.0f / float(force) * pow(map[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X], 0.5);

				if (map[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] - map[Xl + Yl * X] > 0.1 && slide[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] + list.size() / 16.0 < 1)
					slide[(Xm + (Xm - Xl)) + (Ym + (Ym - Yl)) * X] += list.size() / 16.0;

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
					if (!(Xl == Xj && Yl == Yj)) {
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
					}
					Yl++;
				}
				if (!(Xl == Xj && Yl == Yj)) {
					map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
				}
				if (Yl + 1 < Y) {
					Yl++;
					if (!(Xl == Xj && Yl == Yj)) {
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
					}
					Yl--;
				}
				Xl++;
			}
			//æææææææææææææææææææææææææææææææææææææææææææææææææææ
			if (Yl - 1 >= 0) {
				Yl--;
				if (!(Xl == Xj && Yl == Yj)) {
					map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
				}
				Yl++;
			}
			if (Yl + 1 < Y) {
				Yl++;
				if (!(Xl == Xj && Yl == Yj)) {
					map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
				}
				Yl--;
			}
			//æææææææææææææææææææææææææææææææææææææææææææææææææææ
			if (Xl + 1 < X) {
				Xl++;
				if (Yl - 1 >= 0) {
					Yl--;
					if (!(Xl == Xj && Yl == Yj)) {
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
					}
					Yl++;
				}
				if (!(Xl == Xj && Yl == Yj)) {
					map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
					if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
				}
				if (Yl + 1 < Y) {
					Yl++;
					if (!(Xl == Xj && Yl == Yj)) {
						map[Xl + Yl * X] -= 1.0f / float(force * 10) * pow(map[Xl + Yl * X], 0.5);
						if (slide[Xl + Yl * X] + list.size() / 16.0 / 10.0 < 1)slide[Xl + Yl * X] += list.size() / 16.0 / 10.0;
					}
					Yl--;
				}
				Xl--;
			}
		}

		float imx = -INFINITY;
		float imn = INFINITY;
		for (int i = 0;i < Y;i++) {
			for (int j = 0;j < X;j++) {
				imx = max(imx, slide[i * X + j]);
				imn = min(imn, slide[i * X + j]);
			}
		}
		for (int i = 0;i < Y;i++)
			for (int j = 0;j < X;j++) {
				slide[i * X + j] = Kiwii::normalize(slide[i * X + j], imn, imx);
				slide[i * X + j] -= (imx + imn) / 2.0 * 0.05;
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


	}

	double dig() {
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
				map[Xl + Yl * X] += avr * 1.0f / float(inter_force);
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

		return mn + 1.0f / float(force);
	}

	~Exper_1() {
		delete[] map;
	}
};

