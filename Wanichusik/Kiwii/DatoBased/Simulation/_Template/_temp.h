#pragma once
#include "../../Deep/Deep.h"
#include <chrono>



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

			map = new _Ty * [x];
			for (int i = 0;i < x;i++) map[i] = new _Ty[y];
		}

		~Map_Exp() {
			for (int i = 0;i < x;i++) delete[] map[i];
			delete[] map;

			x = 0;
			y = 0;
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
