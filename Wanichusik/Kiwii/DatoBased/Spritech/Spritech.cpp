#include "Spritech.h"

void Kiwii::Spritech::_info_r(std::string _name_r) {
    std::ofstream file("./Kiwii/DatoBased/Info/" + _name_r + ".txt", std::ios::out);
    file << "Info in \"" << _name_r << ".txt\"\n";
    //////////////////////////

    file << "\t" << "_pointer" << " : " << &_pointer << "\n";
    file << "\t" << "_name" << " : " << _name << "\n";

    //////////////////////////
    file.close();
}

void Kiwii::Spritech::load(std::string way) {
    std::ifstream file(way, ios_reading);

    for (uint16_t s = 0;file || s < _height - 1;s++) {
        std::string str;
        std::getline(file, str);
        for (uint16_t i = 0;i < _width||i<str.size();i++) {
            if((0<i||i<_width)&&(0 < s || s < _height))
                _sprite[
                    i
                ][
                    s
                ] = str[
                    i<str.size()?i:str.size()
                ];
        }
    }
    file.close();
}
