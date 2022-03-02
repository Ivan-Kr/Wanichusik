#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>

int main() {
	Kiwii_Experiments::Exper_0 A(30);


	Kiwii::Screench uv;
	uv.setup(120, 90);

	for (int t = 0;t < 0xfff;t++) {

		if (GetAsyncKeyState(VK_ESCAPE)) break;

		A.logic_actmove();
		A.logic_action();
		A.logic_death();
		A.write();

		for (int i = 0;i < 90;i++) {
			for (int j = 0;j < 120;j++) {
				if (A.mappp[i * 120 + j] == '.') {
					if (A.sunnn[i * 120 + j] < 0.2)
						uv.set_screen(j, i, ' ');
					else if (A.sunnn[i * 120 + j] < 0.4)
						uv.set_screen(j, i, char(176));
					else if (A.sunnn[i * 120 + j] < 0.6)
						uv.set_screen(j, i, char(177));
					else if (A.sunnn[i * 120 + j] < 0.8)
						uv.set_screen(j, i, char(178));
					else uv.set_screen(j, i, char(219));
				}
				else uv.set_screen(j, i, A.mappp[i * 120 + j]);
			}
			uv.insert_hex<int>(120*90-1, t);

			uv.print();
		}
	}
	return 0;
}