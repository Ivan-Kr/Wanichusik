#include "_temp.h"

Kiwii::mapf Kiwii::Perlin(uint16_t X, uint16_t Y, int scale) {
	mapf map = new float[X * Y];
	mapf alpha = new float[X * Y];
	int8_t k_null = 1;
	int8_t k = 1;
	float bias = -1351;

	float mx = 1.0;
	float mn = 0.0;

	uint16_t resolution = Kiwii::efclide(X, Y);

	std::vector<int> all_resol;
	all_resol.push_back(resolution);
	for (int s = 0;s < all_resol.size();s++) {
		for (int i = 0; Kiwii::prime(i) <= all_resol[s];i++) {

			if (all_resol[s] % Kiwii::prime(i) == 0) {
				bool is_unique = true;
				int res = all_resol[s] / Kiwii::prime(i);
				for (int ss = 0;ss < all_resol.size();ss++) if (all_resol[ss] == res) is_unique = false;
				if (is_unique && scale <= res) all_resol.push_back(res);
				break;
			}

		}
	}

	for (int i = 0;i < X * Y;i++) map[i] = 0.0;

	for (int s = 0;s < all_resol.size();s++) {

		int ran;

		for (int i = 0;i < Y;i += all_resol[s]) {
			for (int j = 0;j < X;j += all_resol[s]) {
				ran = rand();

				float rnd = float(ran);

				rnd += bias;

				for (int ii = i;ii < i + all_resol[s];ii++)
					for (int ij = j;ij < j + all_resol[s];ij++)
						alpha[ii * X + ij] = rnd * pow(all_resol[s], 1) / pow(resolution, 1);
			}
		}

		int sq = X * Y;
		for (int q = 0;q <= all_resol[s];q++) {
			for (int i = 0;i < Y;i++) {
				for (int j = 0;j < X;j++) {
					int S = 0;
					double add = 0.0;

					if (i - 1 >= 0) {
						S++;
						i--;

						if (i - 2 >= 0) {
							S++;
							i--;

							if (j - 1 >= 0) {
								S++;
								j--;
								add += alpha[i * X + j];
								j++;
							}
							S++;
							add += alpha[i * X + j];
							if (j + 1 < X) {
								S++;
								j++;
								add += alpha[i * X + j];
								j--;
							}
							i++;
						}

						if (j - 1 >= 0) {
							S++;
							j--;
							add += alpha[i * X + j];
							j++;
						}
						S++;
						add += alpha[i * X + j];
						if (j + 1 < X) {
							S++;
							j++;
							add += alpha[i * X + j];
							j--;
						}
						i++;
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (j - 1 >= 0) {
						S++;
						j--;

						if (j - 2 >= 0) {
							S++;
							j--;

							if (i - 1 >= 0) {
								S++;
								i--;
								add += alpha[i * X + j];
								i++;
							}
							S++;
							add += alpha[i * X + j];
							if (i + 1 < Y) {
								S++;
								i++;
								add += alpha[i * X + j];
								i--;
							}
							j++;
						}

						add += alpha[i * X + j];
						j++;
					}
					S++;
					add += alpha[i * X + j];
					if (j + 1 < X) {
						S++;
						j++;

						if (j + 2 < X) {
							S++;
							j++;

							if (i - 1 >= 0) {
								S++;
								i--;
								add += alpha[i * X + j];
								i++;
							}
							S++;
							add += alpha[i * X + j];
							if (i + 1 < Y) {
								S++;
								i++;
								add += alpha[i * X + j];
								i--;
							}
							j--;
						}

						add += alpha[i * X + j];
						j--;
					}
					//æææææææææææææææææææææææææææææææææææææææææææææææææææ
					if (i + 1 < Y) {
						S++;
						i++;

						if (i + 2 < Y) {
							S++;
							i++;

							if (j - 1 >= 0) {
								S++;
								j--;
								add += alpha[i * X + j];
								j++;
							}
							S++;
							add += alpha[i * X + j];
							if (j + 1 < X) {
								S++;
								j++;
								add += alpha[i * X + j];
								j--;
							}
							i--;
						}

						if (j - 1 >= 0) {
							S++;
							j--;
							add += alpha[i * X + j];
							j++;
						}
						S++;
						add += alpha[i * X + j];
						if (j + 1 < X) {
							S++;
							j++;
							add += alpha[i * X + j];
							j--;
						}
						i--;
					}

					map[i * X + j] += pow(pow(add, 1) / pow(S, 1), 1);
				}
			}
		}

		mx = float(-INFINITY);
		mn = float(INFINITY);
		for (int i = 0;i < Y;i++) {
			for (int j = 0;j < X;j++) {
				mx = max(mx, map[i * X + j]);
				mn = min(mn, map[i * X + j]);
			}
		}
		for (int i = 0;i < Y;i++)
			for (int j = 0;j < X;j++)
				map[i * X + j] = float(map[i * X + j] - mn) / float(mx - mn);


	}

	delete[] alpha;
	return map;
}

