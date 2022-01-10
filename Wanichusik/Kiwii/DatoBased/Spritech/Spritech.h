#pragma once
#include "../Deep/Deep.h"
#include <Windows.h>
#include <stdio.h>

namespace Kiwii {
	class Spritech : public Deep {
        //if there are pointers,
        //then on each pointer need one boolean
        //(ask, if decleared, with class, when it hasn't got not empty constructor) 

        typedef char SYM;

        ///////pointers////////
        SYM** _visual;

        ////others variables///
        uint16_t _width;
        uint16_t _height;

        uint16_t _pos_x;
        uint16_t _pos_y;

        bool _have_void = false;

        ///////pointers////////
        bool is_decleared = false;

    public:
        //////constructor//////
        Spritech(){}

        //////get and set//////
        void setup(uint16_t width, uint16_t height, bool have_void = true) {

        }

        ////////virtual////////

        ///////override////////
        void _info_r(std::string _name_r) override;

        /////special func//////
        


        void unsetup() {
            for (uint16_t i = 0;i < _width;i++) delete[] _visual[i];
            delete[] _visual;
        }

        ///////destructor//////
        ~Spritech() { 
            unsetup();
        }

    };
}