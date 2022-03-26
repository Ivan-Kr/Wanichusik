#pragma once
#include "../Deep/Deep.h"
#include <vector>

namespace Kiwii {
	class Spritech : public Deep {
        //if there are pointers,
        //then on each pointer need one boolean
        //(ask, if decleared, with class, when it hasn't got not empty constructor) 

        typedef char SYM;

        ///////pointers////////
        SYM* _sprite;

        ////others variables///
        uint16_t _width=0;
        uint16_t _height=0;

        int16_t _pos_x=0;
        int16_t _pos_y=0;

        bool _need_show = false;

        bool _have_void = false;

        ///////pointers////////
        bool is_decleared = false;

    public:
        //////constructor//////
        Spritech(){}

        //////get and set//////
        void setup(uint16_t width, uint16_t height, bool have_void = true) {
            _width = width;
            _height = height;
            
            _sprite = new SYM[_width * _height];

            is_decleared = true;
        }

        int16_t get_pos_x() { return _pos_x; }
        int16_t get_pos_y() { return _pos_y; }
        void set_pos_x(int16_t pos_x) { _pos_x = pos_x; }
        void set_pos_y(int16_t pos_y) { _pos_y = pos_y; }

        uint16_t get_height() { return _height; }
        uint16_t get_width() { return _width; }

        SYM get_sprite(uint16_t x, uint16_t y) {
            return _sprite[fix<uint16_t>(x, 0, _width) + fix<uint16_t>(y, 0, _height) * _width];
        }
        void set_sprite(uint16_t x, uint16_t y,SYM sprite) {
            _sprite[fix<uint16_t>(x, 0, _width) + fix<uint16_t>(y, 0, _height) * _width] = sprite;
        }

        ////////virtual////////

        ///////override////////
        void _info_r(std::string _name_r) override;

        /////special func//////
        
        void unsetup() {
            if (is_decleared) {
                delete _sprite;

                is_decleared = false;
            }
        }

        ///////destructor//////
        ~Spritech() { 
            unsetup();
        }

    };
}