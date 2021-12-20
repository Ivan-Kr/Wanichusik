#pragma once
/*include*/
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>

/*define*/
#define temp template
namespace Kiwii {
	namespace universalius {
		using QWORD = unsigned long long;
		using DWORD = unsigned long;
		using WORD = unsigned short;
		using BYTE = unsigned char;

		class file_t {
		private:
			std::ifstream Out;
			std::ofstream In;
			std::string directive, insert;
			QWORD siz;
			bool is_opened = 0;

			void check_dir(std::string directive = "") {
				if (directive != "")
					this->directive = directive;
			}
			bool check_open(std::ios_base::open_mode _mode) {
				if (_mode == std::ios::in || _mode == std::ios::app) {
					In.open(this->directive, _mode);
					if (!In.is_open()) return 0;
					else return 1;
				}
				else {
					Out.open(this->directive, _mode);
					if (!Out.is_open()) return 0;
					else return 1;
				}
			}
		public:
			file_t() {
				siz = sizeof(file_t);
			}
			QWORD size() {
				return siz;
			}
			bool is_openn() {
				return is_opened;
			}

			void open(std::string directive, std::ios_base::open_mode _mode) {
				check_dir(directive);
				if (check_open(_mode))
					is_opened = true;
			}

			std::string write(DWORD n_str) {
				if (!is_opened)  return " ";

				while (Out && n_str > 0) {
					std::getline(Out, insert);
					n_str--;
				}

				return insert;
			}

			std::string get_insert() {
				if (is_opened)
					return insert;
			}

			std::string write_all(std::string directive = "") {
				check_dir(directive);
				if (!is_opened) return " ";

				std::string s;

				while (Out) {
					std::getline(Out, s);
					insert += s + "\n";
				}

				return insert;
			}

			void out() {
				printf("%s", insert.c_str());
			}

			void create() {

				In.open(this->directive);
			}

			temp<typename T>
				void input(T val) {
				check_dir(directive);
				if (!is_opened) { return; }

				In << val;
			}

			void close() {
				In.close();
				Out.close();
			}

			~file_t() {
				close();
			}
		};

		class wfile_t {
		private:
			std::wifstream Out;
			std::wofstream In;
			std::wstring directive, insert;
			QWORD siz;
			bool is_opened = 0;

			void check_dir(std::wstring directive = L"") {
				if (directive != L"")
					this->directive = directive;
			}
			bool check_open(std::ios_base::open_mode _mode) {
				if (_mode == std::ios::in || _mode == std::ios::app) {
					In.open(this->directive, _mode);
					if (!In.is_open()) return 0;
					else return 1;
				}
				else {
					Out.open(this->directive, _mode);
					if (!Out.is_open()) return 0;
					else return 1;
				}
			}
		public:
			wfile_t() {
				siz = sizeof(file_t);
			}
			QWORD size() {
				return siz;
			}
			bool is_openn() {
				return is_opened;
			}

			void open(std::wstring directive, std::ios_base::open_mode _mode) {
				check_dir(directive);
				if (check_open(_mode))
					is_opened = true;
			}

			std::wstring write(DWORD n_str) {
				if (!is_opened)  return L" ";

				while (Out && n_str > 0) {
					std::getline(Out, insert);
					n_str--;
				}

				return insert;
			}

			std::wstring get_insert() {
				if (is_opened)
					return insert;
			}

			std::wstring write_all(std::wstring directive = L"") {
				check_dir(directive);
				if (!is_opened) return L" ";

				std::wstring s;

				while (Out) {

					std::getline(Out, s);
					insert += s + L"\n";
				}

				return insert;
			}

			void out() {
				printf("%s", insert.c_str());
			}

			void create() {

				In.open(this->directive);
			}

			temp<typename T>
				void input(T val) {
				check_dir(directive);
				if (!is_opened) { return; }

				In << val;
			}

			void close() {
				In.close();
				Out.close();
			}

			~wfile_t() {
				close();
			}
		};

		class wayfile {
		private:
			std::string waay = "";
			bool haveDisc = 0;
			bool haveFile = 0;
		public:
			std::string way() {
				return waay;
			}

			void set_disk(char type) {
				haveDisc = 1;
				waay += type;
				waay += ":\\";
			}

			void add_folder(std::string folder_way) {
				if (haveDisc)
					waay += folder_way + "\\";
			}

			void set_file(std::string file_name, const char format[4]) {
				if (haveDisc)
					waay += file_name + "." + format;
				haveFile = 1;
			}

			void way(std::string _way) {
				waay = _way;
			}

			bool check_way() {
				if (haveDisc && haveFile)
					return 1;
				else
					return 0;
			}

			void launch_way() {
				if (haveDisc && haveFile)
					system((waay.c_str()));
			}
		};

		class wayfilew {
		private:
			std::wstring waay = L"";
			bool haveDisc = 0;
			bool haveFile = 0;
		public:
			std::wstring way() {
				return waay;
			}

			void set_disk(char type) {
				haveDisc = 1;
				waay += type;
				waay += L":\\";
			}

			void add_folder(std::wstring folder_way) {
				if (haveDisc)
					waay += folder_way + L"\\";
			}

			void set_file(std::wstring file_name, const wchar_t format[4]) {
				if (haveDisc) {
					waay += file_name + L"." + format;
					haveFile = 1;
				}
			}

			void way(std::wstring _way) {
				waay = _way;
			}

			bool check_way() {
				if (haveDisc && haveFile)
					return 1;
				else
					return 0;
			}

			void launch_way() {
				if (haveDisc && haveFile)
					_wsystem(waay.c_str());

			}
		};
	}
}
