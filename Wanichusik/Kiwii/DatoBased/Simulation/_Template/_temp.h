#pragma once
#include "../../Deep/Deep.h"
#include <chrono>
#include <memory>
#include <vector>

namespace Kiwii {
	template<typename _Ty>
	class Map_Exp {
	public:
		_Ty** map;
		uint16_t x = 0;
		uint16_t y = 0;

		Map_Exp(uint16_t x, uint16_t y) {
			this->x = x;
			this->y = y;

			map = new _Ty*[x];
			for (int i = 0;i < x;i++) map[i] = new _Ty[y];
		}

		~Map_Exp() {
			for (int i = 0;i < x;i++) delete[] map[i];
			delete[] map;

			x = 0;
			y = 0;
		}
	};

	template<typename T>
	class Massive_Exp {
		public:
		uint16_t X=0;
		uint16_t Y=0;
		std::vector<std::vector<T>> mas;

		Massive_Exp(uint16_t x, uint16_t y) {
				X = x;
				Y = y;

				mas.resize(X);
				for (int i = 0;i < X;i++) mas[i].resize(Y);
		}

		void set_mas(uint16_t x, uint16_t y,T what) {
			if (x < X && y < Y) mas[x][y] = what;
		}
		T get_mas(uint16_t x, uint16_t y) {
				if(x < X && y < Y) 
					return mas[x][y];
		}

		uint16_t get_x() { return X;}
		uint16_t get_y() { return Y; }

		void fill_mas(T what) {
				for (uint16_t j = 0;j < Y;j++)
					for (uint16_t i = 0;i < X;i++)
						mas[i][j] = what;
		}

		std::vector<T> to_line() {
			std::vector<T> a;
			a.resize(X * Y);

			for (int i = 0;i < Y;i++) for (int j = 0;j < X;j++) a[i * X + j] = mas[j][i];
		}

		~Massive_Exp() {
				for (uint16_t i = 0;i < X;i++) mas[i].clear();
				mas.clear();

				X = 0;
				Y = 0;
		}


	};

	class Point_Exp {
	public:
		int16_t x = 0;
		int16_t y = 0;

		int16_t dx = 0;
		int16_t dy = 0;

		void set_pos(int16_t x, int16_t y) {
			this->x = x;
			this->y = y;
		}

		void move() {
			x += dx;
			y += dy;
		}

		void stop() {
			dx = 0;
			dy = 0;
		}

	};

	class Dot_Exp {
	public:
		double x = 0;
		double y = 0;

		double dx = 0;
		double dy = 0;

		void set_pos(double x, double y) {
			this->x = x;
			this->y = y;
		}
		void set_move(double dx, double dy) {
			this->dx = dx;
			this->dy = dy;
		}

		void move() {
			x += dx;
			y += dy;
		}

		void stop() {
			dx = 0;
			dy = 0;
		}

	};

#define TIME_POINT std::chrono::system_clock::time_point
#define NOW std::chrono::system_clock::now()

}
