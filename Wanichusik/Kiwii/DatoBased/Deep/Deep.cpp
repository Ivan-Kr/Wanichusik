#include "Deep.h"
void Kiwii::Deep::WriteOneChar(std::ofstream file, std::string name, char what) {
	if (file.is_open()) {
		file << '\t' << name << " : '" << what << "'\n";
	}
}
void Kiwii::Deep::WriteOneString(std::ofstream file, std::string name, const char* what) {
	if (file.is_open()) {
		file << '\t' << name << " : \"" << what << "\"\n";
	}
}
void Kiwii::Deep::WriteOneWString(std::ofstream file, std::string name, const wchar_t* what) {
	if (file.is_open()) {
		file << '\t' << name << " : L\"" << what << "\"\n";
	}
}

void Kiwii::Deep::WriteAnyChar(std::ofstream file, std::string name, char* what, size_t size) {
	if (file.is_open()) {
		file << "\t" << name << " : [\n";
		for (size_t i = 0;i < size;i++) {
			file << "\t\t'" << what[i] << '\'';
			if (i != size - 1) file << ",\n";
			else file << '\n';
		}
		file << "\t]\n";
	}
}
void Kiwii::Deep::WriteAnyString(std::ofstream file, std::string name, const char** what, size_t size) {
	if (file.is_open()) {
		file << "\t" << name << " : [\n";
		for (size_t i = 0;i < size;i++) {
			file << "\t\t\"" << what[i] << "\"";
			if (i != size - 1) file << ",\n";
			else file << '\n';
		}
		file << "\t]\n";
	}
}
void Kiwii::Deep::WriteAnyWString(std::ofstream file, std::string name, const wchar_t** what, size_t size) {
	if (file.is_open()) {
		file << "\t" << name << " : [\n";
		for (size_t i = 0;i < size;i++) {
			file << "\t\tL\"" << what[i] << "\"";
			if (i != size - 1) file << ",\n";
			else file << '\n';
		}
		file << "\t]\n";
	}
}

void Kiwii::Deep::_info_r(std::string _name_r) {
	std::ofstream file("./Kiwii/DatoBased/Info/" + _name_r + ".txt", std::ios::out);
	file << "Info in \"" << _name_r << ".txt\"\n";
	//////////////////////////

	file << "\t" << "_pointer" << " : " << &_pointer << "\n";
	file << "\t" << "_name" << " : " << _name << "\n";

	//////////////////////////
	file.close();
}
