#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctime>
#include <chrono>

#define max(a,b)(a<b?b:a)
#define min(a,b)(a<b?a:b)

namespace Kiwii {
	template<typename _Ty>
	static _Ty fix(_Ty num, _Ty mn, _Ty mx) {
		return max(min(num,(mx - 1)),mn);
	}

	class Deep {
	protected:
		std::string _name;
		bool _pointer;
	public:
		
		virtual void _info_r(std::string _name_r) = 0;

		std::string _name_r() {
			return _name;
		}
		void _name_r(std::string namee) {
			_name = namee;
		}
	};

}
