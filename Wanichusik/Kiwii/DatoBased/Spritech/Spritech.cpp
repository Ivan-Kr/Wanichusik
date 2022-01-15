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
    std::ifstream file(way, std::ios::in);

    uint16_t setted_strokes = 0;
    while (file) {
        std::string str;
        file >> str;
        for (uint16_t i = 0;i < _width||i<str.size();i++) {
            _sprite[i][setted_strokes]=str[i];
        }
    }
}
