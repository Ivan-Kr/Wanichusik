#pragma once
#include "Kiwii/ScreenText.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>


int main(){
	//setup
	ScreenText ux(90,30);

	float pixelAspect = 11.0f / 24.0f;

	//cycle
	for (int t = 0;t < 2000000;t++) {
		for (int j = 0;j < ux._height();j++) {
			for (int i = 0;i < ux._width();i++) {

				double x = (double)i / ux._width() *2-1;
				double y = (double)j / ux._height() *2-1;

				x *= ux._aspect()* pixelAspect;

				x += sin(t);

				wchar_t pixel = L' ';
				if ((x * x + y * y) < 0.5) pixel = L'#';
				ux.write(x, y, pixel);
			}
		}
		ux.out();
	}

	ux.~ScreenText();
	return 0;
}
