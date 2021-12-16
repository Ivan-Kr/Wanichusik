#pragma once
#include <string>
#include <fstream>
class Deep {
protected:
	std::string _name;
	bool _pointer;
public:
	virtual void info(std::string name) {
		std::ofstream file("./Kiwii/DatoBased/Info/" + name + ".txt",std::ios::out);
		file << "Info in \"" << name << ".txt\"\n";
		//////////////////////////

		file << "\t" << "_pointer" << " = " << &_pointer << "\n";
		file << "\t" << "_name" << " = " << _name << "\n";
		
		//////////////////////////
		file.close();
	}

	std::string name() {
		return _name;
	}
	void name(std::string namee) {
		_name = namee;
	}


};

