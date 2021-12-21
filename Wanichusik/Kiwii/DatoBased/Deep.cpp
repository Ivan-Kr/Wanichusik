#include "Deep.h"

void Kiwii::Deep::_info_r(std::string _name_r) {
	std::ofstream file("./Kiwii/DatoBased/Info/" + _name_r + ".txt", std::ios::out);
	file << "Info in \"" << _name_r << ".txt\"\n";
	//////////////////////////

	file << "\t" << "_pointer" << " : " << &_pointer << "\n";
	file << "\t" << "_name" << " : " << _name << "\n";

	//////////////////////////
	file.close();
}
