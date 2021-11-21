#pragma once
#include "Kiwii.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

namespace kiwii {

	int Normalize(int val, int maxx, int minn) {
		return min(max(val, minn), maxx);
	}

	class ScreenText {
		WORD WIDTH;
		WORD HEIGHT;
		HANDLE HCONSOLE;
		DWORD DWBYTESWRITTEN = 0;

		double ASPECT;

		wchar_t* SCREEN;
	public:
		ScreenText(WORD Width, WORD Height) {
			WIDTH = Width;
			HEIGHT = Height;

			SetWindow(WIDTH, HEIGHT);

			HCONSOLE = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			SetConsoleActiveScreenBuffer(HCONSOLE);

			ASPECT = WIDTH / HEIGHT;

			SCREEN = new wchar_t[WIDTH * HEIGHT + 1];
			SCREEN[WIDTH * HEIGHT] = L'\0';
		}

		WORD Width() {
			return WIDTH;
		}
		WORD Height() {
			return HEIGHT;
		}

		wchar_t Screen(int index) {
			if (!(index < 0 || index >= WIDTH * HEIGHT))
				return SCREEN[index];
		}
		void Screen(int index, wchar_t val) {
			if (!(index < 0 || index >= WIDTH * HEIGHT))
				SCREEN[index] = val;
		}

		void Comment(int length,const wchar_t*const format) {
			swprintf_s(SCREEN, length, format);
		}

		double Aspect() {
			return ASPECT;
		}

		void Out() {
			WriteConsoleOutputCharacterW(HCONSOLE, SCREEN, WIDTH * HEIGHT, { 0, 0 }, &DWBYTESWRITTEN);
		}

		~ScreenText() {
			delete[] SCREEN;
		}
	};
}