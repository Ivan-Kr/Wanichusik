/*pragma*/
#pragma once
/*include*/
#include ".\Screen.h"
#include "Kiwii.h"

/*define*/
#define temp template
#define Rand rand()%
#define SetAtr SetConsoleTextAttribute

using QWORD = unsigned long long;
using DWORD = unsigned long;
using WORD = unsigned short;
using BYTE = unsigned char;

/*main*/
namespace kiwii {
	int _random(int proc) {
		int W = Rand proc;
		int E = (proc / 2);
		W -= E;

		return W;
	}

	temp<typename T>
		T* copy_array(T* from_arr, T* to_arr, uint32_t count) {

		for (uint32_t i = 0;i < count;i++) {
			to_arr[i] = from_arr[i];
		}

		return to_arr;
	}
	temp<typename T>
		T* copy_array(T* from_arr, T* to_arr, uint32_t count_i, uint32_t count_j) {

		for (uint32_t i = 0;i < count_i;i++) {
			for (uint32_t j = 0;j < count_j;j++) {
				to_arr[i][j] = from_arr[i][j];
			}
		}

		return to_arr;
	}


	////////////////////////////////



	namespace link {
		std::wstring way_to_browser;

		class link_site {
		private:
			std::wstring linkk = L"";
		public:
			std::wstring way() {
				return linkk;
			}

			void way(std::wstring _way) {
				linkk = _way;
			}

			void launch_link() {
				std::wstring stroke = way_to_browser;
				stroke += L" ";
				stroke += linkk.c_str();
				_wsystem(stroke.c_str());
			}
		};
	}
}


           