#include "Table.h"

template<typename _Ty>
void Kiwii::Table<_Ty>::set_table(unsigned int x, unsigned int y) {
    _is_decleared = true;

    _sx = x;
    _sy = y;

    _table = new _Ty[_sx];

    for (unsigned int i = 0;i < _sx;i++) {
        _table[i] = new _Ty[_sy];
    }

    return;
}

template<typename _Ty>
void Kiwii::Table<_Ty>::table(unsigned int x, unsigned int y, _Ty what) {
    if (_is_decleared) {

        if (x < _sx && y < _sy) {
            _table[x][y] = what;
        }

    }
    return;
}

template<typename _Ty>
_Ty Kiwii::Table<_Ty>::table(unsigned int x, unsigned int y) {
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

template<typename _Ty>
void Kiwii::Table<_Ty>::fill(_Ty what) {
    if (_is_decleared) {

        for (unsigned int i = 0;i < _sx;i++) {
            for (unsigned int j = 0;j < _sy;j++) {
                _table[i][j] = what;
            }
        }

    }
    return;
}

template<typename _Ty>
void Kiwii::Table<_Ty>::add(_Ty what) {
    if (_is_decleared) {

        for (unsigned int i = 0;i < _sx;i++) {
            for (unsigned int j = 0;j < _sy;j++) {
                _table[i][j] += what;
            }
        }

    }
    
    return;
}

template<typename _Ty>
void Kiwii::Table<_Ty>::reset_table() {
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

    return;
}
