#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>


int main() {
	Kiwii_Experiments::mapf as = Kiwii_Experiments::Perlin(5, 5);

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++)
			std::cout<<std::hex<<uint16_t(as[i * 5 + j]);
		std::cout << '\n';
	}

	delete[] as;

	return 0;
}