#include "Kiwii/GradientText.h"
#include "Kiwii/ShaderText.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <future>

int main(){
	srand(time(NULL));
	kiwii::GradientText ai;
	kiwii::ShaderText* shader;



	float font_ = 7.0f / 14.0f;
	ai.SetupS(90, 30);
	ai.Setup();
	ai.Fill(L' ');
	ai.ImportL(L"Kiwii/Hash/Gradient1 GradientText.txt");
	shader->Connect(ai);
	for (int t = 0;t < 500000;t++) {

		for (int j = 0;j < ai.Height();j++) {
			for (int i = 0;i < ai.Width();i++) {
				float x = (float)i / ai.Width()*2.0f-1.0f;
				float y = (float)j / ai.Height() * 2.0f - 1.0f;
				x *= ai.Aspect() * font_;

				x += sin(t * 0.001f);

				wchar_t a = L' ';
				if (x * x + y * y < 0.5f)
					a = L'#';
				ai.ScreenP(i, j, a);
			

			}
		}
		shader->Color((unsigned __int8)0x34);
		ai.Out();

	}

	delete shader;
	return 0;
}
