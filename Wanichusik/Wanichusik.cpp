#include "Kiwii/DatoBased/Simulation/Experiment #0/Exper_0.h"
#include "Kiwii/DatoBased/Screench/ScreenchE.h"
#include <iostream>

int main() {
	Kiwii::ScreenchE S;

	S.setup(90, 30);

	while (S.is_work()) {
		S.key_action();

		if (!S.is_pause()) {
			for (int i = 0; i < S.get_X() * S.get_Y();i++)S.set_screen(i, rand());
		}


		S.print_action();
	}

	return 0;
}