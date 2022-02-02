#pragma once
#include "../Deep/Deep.h"
#include <math.h>
#include <corecrt_math_defines.h>



namespace Kiwii {
	struct Dot {
		double_t X = 0;
		double_t Y = 0;

		Dot() {}
		Dot(double_t val) { X = val; Y = val; }
		Dot(double_t x, double_t y) { X = x;Y = y; }

		Dot operator+ (const Dot& one) { return Dot(X + one.X, Y + one.Y); }
		Dot operator- (const Dot& one) { return Dot(X - one.X, Y - one.Y); }
		Dot operator* (const Dot& one) { return Dot(X * one.X, Y * one.Y); }
		Dot operator/ (const Dot& one) { return Dot(X / one.X, Y / one.Y); }
		Dot operator+ (double_t one) { return Dot(X + one, Y + one); }
		Dot operator- (double_t one) { return Dot(X - one, Y - one); }
		Dot operator* (double_t one) { return Dot(X * one, Y * one); }
		Dot operator/ (double_t one) { return Dot(X / one, Y / one); }
	};

	struct Segment {
		Dot A;
		Dot B;

		Segment() {}
		Segment(const Dot& one, Dot& two) {
			A = one;
			B = two;
		}
		Segment(const Dot& two) {
			A = Dot(0.0);
			B = two;
		}

		double_t length() { return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2)); }
	};

	struct Angle {
		double_t angle = 0;

		Angle() {}
		Angle(double_t angle) { this->angle = angle; }
		Angle(double_t radian,int8_t n_PI) { angle = radian * 180.0 * M_PI*n_PI; }

		double_t rad() { return angle / (180.0 * M_PI); }
		void rad(double_t rd) { angle = rd / M_PI * 180.0; }

	};

	struct Vector {
		Segment line;

		Vector() {}
		Vector(const Dot from, Dot to) { line = Segment(from, to); }
		Vector(const Dot two) { line = Segment(two); }

		Dot direction() { return line.B-line.A; }

		Angle angle() {
			Dot dot(direction().X / line.length(), direction().Y/line.length());

			Angle angle;
			angle.rad(acos(dot.X));

			if ((asin(dot.Y) / M_PI * 180.0) < 0)
				angle.angle *= -1;

			return angle;
		}

	};

	//int64_t efclide(int64_t a, int64_t b) {
	//	while (a != b) {
	//		max(a, b) -= min(a, b);
	//	}
	//	return a;
	//}
}
