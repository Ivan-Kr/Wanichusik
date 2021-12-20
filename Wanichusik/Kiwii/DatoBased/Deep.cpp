#include "Deep.h"

void Kiwii::Deep::info(std::string name) {
	std::ofstream file("./Kiwii/DatoBased/Info/" + name + ".txt", std::ios::out);
	file << "Info in \"" << name << ".txt\"\n";
	//////////////////////////

	file << "\t" << "_pointer" << " = " << &_pointer << "\n";
	file << "\t" << "_name" << " = " << _name << "\n";

	//////////////////////////
	file.close();
}
