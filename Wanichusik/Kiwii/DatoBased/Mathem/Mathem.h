#pragma once
#include "../Deep/Deep.h"
#include <math.h>

struct Dot {
	double_t X;
	double_t Y;

	Dot(){}
	Dot(double_t val) { X = val; Y = val; }
	Dot(double_t x, double_t y) { X = x;Y = y; }

	Dot operator+ (const Dot& one){ return Dot(X + one.X, Y + one.Y); }
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

	Segment(){}
	Segment(const Dot& one, Dot& two) { 
		A = one;
		B = two;
		
	}
	Segment(const Dot& two) {
		A=Dot(0.0);
		B = two;
	}

	double_t length() {
		return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2));
	}
};

