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
		WORD _width;
		WORD _height;
		HANDLE _hconsole;
		DWORD _dwbyteswritten = 0;

		double _aspect;

		wchar_t* _screen;


	public:
		int SQUARE() {
			return _width * _height;
		}
		virtual void Setup();

		void SetupS(WORD Width, WORD Height);

		WORD Width() {
			return _width;
		}
		WORD Height() {
			return _height;
		}
		HANDLE hConsole() {
			return _hconsole;
		}

		wchar_t ScreenL(int index);
		void ScreenL(int index, wchar_t val);
		wchar_t ScreenP(int x,int y);
		void ScreenP(int x, int y, wchar_t val);

		void Comment(int length,const wchar_t*const format) {
			swprintf_s(_screen, length, format);
		}

		double Aspect() {
			return _aspect;
		}

		void Fill(wchar_t val);

		void Out() {
			WriteConsoleOutputCharacterW(_hconsole, _screen, SQUARE(), { 0, 0 }, &_dwbyteswritten);
		}

		~ScreenText() {
			delete[] _screen;
		}
	};
}
