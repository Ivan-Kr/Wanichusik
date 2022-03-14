#pragma once
#include "../../Deep/Deep.h"
#include "../../Mathem/Mathem.h"

namespace Kiwii {
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

	mapf Perlin(uint16_t X, uint16_t Y, int scale = 0);
}
