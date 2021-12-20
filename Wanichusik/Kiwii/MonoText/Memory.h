#pragma once
#include <string>
#include <fstream>

//class of control memory and process
namespace Kiwii {
	namespace monotext {
		class Memory
		{
		protected:
			bool pointer;
			std::wstring _name = L"[null]";
		public:
			void Name(std::wstring name) {
				_name = name;
			}
			std::wstring Name() {
				return _name;
			}

			virtual void Info() {
				std::wifstream Version(L"Kiwii/MonoText/Report/Num.txt", std::ios::in);

				if (!Version.is_open()) {
					Version.close();
					exit(3);
				}
				else {
					unsigned int Num = 0;
					Version >> Num;
					//////////////////////////////

					std::wofstream In(L"Kiwii/MonoText/Report/Report Memory #" + std::to_wstring(Num) + L".txt", std::ios::out);
					In << "Report #" << Num << '\n';

					In << '\t' << "pointer" << " = " << std::hex << &pointer << '\n';
					In << '\t' << "_name" << " = " << _name << '\n';

					//////////////////////////////
					Version.close();
					std::wofstream Vers(L"Kiwii/MonoText/Report/Num.txt", std::ios::out);
					Vers << Num + 1 << '\n';
					Vers.close();

				}


			}
		};
	}
}
