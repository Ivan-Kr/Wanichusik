#include "Kiwii/Screen.h"
#include "Kiwii/Music.h"
#include "Kiwii/Time Act.h"
#include <string>

BYTE noise(WORD x, WORD y, BYTE val) {
	BYTE vl = Rand 4;
	switch (vl) {
	case 0:	return 0x00;
	case 1:	return 0x88;
	case 2:	return 0x77;
	case 3:	return 0xff;
	}

}

double timer = 0;
int main(int args,char* argv[])
{
	printf("%s\n",argv[0]);
	//is_sound(L".\\Pocket\\Introduce.wav");

	srand(time(NULL));

	scene a;

	double rps=0;
	TIME_POINT end=NOW_T, beg=NOW_T;
	for (int i = 0;i < 128;i++) {
		beg = NOW_T;
		system("cls");
		a.write_modific_scene(20, 20, true,noise);
		Sleep(rps);
		end = NOW_T;
		a.write_comment(
			"Renders = \t" + std::to_string(i) + " iter\n"+
			"Speed render = \t" + std::to_string(time_rps_g(beg, end)) + " RPS\n"+
			"Delay = \t" + std::to_string(1000 / time_rps_g(beg, end)) + " ms\n"+
			"Timer = \t" + std::to_string(timer) + " s\n" +
			"Avrg render = \t" + std::to_string(i/ timer) + " RPS"
		);
		timer += 1 / time_rps_g(beg, end);

		//rps = time_rps_g(beg, end)*5;

	}
	system("pause");

	return 0;
}