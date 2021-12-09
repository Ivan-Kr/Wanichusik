#include "Kiwii/Universalius/UniversaliusKit.h"
#include "Kiwii/MonoText/MonoTextKit.h"
#include <iostream>
//#include <Windows.h>
//#include <stdio.h>
//#include <math.h>
//#include <string>
//#include <future>

int main(){
	/*
	srand(time(NULL));
	kiwii::ScreenText ai;

	change_font(4,8);

	float font_ = 4.0f / 8.0f;
	ai.SetupS(320,120);
	//ai.Fill(L' ');
	//ai.ImportL(L"Kiwii/Hash/Gradient1 GradientText.txt");

	for (int t = 0;t < 500000;t++) {
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
	*/

	kiwii::monotext::Memory a;

	a.Name(L"Sub");
	a.Info();

	kiwii::monotext::Memory b;

	//b.Name(L"Sub");
	b.Info();

	std::cout << &a;

	return 0;
}
