#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>


int main() {
	Kiwii::Massive_Exp<uint8_t> a(5, 5);
	int d[1] = { 1 };
	Kiwii_Experiment::Perlin(a, 1, d, 0);

	for (int i = 0;i < a.get_y();i++) {
		for (int j = 0;j < a.get_x();j++) {
			if (a.get_mas(j,i) < 51.2)
				std::cout << ' ';
			else if (a.get_mas(j, i) < 51.2 * 2)
				std::cout << char(176);
			else if (a.get_mas(j, i) < 51.2 * 3)
				std::cout << char(177);
			else if (a.get_mas(j, i) < 51.2 * 4)
				std::cout << char(178);
			else std::cout << char(219);
		}
		std::cout << '\n';
	}

	return 0;
}