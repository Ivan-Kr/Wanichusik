#include "Kiwii/DatoBased/Simulation/Experiment #0/Exp0 - Main.h"
#include "Kiwii/DatoBased/Screench/Screench.h"
#include "Kiwii/DatoBased/Simulation/_Template/_temp.h"
#include <iostream>

int main() {
	int x = 120;
	int y = 90;
	Kiwii_Experiments::Exper_2 E(Kiwii::vec2(x, y));
	Kiwii::Screench uv;
	uv.setup(x, y);

	uint64_t t = 0;
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) { break; Sleep(100); }
		if (GetAsyncKeyState(' ')) { 
			Kiwii::vec2 a(rand()%x, rand() % y), b(rand() % x, rand() % y);
			E.Segment(Kiwii::segment(a,b)); 
			Sleep(10); 
		}


		uv.copy(E.scr);
		uv.insert_hex(x * y - 1, t);
		uv.print();
		t++;
	}

	return 0;
}