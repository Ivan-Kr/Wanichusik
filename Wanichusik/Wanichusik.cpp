#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>

int main() {
	//srand(time(NULL));
	int x=150, y=120;

	Kiwii_Experiments::mapf as = Kiwii_Experiments::Perlin(x, y);

	for (int i = 0;i < y;i++) {
		for (int j = 0;j < x;j++)
			//std::cout << as[i * x + j]<<'\t';
			if (as[i * x + j] < 0.2) std::cout << ' ';
			else if (as[i * x + j] < 0.4) std::cout << char(176);
			else if (as[i * x + j] < 0.6) std::cout << char(177);
			else if (as[i * x + j] < 0.8) std::cout << char(178);
			else std::cout << char(219);
		std::cout << '\n';
	}

	delete[] as;
	std::cin.get();
	return 0;
}