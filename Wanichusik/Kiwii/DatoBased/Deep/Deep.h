#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>

#define max(a,b)(a<b?b:a)
#define min(a,b)(a<b?a:b)

#define ios_reading std::ios::in
#define ios_writing std::ios::out

namespace Kiwii {
	static char get_hex(unsigned char what,bool num) {
		if (!num) {
			if (what % 16 == 0) return '0';
			else if (what % 16 == 1)  return '1';
			else if (what % 16 == 2)  return '2';
			else if (what % 16 == 3)  return '3';
			else if (what % 16 == 4)  return '4';
			else if (what % 16 == 5)  return '5';
			else if (what % 16 == 6)  return '6';
			else if (what % 16 == 7)  return '7';
			else if (what % 16 == 8)  return '8';
			else if (what % 16 == 9)  return '9';
			else if (what % 16 == 10) return 'A';
			else if (what % 16 == 11) return 'B';
			else if (what % 16 == 12) return 'C';
			else if (what % 16 == 13) return 'D';
			else if (what % 16 == 14) return 'E';
			else return 'F';
		}
		else {
			if (what / 16 == 0) return '0';
			else if (what / 16 == 1)  return '1';
			else if (what / 16 == 2)  return '2';
			else if (what / 16 == 3)  return '3';
			else if (what / 16 == 4)  return '4';
			else if (what / 16 == 5)  return '5';
			else if (what / 16 == 6)  return '6';
			else if (what / 16 == 7)  return '7';
			else if (what / 16 == 8)  return '8';
			else if (what / 16 == 9)  return '9';
			else if (what / 16 == 10) return 'A';
			else if (what / 16 == 11) return 'B';
			else if (what / 16 == 12) return 'C';
			else if (what / 16 == 13) return 'D';
			else if (what / 16 == 14) return 'E';
			else return 'F';
		}
	}

	template<typename _Ty>
	static _Ty fix(_Ty num, _Ty mn, _Ty mx) { return max(min(num,(mx - 1)),mn); }

	class Deep {
	protected:
		std::string _name;
		bool _pointer;
	public:
		
		virtual void _info_r(std::string _name_r) = 0;

		std::string _name_r() { return _name; }
		void _name_r(std::string namee) { _name = namee; }
	};

}
