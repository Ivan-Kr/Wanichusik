#pragma once

#include ".\Math.h"
#include ".\Screen.h"
#include ".\Time Act.h"
#include <conio.h>

#define Size_Screen_X 1280
#define Size_Screen_Y 1024
#define Font_X 14
#define Font_Y 7
namespace Kiwii {
	namespace universalius {
		class Snake {
			vec2<int16_t> size;
			std::vector<vec2<int16_t>> snake;
			std::vector<vec2<uint16_t>> fruit;
			std::vector<std::vector<wchar_t>> screen;
			std::chrono::system_clock::time_point end, begin;
			bool need_fps = 0, need_wall = 1, is_lost = 0;
			char ch = 'w';
		public:
			Snake(uint16_t nFruits, bool need_fps, bool need_wall) {
				size.x = Size_Screen_X / Font_X;
				size.y = Size_Screen_Y / Font_Y;

				snake.push_back(size);
				snake[0].x /= 2;
				snake[0].y /= 2;

				fruit = reserve_vector(fruit, nFruits);
				for (int i = 0;i < fruit.size();i++) {
					fruit[i].x = Rand size.x;
					fruit[i].y = Rand size.y;
				}

				screen = reserve_vector(screen, size.x, size.y);


				this->need_wall = need_wall;
				this->need_fps = need_fps;

			}

			bool islost() {
				return this->is_lost;
			}

			~Snake() {}

			void input() {
				if (need_fps)
					begin = std::chrono::system_clock::now();
				if (_kbhit()) {
#pragma warning(suppress : 4996)
					ch = getch();

				}
			}

			void move() {
				if (!is_lost)
				{
					//first we need move tail in next position
					{
						for (int i = snake.size() - 1;i > 0;i--) {
							snake[i] = snake[i - 1];
						}
					}
					//then we need move
					switch (ch) {
					case (char)'w':
						snake[0].y--;
						break;
					case (char)'a':
						snake[0].x--;
						break;
					case (char)'s':
						snake[0].y++;
						break;
					case (char)'d':
						snake[0].x++;
						break;
					}
				}
			}

			void logic() {
				if (!is_lost)
				{
					if (need_wall) {
						if ((size.x <= snake[0].x || snake[0].x < 0 || size.y <= snake[0].y || snake[0].y < 0)) {
							wprintf(L"> Your snake was stuck, its length was %d cm\n", snake.size());
							std::cin.get();
							is_lost = 1;
						}
					}
					else {
						if ((size.x <= snake[0].x))
							snake[0].x = 0;
						if ((snake[0].x < 0))
							snake[0].x = size.x - 1;
						if ((size.y <= snake[0].y))
							snake[0].y = 0;
						if ((snake[0].y < 0))
							snake[0].y = size.y - 1;
					}

					if ((screen[snake[0].x][snake[0].y] == L'o') || ch == 'x') {
						wprintf(L"> Your snake was stuck, its length was %d cm\n", snake.size());
						std::cin.get();
						is_lost = 1;
					}

					//and finally we check, is snake in fruit
					if (screen[snake[0].x][snake[0].y] == L'X') {
						for (int i = 0;i < fruit.size();i++) {
							if ((fruit[i].x == snake[0].x) && (fruit[i].y == snake[0].y)) {
								snake.push_back(snake[snake.size() - 1]);

								int s = 0;
								do {
									s++;
									fruit[i].x = Rand size.x;
									fruit[i].y = Rand size.y;
									if (s == 10)
										break;
								} while (screen[fruit[i].x][fruit[i].y] != L'.');
								break;
							}
						}
					}
				}
			}

			void output(uint16_t wait) {
				if (!is_lost)
				{
					//first write in screen void
					for (int j = 0;j < size.y;j++) for (int i = 0;i < size.x;i++) screen[i][j] = L'.';
					//write in screen all needly values
					for (int i = 0;i < fruit.size();i++) {
						screen[fruit[i].x][fruit[i].y] = L'X';
					}

					for (int i = 0;i < snake.size();i++) {
						if (i == 0) screen[snake[i].x][snake[i].y] = L'O';
						else screen[snake[i].x][snake[i].y] = L'o';
					}



					//out in console
					_wsystem(L"cls");
					std::wstring stroke = L"";

					stroke = L"";
					for (int i = 0;i < size.y;i++) {

						for (int j = 0;j < size.x;j++) stroke += screen[j][i];
						stroke += '\n';
					}
					wprintf(L"%s\n", stroke.c_str());

					wprintf(L"length : %d cm\t", snake.size());

					if (wait != 0) {
						//std::cin.get();
						Sleep(wait);
					}
					if (need_fps) {
						std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

						time_rps(begin, end);
					}
				}
			}

		};
	}
}
