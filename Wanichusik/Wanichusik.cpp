#include "Kiwii/MonoText/GradientText.h"
#include "Kiwii/MonoText/SScreenText.h"
#include "Kiwii/Universalius/Math.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <future>

int main(){
	srand(time(NULL));
	kiwii::GradientText ai;
	kiwii::ScreenText ux;


	ux.SetupS(90, 30);
	float font_ = 7.0f / 14.0f;
	ai.SetupS(90, 30);
	ai.Setup();
	ai.Fill(L' ');
	ai.ImportL(L"Kiwii/Hash/Gradient1 GradientText.txt");

	for (int t = 0;t < 500000;t++) {

		for (int j = 0;j < ai.Height();j++) {
			for (int i = 0;i < ai.Width();i++) {
				
				float x = (float)i / ai.Width() * 2.0f - 1.0f;
				float y = (float)j / ai.Height() * 2.0f - 1.0f;
				x *= ai.Aspect() * font_;

				y -= t * 0.0005f* t * 0.0005f;

				wchar_t a = L' ';
				if (((x * x < 0.25f) && ( y * y < 0.25f)))
					a = L'#';
				ai.ScreenP(i, j, a);
				

			}
		}
		ai.Out();

	}

	return 0;
}
