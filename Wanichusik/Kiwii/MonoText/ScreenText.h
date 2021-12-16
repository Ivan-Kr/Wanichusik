#pragma once
#include "Memory.h"
#include "Kiwii.h"
#include "Foot.h"
//#include <iostream>
#include <stdio.h>

namespace kiwii {
	namespace monotext {
		class ScreenText : public Kiwii, public Memory
		{
		protected:
			WORD _width;
			WORD _height;
			HANDLE _hconsole;
			DWORD _dwbyteswritten = 0;

			double _aspect;

			wchar_t* _screen;


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
				swprintf_s(_screen, length, format);
			}

			double Aspect() {
				return _aspect;
			}

			void Fill(wchar_t val);

			void Out() {
				WriteConsoleOutputCharacterW(_hconsole, _screen, Square(), { 0, 0 }, &_dwbyteswritten);
			}

			void Info()override {
				std::wifstream Version(L"Kiwii/MonoText/Report/Num.txt", std::ios::in);

				if (!Version.is_open()) {
					Version.close();
					exit(3);
				}
				else {
					unsigned int Num = 0;
					Version >> Num;
					//////////////////////////////

					std::wofstream In(L"Kiwii/MonoText/Report/Report ScreenText #" + std::to_wstring(Num) + L".txt", std::ios::out);
					In << "Report #" << Num << '\n';

					In << '\t' << "pointer" << " = " << std::hex << &pointer << '\n';
					In << '\t' << "_name" << " = " << _name << '\n';
					In << '\t' << "_width" << " = " << _width << '\n';
					In << '\t' << "_height" << " = " << _height << '\n';
					In << '\t' << "_hconsole" << " = " << _hconsole << '\n';
					In << '\t' << "_dwbyteswritten" << " = " << _dwbyteswritten << '\n';
					In << '\t' << "_aspect" << " = " << _aspect << '\n';

					for (int i = 0;i < Square();i++) {
						In << '\t' << "_screen"<<"["<<i<<"]" << " = " <<'\'' << _screen[i] << '\'' << '\n';
					}

					//////////////////////////////
					Version.close();
					std::wofstream Vers(L"Kiwii/MonoText/Report/Num.txt", std::ios::out);
					Vers << Num + 1 << '\n';
					Vers.close();

				}


			}

			~ScreenText() {
				delete[] _screen;
			}
		};
	}
}
