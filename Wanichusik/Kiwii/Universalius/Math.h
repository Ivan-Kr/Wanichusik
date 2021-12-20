#pragma once

#include <math.h>

namespace Kiwii {
	namespace universalius {
		typedef unsigned int wint;
		typedef float procent;

		template<typename T>
		struct vec2 {
			T x, y;
			vec2 operator+(vec2 const& other) { return vec2(x + other.x, y + other.y); }
			vec2 operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }
			vec2 operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
			vec2 operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }
		};

		double piphagor(double a, double b) {
			return sqrt(a * a + b * b);
		}

		template<typename T>
		double avge(T* mas, unsigned __int16 nmas) {
			double avg = 0;
			for (int i = 0;i < nmas;i++)
				avg += mas[i];
			avg /= nmas;
			return avg;
		}
	}
}
