#pragma once
#include "../Deep/Deep.h"
#include <math.h>
#include <corecrt_math_defines.h>



namespace Kiwii {
	struct vec2 {
		double X = 0;
		double Y = 0;

		vec2() {}
		vec2(double val) { X = val; Y = val; }
		vec2(double x, double y) { X = x;Y = y; }

		vec2 operator+ (const vec2& one) { return vec2(X + one.X, Y + one.Y); }
		vec2 operator- (const vec2& one) { return vec2(X - one.X, Y - one.Y); }
		vec2 operator* (const vec2& one) { return vec2(X * one.X, Y * one.Y); }
		vec2 operator/ (const vec2& one) { return vec2(X / one.X, Y / one.Y); }
		vec2 operator+ (double one) { return vec2(X + one, Y + one); }
		vec2 operator- (double one) { return vec2(X - one, Y - one); }
		vec2 operator* (double one) { return vec2(X * one, Y * one); }
		vec2 operator/ (double one) { return vec2(X / one, Y / one); }
		vec2 operator-() { return vec2(-X, -Y); }
	};

	struct vec3 {
		double X = 0;
		double Y = 0;
		double Z = 0;

		vec3() {}
		vec3(double val) { X = val; Y = val;Z = val;}
		vec3(double x, double y, double z) { X = x;Y = y;Z = z; }
		vec3 operator+(vec3 const& one) { return vec3(X + one.X, Y + one.Y, Z + one.Z); }
		vec3 operator-(vec3 const& one) { return vec3(X - one.X, Y - one.Y, Z - one.Z); }
		vec3 operator*(vec3 const& one) { return vec3(X * one.X, Y * one.Y, Z * one.Z); }
		vec3 operator/(vec3 const& one) { return vec3(X / one.X, Y / one.Y, Z / one.Z); }
		vec3 operator+ (double one) { return vec3(X + one, Y + one, Z + one); }
		vec3 operator- (double one) { return vec3(X - one, Y - one, Z - one); }
		vec3 operator* (double one) { return vec3(X * one, Y * one, Z * one); }
		vec3 operator/ (double one) { return vec3(X / one, Y / one, Z / one); }
		vec3 operator-() { return vec3(-X, -Y, -Z); }
	};

	struct vec4 {
		double X = 0;
		double Y = 0;
		double Z = 0;
		double W = 0;

		vec4() {}
		vec4(double val) { X = val; Y = val;Z = val;W = val; }
		vec4(double x, double y, double z, double w) { X = x;Y = y;Z = z; W = w; }
		vec4 operator+(vec4 const& one) { return vec4(X + one.X, Y + one.Y, Z + one.Z, W + one.W); }
		vec4 operator-(vec4 const& one) { return vec4(X - one.X, Y - one.Y, Z - one.Z, W - one.W); }
		vec4 operator*(vec4 const& one) { return vec4(X * one.X, Y * one.Y, Z * one.Z, W * one.W); }
		vec4 operator/(vec4 const& one) { return vec4(X / one.X, Y / one.Y, Z / one.Z, W / one.W); }
		vec4 operator+ (double one) { return vec4(X + one, Y + one, Z + one, W + one);}
		vec4 operator- (double one) { return vec4(X - one, Y - one, Z - one, W - one); }
		vec4 operator* (double one) { return vec4(X * one, Y * one, Z * one, W * one); }
		vec4 operator/ (double one) { return vec4(X / one, Y / one, Z / one, W / one); }
		vec4 operator-() { return vec4(-X, -Y, -Z,-W); }
	};

	struct segment {
		vec2 A;
		vec2 B;

		segment() {}
		segment(const vec2& one, vec2& two) {
			A = one;
			B = two;
		}
		segment(const vec2& two) {
			A = vec2(0.0);
			B = two;
		}

		double_t length() { return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2)); }
	};

	struct angle {
		double angle_ = 0;

		angle() {}
		angle(double angle) { this->angle_ = angle_; }
		angle(double radian,int8_t n_PI) { angle_ = radian * 180.0 * M_PI*n_PI; }

		double rad() { return angle_ / (180.0 * M_PI); }
		void rad(double rd) { angle_ = rd / M_PI * 180.0; }

	};

	struct vector {
		segment line;

		vector() {}
		vector(const vec2 from, vec2 to) { line = segment(from, to); }
		vector(const vec2 two) { line = segment(two); }

		vec2 direction() { return line.B-line.A; }

		angle angle_() {
			vec2 dot(direction().X / line.length(), direction().Y/line.length());

			angle _angle;
			_angle.rad(acos(dot.X));

			if ((asin(dot.Y) / M_PI * 180.0) < 0)
				_angle.angle_ *= -1;

			return _angle;
		}

	};

	inline int64_t efclide(int64_t a, int64_t b) {
		while (a != b) {
			if (a < b) b -= a;
			else a -= b;
		}
		return a;
	}

	inline uint64_t prime(int64_t num) {
		uint64_t n = 0;
		for (int i = 2; i < 100&&num>=0; i++)
		{
			bool prime = true;
			for (int j = 2; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					prime = false;
					break;
				}
			}
			if (prime) { n = i;num--; }
		}
		return n;
	}
}
