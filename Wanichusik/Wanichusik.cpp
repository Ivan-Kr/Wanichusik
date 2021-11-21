#pragma once
#include "Kiwii/ScreenText.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>

int main(){
	kiwii::ScreenText ux(90, 30);

	float pixelAspect = 11.0f / 24.0f;

	for (int t = 0;t < 2000000;t++) {
		for (int j = 0;j < ux.Height();j++) {
			for (int i = 0;i < ux.Width();i++) {

				double x = (double)i / ux.Width() * 2 - 1;
				double y = (double)j / ux.Height() * 2 - 1;

				x *= ux.Aspect() * pixelAspect;

				x += sin((double)t * 0.001);

				wchar_t pixel = L' ';
				if ((x * x + y * y) < 0.5) pixel = L'#';
				ux.Screen(i + j * ux.Width(), pixel);
			}
		}
		ux.Out();
	}

	return 0;
}
