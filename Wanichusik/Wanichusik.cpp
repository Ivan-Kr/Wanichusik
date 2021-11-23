#include "Kiwii/ScreenText.h"
#include "Kiwii/Math.h"
#include "Kiwii/GradientText.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <future>

int main(){
	srand(time(NULL));
	
	kiwii::GradientText ai;
	ai.SetupS(90, 30);

	ai.Setup();
	ai.Import(L"Kiwii/Hash/Gradient1 GradientText.txt");
	for (int i = 0;i < 500000;i++) {
		for (int i = 0;i < ai.SQUARE();i++) {
			ai.Brightness(i, rand());
		}

		ai.Out();
	}
	return 0;
}
