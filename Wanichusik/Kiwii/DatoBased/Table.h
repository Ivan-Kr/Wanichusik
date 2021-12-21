#pragma once
#include "Deep.h"

namespace Kiwii {
    template<typename _Ty>
    class Table :
        public Deep
    {
        //if there are pointers,
        //then on each pointer need one boolean
        //(ask, if decleared, with class, when it hasn't got not empty constructor) 

        ///////pointers////////
        _Ty** _table = nullptr;

        ////others variables///
        unsigned int _sx = NULL;
        unsigned int _sy = NULL;

        ///////pointers////////
        bool _is_decleared = false;

    public:
        //////constructor//////
        Table(){}
        void set_table(unsigned int x, unsigned int y);

        //////get and set//////
        void table(unsigned int x, unsigned int y, _Ty what);
        _Ty table(unsigned int x, unsigned int y);



        ////////virtual////////
        ///////override////////
        void _info_r(std::string _name_r) override {
            std::ofstream file("./Kiwii/DatoBased/Info/" + _name_r + ".txt", std::ios::out);
            file << "Info in \"" << _name_r << ".txt\"\n";
            //////////////////////////

            file << "\t" << "_pointer" << " : " << &_pointer << "\n";
            file << "\t" << "_name" << " : " << _name << "\n";

            if (_is_decleared) {
                file << "\t" << "_table" << ": [\n";
                for (int i = 0;i < _sx;i++) {
                    file << "\t[\n";
                    for (int j = 0;j < _sy;j++) {
                        file << "\t\t" << _table;

                        if (j != _sy - 1) {
                            file << ", ";
                        }
                    }
                    if (i != _sx - 1) {
                        file << ",\n\t\t[";
                    }
                }
            }

            //////////////////////////
            file.close();
        }

        /////special func//////

        void fill(_Ty what);
        void add(_Ty what);

        ///////destructor//////
        void reset_table();
        ~Table() { 
            reset_table();
        }

    };
}
