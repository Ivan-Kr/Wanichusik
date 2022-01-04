#pragma once
#include "../Deep/Deep.h"
#include <Windows.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <chrono>

namespace Kiwii {
    static void SO_set_window(int Width, int Height) {
        _COORD coord;
        coord.X = Width;
        coord.Y = Height;
        _SMALL_RECT Rect;
        Rect.Top = 0;
        Rect.Left = 0;
        Rect.Bottom = Height - 1;
        Rect.Right = Width - 1;
        HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleScreenBufferSize(Handle, coord);
        SetConsoleWindowInfo(Handle, TRUE, &Rect);
    }

    static void SO_change_font(short x, short y) {
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(cfi);
        cfi.nFont = 0;
        cfi.dwFontSize.X = x;                   // Width of each character in the font
        cfi.dwFontSize.Y = y;                  // Height
        cfi.FontFamily = FF_DONTCARE;
        cfi.FontWeight = FW_NORMAL;
#pragma warning(suppress : 4996)
        wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }

	class Screench : public Deep {
        //if there are pointers,
        //then on each pointer need one boolean
        //(ask, if decleared, with class, when it hasn't got not empty constructor) 

        typedef char SYM;

        ///////pointers////////
        SYM* _screen;

        ////others variables///
        uint16_t _width;
        uint16_t _height;
        HANDLE _hconsole;
        DWORD _dwbyteswritten = 0;

        double _aspect = NULL;

        ///////pointers////////
        bool is_decleared = false;

    public:
        //////constructor//////
        Screench(){}

        //////get and set//////
        void setup(uint16_t width, uint16_t height, bool need_adapt = true);
        double get_aspect() { return _aspect; }
        uint32_t get_square() { return _width*_height; }
        HANDLE get_handle() { return _hconsole; }
        uint16_t get_width() { return _width; }
        uint16_t get_height() { return _height; }
        SYM screen(uint16_t x, uint16_t y) {
            if (is_decleared)
                return _screen[(x < _width ? x : _width - 1) + (y < _height ? y : _height - 1) * _width];
        }
        SYM screen(uint32_t ind) {
            if (is_decleared)
                return _screen[ind < get_square() ? ind : get_square() - 1];
        }
        void screen(uint16_t x, uint16_t y, SYM what) {
            if (is_decleared)
                _screen[(x < _width ? x : _width - 1) + (y < _height ? y : _height - 1) * _width] = what;
        }
        void screen(uint32_t ind, SYM what) {
            if (is_decleared)
                _screen[ind < get_square() ? ind : get_square() - 1] = what;
        }

        ////////virtual////////

        ///////override////////
        void _info_r(std::string _name_r) override;

        /////special func//////
        
        void print() {
            if(is_decleared) WriteConsoleOutputCharacterA(_hconsole, _screen, get_square(), { 0,0 }, &_dwbyteswritten);
        }

        void reset_screen() {
            delete[] _screen;
        }

        ///////destructor//////
        ~Screench() { reset_screen(); }

    };
}