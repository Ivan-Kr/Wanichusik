#pragma once
#include "Kiwii.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>

void SetWindow(int Width, int Height);

namespace kiwii {
	class ScreenText {
	protected:
		WORD WIDTH;
		WORD HEIGHT;
		HANDLE HCONSOLE;
		DWORD DWBYTESWRITTEN = 0;

		double ASPECT;

		wchar_t* SCREEN;

		int SQUARE() {
			return WIDTH * HEIGHT;
		}
	public:

		ScreenText(WORD Width, WORD Height);

		WORD Width() {
			return WIDTH;
		}
		WORD Height() {
			return HEIGHT;
		}
		HANDLE hConsole() {
			return HCONSOLE;
		}

		wchar_t Screen(int index);
		void Screen(int index, wchar_t val);

		void Comment(int length,const wchar_t*const format) {
			swprintf_s(SCREEN, length, format);
		}

		double Aspect() {
			return ASPECT;
		}

		void Out() {
			WriteConsoleOutputCharacterW(HCONSOLE, SCREEN, SQUARE(), { 0, 0 }, &DWBYTESWRITTEN);
		}

		~ScreenText() {
			delete[] SCREEN;
		}
	};
}
