#include "Kiwii/ScreenText.h"
#include "Kiwii/Math.h"
#include "Kiwii/GradientText.h"
#include "Kiwii/Music.h"
#include "Kiwii/Kiwii.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <future>

int main(){
	srand(time(NULL));
	Kiwii d;
	d._random(45);
	kiwii::GradientText ai;
	ai.SetupS(90, 30);
	ai.Setup();
	ai.ImportO(L"Kiwii/Hash/Gradient1 GradientText.txt");

	for (int t = 0;t < 500000;t++) {
		for (int i = 0;i < ai.SQUARE();i++) {
			ai.Brightness(i, (int)(sin(t*i)*2));
			ai.BrightnessDiff(i, d._random());
		}
		ai.Paint();
		ai.Out();
	}
	return 0;
}
/*
map     shader  .
movement        import  .
made_perlin     .       .
scaling_screen  .       .

*/