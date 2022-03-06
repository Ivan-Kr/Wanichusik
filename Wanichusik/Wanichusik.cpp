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

	Kiwii::vec2 a(0),b(1);

	uint64_t t = 0;
	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		if (GetAsyncKeyState('W')) {
			a.Y--;
		}
		if (GetAsyncKeyState('A')) {
			a.X--;
		}
		if (GetAsyncKeyState('S')) {
			a.Y++;
		}
		if (GetAsyncKeyState('D')) {
			a.X++;
		}
		if (GetAsyncKeyState(VK_UP)) {
			b.Y--;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			b.X--;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			b.Y++;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			b.X++;
		}
		if (GetAsyncKeyState(' ')) { 
			E.Segment(a.X,a.Y,b.X,b.Y,1); 
		}

		uv.copy(E.scr);

		uv.set_screen(Kiwii::fix<int>(a.X + x * a.Y, 0, x * y),'+');
		uv.set_screen(Kiwii::fix<int>(b.X + x * b.Y, 0, x * y), '+');

		uv.insert_hex(x * y - 1, t);
		uv.print();
		Sleep(33);
		t++;
	}

	return 0;
}