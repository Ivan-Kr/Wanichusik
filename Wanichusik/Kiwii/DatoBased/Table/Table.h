#pragma once
#include "../Deep/Deep.h"

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
        unsigned int _sx;
        unsigned int _sy;

        ///////pointers////////
        bool _is_decleared = false;

    public:
        //////constructor//////
        Table(){}
        void setup(unsigned int x, unsigned int y) {
            _is_decleared = true;

            _sx = x;
            _sy = y;

            _table = new _Ty*[_sx];

            for (unsigned int i = 0;i < _sx;i++) {
                _table[i] = new _Ty[_sy];
            }
        }

        //////get and set//////
        void table(unsigned int x, unsigned int y, _Ty what) {
            if (_is_decleared) {

                if (x < _sx && y < _sy) {
                    _table[x][y] = what;
                }

            }

        }
        _Ty table(unsigned int x, unsigned int y) {
            if (_is_decleared) {

                if (x < _sx && y < _sy) {
                    return _table[x][y];
                }
                else {
                    return _Ty();
                }

            }
            else {
                return _Ty();
            }
        }

        ////////virtual////////
        ///////override////////
        /////special func//////

        void fill(_Ty what) {
            if (_is_decleared) {

                for (unsigned int i = 0;i < _sx;i++) {
                    for (unsigned int j = 0;j < _sy;j++) {
                        _table[i][j] = what;
                    }
                }

            }
        }
        void add(_Ty what) {
            if (_is_decleared) {

                for (unsigned int i = 0;i < _sx;i++) {
                    for (unsigned int j = 0;j < _sy;j++) {
                        _table[i][j] += what;
                    }
                }

            }
        }

        ///////destructor//////
        void reset_table() {
            if (_is_decleared) {
                for (unsigned int i = 0;i < _sx;i++) {
                    delete[] _table[i];
                }

                delete[] _table;

                _sx = NULL;
                _sy = NULL;


                _table = nullptr;
                _is_decleared = false;
            }
        }
        ~Table() { 
            reset_table();
        }

    };
}
