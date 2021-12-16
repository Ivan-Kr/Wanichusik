//#include "Kiwii/Universalius/UniversaliusKit.h"
//#include "Kiwii/MonoText/MonoTextKit.h"
#include "Kiwii/DatoBased/Deep.h"
#include <iostream>
//#include <Windows.h>
//#include <stdio.h>
//#include <math.h>
//#include <string>
//#include <future>

int main(){
	/*
	srand(time(NULL));
	kiwii::monotext::ScreenText ai;

	ai.Name(L"UX");

	change_font(8,16);

	float font_ = 8.0f / 16.0f;
	ai.SetupS(90,30);
	//ai.Fill(L' ');
	//ai.ImportL(L"Kiwii/_Hash/Gradient1 GradientText.txt");

	for (int t = 0;t < 5000;t++) {
		for (int j = 0;j < ai.Height();j++) {
			for (int i = 0;i < ai.Width();i++) {
				
				float x = (float)i / ai.Width() * 2.0f - 1.0f;
				float y = (float)j / ai.Height() * 2.0f - 1.0f;
				x *= ai.Aspect() * font_;

				x += sin(t * 0.01f);

				wchar_t a = L' ';
				if (x * x + y * y < 0.5f)
					a = L'#';
				ai.ScreenP(i, j, a);
				

			}
		}
		ai.Out();

	}
	ai.Info();
	*/

	Deep a;
	a.name("Kiwii");
	a.info("first deep");

	return 0;
}
