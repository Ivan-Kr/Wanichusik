#pragma once
#include <vector>
#include <corecrt_math_defines.h>
#include "../../Mathem/Mathem.h"

namespace Kiwii_Experiments {
	typedef float* mapf;
	typedef int* mapi;
	typedef double* mapd;
	typedef unsigned int* mapui;

	static mapf Perlin(uint16_t X = 120, uint16_t Y = 90) {
		mapf map = new float[X * Y];

		uint16_t resolution = Kiwii::efclide(X, Y);
		uint16_t resol = resolution;
		while (true) {
			if (resolution == 0)
				break;

			mapf map_buf = new float[X * Y];

			int ran;

			for (int i = 0;i < Y;i+=resolution) {
				for (int j = 0;j < X;j += resolution) {
					ran = rand();

					for (int ii = i;ii < i + resolution;ii++) for (int ij = j;ij < j + resolution;ij++) map_buf[ii * X + ij] = ran;
				}
			}
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					float num = map_buf[i * X + j];
					num += ((
						map_buf[Kiwii::fix<int>(i * X + j+1,0, X * Y)]+
						map_buf[Kiwii::fix<int>((i+1) * X + j, 0, X * Y)]+
						map_buf[Kiwii::fix<int>(i * X + j - 1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 1) * X + j, 0, X * Y)]+
						map_buf[Kiwii::fix<int>((i + 1) * X + j + 1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i + 1) * X + j-1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 1) * X + j + 1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 1) * X + j-1, 0, X * Y)]+

						map_buf[Kiwii::fix<int>(i * X + j + 2, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i + 1) * X + j+2, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i-1) * X + j +2, 0, X * Y)] +

						map_buf[Kiwii::fix<int>(i * X + j - 2, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i + 1) * X + j - 2, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 1) * X + j - 2, 0, X * Y)] +

						map_buf[Kiwii::fix<int>((i + 2) * X + j, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i + 2) * X + j - 1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i + 2) * X + j + 1, 0, X * Y)] +

						map_buf[Kiwii::fix<int>((i - 2) * X + j, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 2) * X + j - 1, 0, X * Y)] +
						map_buf[Kiwii::fix<int>((i - 2) * X + j + 1, 0, X * Y)])/20)*(resolution/resol);

					map[i * X + j] = num;
				}
			}

			if (resolution == 1) {
				resolution = 0;
			}
			for (int i = 0;Kiwii::prime(i) <= resolution;i++) {

				if (resolution % Kiwii::prime(i) == 0) {
					resolution = resolution / Kiwii::prime(i);
					break;
				}
					
			}


			delete[] map_buf;
		}

		return map;
	}
}
