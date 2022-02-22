#pragma once
#include <vector>
#include <corecrt_math_defines.h>
#include "../../Mathem/Mathem.h"
#include <iostream>

namespace Kiwii_Experiments {
	typedef float* mapf;
	typedef int* mapi;
	typedef double* mapd;
	typedef unsigned int* mapui;
	typedef unsigned char* mapuc;

	static mapf Perlin(uint16_t X = 120, uint16_t Y = 90) {
		mapf map = new float[X * Y];

		int32_t bias = 0;

		uint16_t resolution = Kiwii::efclide(X, Y);
		uint16_t null_resolution = resolution;

		while (true) {
			if (resolution == 0)
				break;

			int ran;

			for (int i = 0;i < Y;i += resolution) {
				for (int j = 0;j < X;j += resolution) {
					ran = rand();

					float rnd = float(ran);

					for (int ii = i;ii < i + resolution;ii++) 
						for (int ij = j;ij < j + resolution;ij++)
							if(i==0) map[ii * X + ij] += rnd * (float(resolution) / float(null_resolution));
							else map[ii * X + ij] = rnd*(float(resolution) / float(null_resolution));
				}
			}

			{
				for (int i = 0;i < Y;i++) {
					for (int j = 0;j < X;j++)
						//std::cout << as[i * x + j]<<'\t';
						if (map[i * X + j] < 0.2) std::cout << ' ';
						else if (map[i * X + j] < 0.4) std::cout << char(176);
						else if (map[i * X + j] < 0.6) std::cout << char(177);
						else if (map[i * X + j] < 0.8) std::cout << char(178);
						else std::cout << char(219);
					std::cout << '\n';
				}
				std::cout << '\n';
			}

			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					map[i * X + j]+=(float(
						map[Kiwii::fix<int>(i * X + j + 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 1) * X + j, 0, X * Y)] +
						map[Kiwii::fix<int>(i * X + j - 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 1) * X + j, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 1) * X + j + 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 1) * X + j - 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 1) * X + j + 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 1) * X + j - 1, 0, X * Y)] +
						map[Kiwii::fix<int>(i * X + j + 2, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 1) * X + j + 2, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 1) * X + j + 2, 0, X * Y)] +
						map[Kiwii::fix<int>(i * X + j - 2, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 1) * X + j - 2, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 1) * X + j - 2, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 2) * X + j, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 2) * X + j - 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i + 2) * X + j + 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 2) * X + j, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 2) * X + j - 1, 0, X * Y)] +
						map[Kiwii::fix<int>((i - 2) * X + j + 1, 0, X * Y)]) / 10.0f);
				}
			}

			if (resolution == 1) {
				resolution = 0;
			}
			else {
				for (int i = 0;Kiwii::prime(i) <= resolution;i++) {

					if (resolution % Kiwii::prime(i) == 0) {
						resolution /= Kiwii::prime(i);
						break;
					}

				}
			}

			float mx = float(short(0x8000));
			float mn = float(short(0x7fff));
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					mx = max(mx, map[i * X + j]);
					mn = min(mn, map[i * X + j]);
				}
			}
			for (int i = 0;i < Y;i++)
				for (int j = 0;j < X;j++)
					map[i * X + j] = float(map[i * X + j] - mn) / float(mx - mn);

			{
				for (int i = 0;i < Y;i++) {
					for (int j = 0;j < X;j++)
						//std::cout << as[i * x + j]<<'\t';
						if (map[i * X + j] < 0.2) std::cout << ' ';
						else if (map[i * X + j] < 0.4) std::cout << char(176);
						else if (map[i * X + j] < 0.6) std::cout << char(177);
						else if (map[i * X + j] < 0.8) std::cout << char(178);
						else std::cout << char(219);
					std::cout << '\n';
				}
				std::cout << '\n';
			}
		}

		return map;
	}
}
