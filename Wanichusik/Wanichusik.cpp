#pragma once
#include "Kiwii/ScreenText.h"
#include "Kiwii/Math.h"
#include "Kiwii/Music.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <future>

int main(){
	srand(time(NULL));

	kiwii::ScreenText ux(90, 30);

	kiwii::vec2<double> round{};
	float pixelAspect = 11.0f / 24.0f;

	std::future<void> a=std::async(kiwii::play_test_song);

	a;

	for (int t = 0;t < 2000000;t++) {
		for (int j = 0;j < ux.Height();j++) {
			for (int i = 0;i < ux.Width();i++) {


				round.x = (double)i / ux.Width() * 2 - 1;
				round.y = (double)j / ux.Height() * 2 - 1;

				round.x *= ux.Aspect() * pixelAspect;

				round.x += sin((double)t * 0.005);
				round.y += cos((double)t * 0.005);

				wchar_t pixel = L' ';
				if ((round.x * round.x + round.y * round.y) < 0.25) pixel = L'#';
				ux.Screen(i + j * ux.Width(), pixel);
			}
		}
		std::wstring s = L"Kiwii x = " + std::to_wstring(round.x);
		s += L" y = " + std::to_wstring(round.y);
		ux.Comment(35, s.c_str());
		ux.Out();
	}

	return 0;
}
