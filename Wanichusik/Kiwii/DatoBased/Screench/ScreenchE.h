#pragma once
#include "Screench.h"
#include <Windows.h>
#include <stdio.h>
#include <utility>
#include <algorithm>

namespace Kiwii {
	class ScreenchE : public Deep {
        typedef char SYM;

        Screench uv;

        uint64_t t = 0;
        double microsec = 0.0;
        TIME_POINT beg = NOW, end = NOW;

        bool debug = false;
        bool pause = true;
        bool work = true;
    public:
        ScreenchE() {} 
        
        void setup(uint16_t x, uint16_t y){
            uv.setup(x, y);
        }
        void key_action() {
            if (work) {
                if (GetAsyncKeyState(VK_ESCAPE)) { work = false; }
                if (GetAsyncKeyState(VK_SPACE)) { pause = !pause; Sleep(75); }
                if (GetAsyncKeyState(VK_F10)) { debug = !debug; Sleep(75); }
            }
        }

        uint16_t get_X() { return uv.get_width(); }
        uint16_t get_Y() { return uv.get_height(); }
        uint64_t get_t() { return t; }
        bool is_work() { return work; }
        bool is_pause() { return pause; }
        bool is_debug() { return debug; }
        void set_screen(uint16_t x, uint16_t y, SYM what) {
            uv.set_screen(x, y, what);
        }
        void set_screen(uint16_t ind, SYM what) {
            uv.set_screen(ind, what);
        }
        SYM get_screen(uint16_t x, uint16_t y) {
            return uv.get_screen(x, y);
        }
        SYM get_screen(uint16_t ind) {
            return uv.get_screen(ind);
        }

        void _info_r(std::string _name_r) override {}

        void print_action() {
            end = NOW;
            microsec += double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - beg).count()) / 100.0;

            if (debug) {

                int x = uv.get_width();
                int y = uv.get_height();

                for (int i = x * y - 1;i >= x * y - x - x;i--)uv.set_screen(i, ' ');

                uv.insert_dec(x * y - x / 2 + 5, uint16_t(uint16_t(microsec / 1000.0) % 1000));
                uv.insert_dec(x * y - x / 2 + 1, uint8_t(uint8_t(microsec / 10000000.0) % 60));
                uv.insert_dec(x * y - x / 2 - 2, uint8_t(uint8_t(microsec / 600000000.0) % 60));
                uv.insert_dec(x * y - x / 2 - 5, uint8_t(uint8_t(microsec / 36000000000.0) % 24));
                uv.insert_dec(x * y - x / 2 - 8, uint8_t(uint8_t(microsec / 864000000000.0)));
                uv.set_screen(x * y - x / 2 + 2, '.');
                uv.set_screen(x * y - x / 2 - 1, ':');
                uv.set_screen(x * y - x / 2 - 4, ':');
                uv.set_screen(x * y - x / 2 - 7, ' ');
                uv.insert_dec(x * y - x + 4, uint16_t(1000000 / (std::chrono::duration_cast<std::chrono::microseconds>(end - beg).count())));
                uv.insert_hex(x * y - 1, t);
            }

            beg = NOW;

            uv.print();
            if (!pause) t++;

            Sleep(1);
        }

        ~ScreenchE(){}
    };
}
