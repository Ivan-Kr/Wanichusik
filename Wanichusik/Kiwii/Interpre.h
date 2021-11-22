#pragma once
#include "Screen.h"
#include <functional>
#include <vector>
#include <list>
#include <string>

namespace kiwii {
	__int64 min3(__int64 a, __int64 b, __int64 c) {
		if (a < b && a < c) return a;
		else if (b < c && b < a) return b;
		else return c;
	}
	__int64 max3(__int64 a, __int64 b, __int64 c) {
		if (a > b && a > c) return a;
		else if (b > c && b > a) return b;
		else return c;
	}

	unsigned __int32 num_leven(std::string first, std::string second) {

		std::vector<std::vector<unsigned __int32>> arr;
		int X = first.length() + 1;
		int Y = second.length() + 1;
		arr = reserve_vector(arr, X, Y);

		for (int j = 0;j < Y;j++) {
			for (int i = 0;i < X;i++) {
				if (j == 0) {
					arr[i][j] = i;
				}
				else if (i == 0) {
					arr[i][j] = j;
				}
				else {
					int min0 = arr[i - 1][j];
					int min2 = arr[i][j - 1];
					int min1 = arr[i - 1][j - 1];

					arr[i][j] = min3(min0, min1, min2);

					if (first[i - 1] != second[j - 1])
						arr[i][j]++;
				}


			}
		}

		return arr[X - 1][Y - 1];
	}

	unsigned __int32 num_wleven(std::wstring first, std::wstring second) {

		std::vector<std::vector<unsigned __int32>> arr;
		int X = first.length() + 1;
		int Y = second.length() + 1;
		arr = reserve_vector(arr, X, Y);

		for (int j = 0;j < Y;j++) {
			for (int i = 0;i < X;i++) {
				if (j == 0) {
					arr[i][j] = i;
				}
				else if (i == 0) {
					arr[i][j] = j;
				}
				else {
					int min0 = arr[i - 1][j];
					int min2 = arr[i][j - 1];
					int min1 = arr[i - 1][j - 1];

					arr[i][j] = min3(min0, min1, min2);

					if (first[i - 1] != second[j - 1])
						arr[i][j]++;
				}


			}
		}

		return arr[X - 1][Y - 1];
	}
}

