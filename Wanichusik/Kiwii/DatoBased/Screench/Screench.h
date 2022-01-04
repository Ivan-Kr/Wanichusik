#pragma once
#include "../Deep/Deep.h"
#include <Windows.h>
#include <stdio.h>

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

        ///////pointers////////
        char* _screen;

        ////others variables///
        WORD _width;
        WORD _height;
        HANDLE _hconsole;
        DWORD _dwbyteswritten = 0;

        double _aspect;

        ///////pointers////////
        bool is_decleared = false;

    public:
        //////constructor//////
        Screench(){}

        //////get and set//////
        void set_screen(WORD width, WORD height, bool need_adapt = false);
        
        ////////virtual////////
        
        ///////override////////
        
        /////special func//////
        

        ///////destructor//////
        ~Screench(){}

    };
}