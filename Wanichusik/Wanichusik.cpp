#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>

int main() {
	Kiwii_Experiments::mapf as = Kiwii_Experiments::Perlin(15, 15);

	for (int i = 0;i < 15;i++) {
		for (int j = 0;j < 15;j++)
			std::cout  << as[i * 15 + j]  <<  '\t' ;
		std::cout << '\n';
	}

	delete[] as;

	return 0;
}