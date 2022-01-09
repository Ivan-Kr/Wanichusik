#pragma once
#include <string>
#include <fstream>

#define max(a,b)(a<b?b:a)
#define min(a,b)(a<b?a:b)

namespace Kiwii {
	template<typename _Ty>
	static _Ty fix_int(_Ty num, _Ty mn, _Ty mx) {
		return max(min(num,(mx - 1)),mn);
	}

	class Deep {
	protected:
		std::string _name;
		bool _pointer;

		template<typename _Ty>
		void WriteOneSym(std::ofstream file, std::string name, _Ty what) {
			if (file.is_open()) file << '\t' << name << " : " << what << "\n";
		}
		void WriteOneChar(std::ofstream file, std::string name, char what);
		void WriteOneString(std::ofstream file, std::string name, const char* what);
		void WriteOneWString(std::ofstream file, std::string name, const wchar_t* what);

		template<typename _Ty>
		void WriteAnySym(std::ofstream file, std::string name, _Ty* what,size_t size) {
			if (file.is_open()) {
				file << "\t" << name<< " : [\n";
				for (size_t i = 0;i < size;i++) {
					file << "\t\t" << what[i];
					if (i != size - 1) file << ",\n";
					else file << '\n';
				}
				file << "\t]\n";
			}
		}
		void WriteAnyChar(std::ofstream file, std::string name, char* what, size_t size);
		void WriteAnyString(std::ofstream file, std::string name, const char** what, size_t size);
		void WriteAnyWString(std::ofstream file, std::string name, const wchar_t** what, size_t size);
	public:
		void setup();

		virtual void _info_r(std::string _name_r);

		std::string _name_r() {
			return _name;
		}
		void _name_r(std::string namee) {
			_name = namee;
		}

		void unsetup();
	};

}
