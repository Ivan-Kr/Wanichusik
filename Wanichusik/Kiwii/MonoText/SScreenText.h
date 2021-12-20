#pragma once
#include "Kiwii.h"
#include "Foot.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <vector>


namespace Kiwii {
	namespace monotext {
		class SScreenText : public KiwiI {
		protected:
			WORD _width;
			WORD _height;
			HANDLE _hconsole;
			DWORD _dwbyteswritten = 0;

			double _aspect;

			std::vector<wchar_t> _screen;


		public:
			int Square() {
				return _width * _height;
			}
			virtual void Setup() {};

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
			wchar_t ScreenP(int x, int y);
			void ScreenP(int x, int y, wchar_t val);

			void Comment(int length, const wchar_t* const format) {
				wchar_t* comment = new wchar_t[length];
				swprintf_s(comment, length, format);
				for (int i = 0;i < length;i++)_screen[i] = comment[i];
				delete[] comment;
			}

			double Aspect() {
				return _aspect;
			}

			void Fill(wchar_t val);

			void Out() {
				wchar_t* scr = new wchar_t[_width * _height + 1];
				scr[_width * _height] = L'\0';
				for (int i = 0;i < _width * _height;i++)_screen[i] = scr[i];
				WriteConsoleOutputCharacterW(_hconsole, scr, Square(), { 0, 0 }, &_dwbyteswritten);
				delete[] scr;
			}
		};
	}
}
