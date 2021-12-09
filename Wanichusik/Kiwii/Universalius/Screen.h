#pragma once

/*include*/
#include ".\Math.h"
#include ".\Explorer.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <map>
#include <functional>

/*define*/
#define Rand rand()%
#define SetAtr SetConsoleTextAttribute
#define elif else if

#define turncmd wincon_convert
#define resvec reserve_vector
#define copyvec copy_vector
#define show_win ShowWindow(::GetConsoleWindow(), SW_SHOW)
#define hide_win ShowWindow(::GetConsoleWindow(), SW_HIDE)

#define vec std::vector
namespace kiwii {
	namespace universalius {
		using QWORD = unsigned long long;
		using DWORD = unsigned long;
		using WORD = unsigned short;
		using BYTE = unsigned char;

		int _random(int proc) {
			int W = Rand proc;
			int E = (proc / 2);
			W -= E;

			return W;
		}

		/*screen*/

		typedef char TEXT;

		BYTE wincon_convert(BYTE r, BYTE g, BYTE b) {
			std::map<BYTE, BYTE>win_console_col_list = {
				{0,0x0},{1,0x11},{2,0x22},{3,0x33},{4,0x44},
				{5,0x55},{6,0x66},{7,0x77},{8,0x88},{9,0x99},
				{0xa,0xaa},{0xb,0xbb},{0xc,0xcc},{0xd,0xdd},{0xe,0xee},
				{0xf,0xff}
			};
			std::map<BYTE, BYTE>win_console_text_list = {
				{0,0x09},{1,0x1f},{2,0x2a},{3,0x3b},{4,0x4c},
				{5,0x5d},{6,0x6e},{7,0x78},{8,0x87},{9,0x90},
				{0xa,0xa2},{0xb,0xb3},{0xc,0xc4},{0xd,0xd5},{0xe,0xe6},
				{0xf,0xf1}
			};

			if (r == 0x00 && g == 0x00 && b == 0x00)  return 0xfe;
			elif(r == 0x0f && g == 0x0f && b == 0x0f) return win_console_col_list[0];
			elif(r == 0x00 && g == 0x00 && b == 0x80) return win_console_col_list[1];
			elif(r == 0x00 && g == 0x80 && b == 0x00) return win_console_col_list[2];
			elif(r == 0x00 && g == 0x80 && b == 0x80) return win_console_col_list[3];
			elif(r == 0x80 && g == 0x00 && b == 0x00) return win_console_col_list[4];
			elif(r == 0x80 && g == 0x00 && b == 0x80) return win_console_col_list[5];
			elif(r == 0x80 && g == 0x80 && b == 0x00) return win_console_col_list[6];
			elif(r == 0xc0 && g == 0xc0 && b == 0xc0) return win_console_col_list[7];
			elif(r == 0x80 && g == 0x80 && b == 0x80) return win_console_col_list[8];
			elif(r == 0x00 && g == 0x00 && b == 0xff) return win_console_col_list[9];
			elif(r == 0x00 && g == 0xff && b == 0x00) return win_console_col_list[10];
			elif(r == 0x00 && g == 0xff && b == 0xff) return win_console_col_list[11];
			elif(r == 0xff && g == 0x00 && b == 0x00) return win_console_col_list[12];
			elif(r == 0xff && g == 0x00 && b == 0xff) return win_console_col_list[13];
			elif(r == 0xff && g == 0xff && b == 0x00) return win_console_col_list[14];
			elif(r == 0xff && g == 0xff && b == 0xff) return win_console_col_list[15];

			elif(r == 0x2f && g == 0x2f && b == 0x2f) return win_console_text_list[0];
			elif(r == 0x2f && g == 0x2f && b == 0xaf) return win_console_text_list[1];
			elif(r == 0x2f && g == 0xaf && b == 0x2f) return win_console_text_list[2];
			elif(r == 0x2f && g == 0xaf && b == 0xaf) return win_console_text_list[3];
			elif(r == 0xaf && g == 0x2f && b == 0x2f) return win_console_text_list[4];
			elif(r == 0xaf && g == 0x2f && b == 0xaf) return win_console_text_list[5];
			elif(r == 0xaf && g == 0xaf && b == 0x2f) return win_console_text_list[6];
			elif(r == 0xdf && g == 0xdf && b == 0xdf) return win_console_text_list[7];
			elif(r == 0xaf && g == 0xaf && b == 0xaf) return win_console_text_list[8];
			elif(r == 0x2f && g == 0x2f && b == 0xef) return win_console_text_list[9];
			elif(r == 0x2f && g == 0xef && b == 0x2f) return win_console_text_list[10];
			elif(r == 0x2f && g == 0xef && b == 0xef) return win_console_text_list[11];
			elif(r == 0xef && g == 0x2f && b == 0x2f) return win_console_text_list[12];
			elif(r == 0xef && g == 0x2f && b == 0xef) return win_console_text_list[13];
			elif(r == 0xef && g == 0xef && b == 0x2f) return win_console_text_list[14];
			elif(r == 0xef && g == 0xef && b == 0xef) return win_console_text_list[15];
			else return 0xfe;
		}

		temp<typename T>
			vec<T> reserve_vector(vec<T> Vec, DWORD size) {
			Vec.reserve(size);
			Vec.resize(size);
			return Vec;
		}
		temp<typename T>
			vec<vec<T>> reserve_vector(vec<vec<T>> Vec, DWORD size_x, DWORD size_y) {
			Vec.reserve(size_x);
			Vec.resize(size_x);
			for (BYTE i = 0;i < size_x;i++) {
				Vec[i].reserve(size_y);
				Vec[i].resize(size_y);
			}
			return Vec;
		}
		temp<typename T>
			vec<T> copy_vector(vec<T> from_arr, vec<T> to_arr, uint32_t count) {

			for (uint32_t i = 0;i < count;i++) {
				to_arr[i] = from_arr[i];
			}

			return to_arr;
		}
		temp<typename T>
			vec<vec<T>> copy_vector(vec<vec<T>> from_arr, vec<vec<T>>to_arr, uint32_t count_i, uint32_t count_j) {

			for (uint32_t i = 0;i < count_i;i++) {
				for (uint32_t j = 0;j < count_j;j++) {
					to_arr[i][j] = from_arr[i][j];
				}
			}

			return to_arr;
		}

		class boxic {
		private:
			vec2<BYTE> Size;
			vec2<WORD> Position;

			vec<vec<BYTE>> Picture;
			vec<vec<TEXT>> Text;
		public:

			BYTE& _size(char pos) {
				if (pos == 'x')
					return Size.x;
				elif(pos == 'y')
					return Size.y;
			}
			WORD& _position(char pos) {
				if (pos == 'x')
					return Position.x;
				elif(pos == 'y')
					return Position.y;
			}
			void _position(char pos, BYTE value) {
				if (pos == 'x')
					Position.x = value;
				else if (pos == 'y')
					Position.y = value;
			}
			void _positioo(WORD x, WORD y) {
				Position.x = x;
				Position.y = y;
			}
			BYTE& _picture(BYTE x, BYTE y) {
				return Picture[x][y];
			}
			void _picture(BYTE x, BYTE y, BYTE value) {
				Picture[x][y] = value;
			}
			TEXT& _text(BYTE x, BYTE y) {
				return Text[x][y];
			}
			void _text(BYTE x, BYTE y, TEXT value) {
				Text[x][y] = value;
			}

			boxic(BYTE size_x = 0, BYTE size_y = 0) {
				set_size(size_x, size_y);
			}

			void set_size(BYTE size_x = 0, BYTE size_y = 0) {
				Size.x = size_x;
				Size.y = size_y;
				if (!(Size.x == 0 || Size.y == 0)) {

					Picture = resvec(Picture, Size.x, Size.y);
					Text = resvec(Text, Size.x, Size.y);
				}

			}
			void import(std::string dir) {
				file_t file;
				file.open(dir, std::ios::out);

				int R = 0;
				int G = 0;
				int B = 0;
				if (file.is_openn()) {
					file.write(5);
					for (int i = 0;i < Size.x * Size.y;i++) {

						R = stoi(file.get_insert());
						file.write(1);
						G = stoi(file.get_insert());
						file.write(1);
						B = stoi(file.get_insert());
						Picture[i % Size.x][i / Size.x] = wincon_convert(R, G, B);
						file.write(1);
					}
				}
				file.close();
			}

			void fill_image(BYTE charr) {
				for (BYTE j = 0;j < Size.y;j++)
					for (BYTE i = 0;i < Size.x;i++)
						Picture[i][j] = charr;
			}
			void fill_text(TEXT charr) {
				for (BYTE j = 0;j < Size.y;j++)
					for (BYTE i = 0;i < Size.x;i++)
						Text[i][j] = charr;
			}

			void test_image() {
				for (int i = 0;i < Size.y;i++) {
					for (int j = 0;j < Size.x;j++) {

						if (Picture[j][i] == 0xfe) {
							SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), wincon_convert(128, 128, 128));
							printf("#");
						}
						else {
							SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), Picture[j][i]);
							printf("#");
						}
					}
					if (i + 1 != Size.y) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}

				}
				printf("\n");
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			void test_sprite() {
				for (int i = 0;i < Size.y;i++) {
					for (int j = 0;j < Size.x;j++) {

						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), Picture[j][i]);
						if (sizeof(TEXT) == 1)
							putchar(Text[j][i]);
						if (sizeof(TEXT) == 2)
							putwchar(Text[j][i]);
					}
					if (i + 1 != Size.y) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}

				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			void test_image_without_endl() {
				for (int i = 0;i < Size.y;i++) {
					for (int j = 0;j < Size.x;j++) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), Picture[j][i]);
						printf("#");
					}
					if (i + 1 != Size.y) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						//printf("\n");
					}

				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}

			void mirror(bool by_x) {
				std::vector<std::vector<BYTE>> PicBuf;
				std::vector<std::vector<TEXT>> TexBuf;
				PicBuf = reserve_vector(PicBuf, Picture.size(), Picture[0].size());
				TexBuf = reserve_vector(TexBuf, Text.size(), Text[0].size());

				if (by_x) {
					for (int i = 0;i < Size.x;i++) {
						for (int j = 0;j < Size.y;j++) {
							PicBuf[i][j] = Picture[Size.x - i - 1][j];
							TexBuf[i][j] = Text[Size.y - j - 1][j];
						}

					}
				}
				else {
					for (int i = 0;i < Size.x;i++) {
						for (int j = 0;j < Size.y;j++) {
							PicBuf[i][j] = Picture[i][Size.y - j - 1];
							TexBuf[i][j] = Text[i][Size.y - j - 1];
						}

					}
				}
				Picture = copy_vector(PicBuf, Picture, Size.x, Size.y);
				Text = copy_vector(TexBuf, Text, Size.x, Size.y);

			}
			void rotate() {
				if (Size.x != 0) {
					if (Size.x == Size.y) {
						std::vector<std::vector<BYTE>> PicBuf;
						std::vector<std::vector<TEXT>> TexBuf;
						PicBuf = resvec(PicBuf, Picture.size(), Picture[0].size());
						TexBuf = resvec(TexBuf, Text.size(), Text[0].size());

						for (int j = 0;j < Size.y;j++) {
							for (int i = 0;i < Size.x;i++) {
								PicBuf[i][j] = Picture[j][Size.x - i - 1];
								TexBuf[i][j] = Text[j][Size.x - i - 1];
							}
						}
						Picture = copy_vector(PicBuf, Picture, Size.x, Size.y);
						Text = copy_vector(TexBuf, Text, Size.x, Size.y);
					}
				}
			}

			~boxic() {
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			}
		};

		class scene {
			std::string Comment;
			BYTE duration_shake = 0;
		public:
			vec<boxic> obj;

			void write_comment(std::string Comment) {
				this->Comment = Comment;
			}

			vec<int[2]> check_collision() {
				vec<int[2]> token_col;

				for (int i = 0;i < obj.size();i++) {
					for (int j = 0;j < obj.size();j++) {
						auto iXp = obj[i]._position('x');
						auto jXp = obj[j]._position('x');
						auto iYp = obj[i]._position('y');
						auto jYp = obj[j]._position('y');
						auto iXs = obj[i]._size('x');
						auto jXs = obj[j]._size('x');
						auto iYs = obj[i]._size('y');
						auto jYs = obj[j]._size('y');

						int ind[2] = { i,j };

						if (iXp <= jXp && iYp <= jYp)
							if (iXp + iXs > jXp && iYp + iYs > jYp) {}
					}

				}

				return token_col;
			}

			void write_graph(WORD size_scr_X, WORD size_scr_Y, bool need_comment, std::function<double(int)> func, BYTE end_clr = 7) {

				BYTE* scr_col = new BYTE[size_scr_X * size_scr_Y];

				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_col[i] = 0x00;

				for (int i = 0;i < size_scr_X;i++) {
					if (((int)(func(i) * (size_scr_X * 1.0f))) + i < size_scr_X * size_scr_Y && ((int)(func(i) * (size_scr_X * 1.5f))) + i >= 0) {
						scr_col[((int)(func(i) * (size_scr_X * 1.0f))) + i] = 0xcc;
					}
				}

				for (int is = 0;is < size_scr_X * size_scr_Y;is++) {
					SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), scr_col[is]);
					putchar(' ');
					if ((is + 1) % size_scr_X == 0 && is != 0) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}
				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), end_clr);
				if (need_comment) {
					printf("%s\n", this->Comment.c_str());
				}
				delete[] scr_col;
			}

			void write_scene(WORD size_scr_X, WORD size_scr_Y, bool need_comment, BYTE end_clr = 7) {

				BYTE* scr_col = new BYTE[size_scr_X * size_scr_Y];
				TEXT* scr_text = new TEXT[size_scr_X * size_scr_Y];

				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_col[i] = 0x00;
				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_text[i] = (TEXT)' ';

				for (int i = 0;i < this->obj.size();i++) {

					auto Xp = obj[i]._position('x');
					auto Yp = obj[i]._position('y');

					auto Xs = obj[i]._size('x');
					auto Ys = obj[i]._size('y');

					int Pos = (Yp * size_scr_X) + Xp;

					for (int is = 0;is < Ys;is++) {
						for (int js = 0;js < Xs;js++) {
							if (obj[i]._picture(js, is) != 0xfe) {
								if ((int)(Pos + (is * size_scr_X) + js) < (int)(size_scr_X * size_scr_Y)) {
									scr_col[Pos + (is * size_scr_X) + js] = obj[i]._picture(js, is);
									scr_text[Pos + (is * size_scr_X) + js] = (TEXT)'3';
								}
							}
						}
					}

				}

				for (int is = 0;is < size_scr_X * size_scr_Y;is++) {
					SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), scr_col[is]);
					if (sizeof(TEXT) == 1)
						putchar(scr_text[is]);
					if (sizeof(TEXT) == 2)
						putwchar(scr_text[is]);
					if ((is + 1) % size_scr_X == 0 && is != 0) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}
				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), end_clr);
				if (need_comment) {
					printf("%s\n", this->Comment.c_str());
				}
				delete[] scr_col, scr_text;
			}

			void write_shake_scene(WORD size_scr_X, WORD size_scr_Y, bool need_comment, BYTE duration = 0, BYTE end_clr = 7) {
				if (duration != 0) {
					duration_shake = duration;
				}

				signed char changeX, changeY;

				BYTE* scr_col = new BYTE[size_scr_X * size_scr_Y];
				TEXT* scr_text = new TEXT[size_scr_X * size_scr_Y];

				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_col[i] = 0x00;
				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_text[i] = (TEXT)' ';

				if (duration_shake != 0) {
					changeX = _random(3);
					changeY = _random(3);
				}

				for (int i = 0;i < this->obj.size();i++) {
					auto Xp = obj[i]._position('x');
					auto Yp = obj[i]._position('y');

					if (duration_shake != 0) {
						Xp = obj[i]._position('x') + changeX;
						Yp = obj[i]._position('y') + changeY;
					}

					auto Xs = obj[i]._size('x');
					auto Ys = obj[i]._size('y');

					int Pos = (Yp * size_scr_X) + Xp;

					for (int is = 0;is < Ys;is++) {
						for (int js = 0;js < Xs;js++) {
							if (obj[i]._picture(js, is) != 0xfe) {
								if ((int)(Pos + (is * size_scr_X) + js) < (int)(size_scr_X * size_scr_Y)) {
									scr_col[Pos + (is * size_scr_X) + js] = obj[i]._picture(js, is);
									scr_text[Pos + (is * size_scr_X) + js] = (TEXT)'3';
								}
							}
						}
					}

				}

				for (int is = 0;is < size_scr_X * size_scr_Y;is++) {
					SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), scr_col[is]);
					if (sizeof(TEXT) == 1)
						putchar(scr_text[is]);
					if (sizeof(TEXT) == 2)
						putwchar(scr_text[is]);
					if ((is + 1) % size_scr_X == 0 && is != 0) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}
				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), end_clr);
				if (need_comment) {
					printf("%s\n", this->Comment.c_str());
				}

				if (duration_shake != 0) {
					duration_shake--;
				}
				delete[] scr_col, scr_text;
			}

			void write_modific_scene(WORD size_scr_X, WORD size_scr_Y, bool need_comment, std::function<BYTE(WORD, WORD, BYTE)> func, BYTE end_clr = 7) {

				BYTE* scr_col = new BYTE[size_scr_X * size_scr_Y];
				TEXT* scr_text = new TEXT[size_scr_X * size_scr_Y];

				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_col[i] = 0x00;
				for (int i = 0;i < size_scr_X * size_scr_Y;i++) scr_text[i] = (TEXT)' ';

				for (int i = 0;i < this->obj.size();i++) {

					auto Xp = obj[i]._position('x');
					auto Yp = obj[i]._position('y');

					auto Xs = obj[i]._size('x');
					auto Ys = obj[i]._size('y');

					int Pos = (Yp * size_scr_X) + Xp;

					for (int is = 0;is < Ys;is++) {
						for (int js = 0;js < Xs;js++) {
							if (obj[i]._picture(js, is) != 0xfe) {
								if ((int)(Pos + (is * size_scr_X) + js) < (int)(size_scr_X * size_scr_Y)) {
									scr_col[Pos + (is * size_scr_X) + js] = obj[i]._picture(js, is);
									scr_text[Pos + (is * size_scr_X) + js] = (TEXT)'3';
								}
							}
						}
					}

				}

				for (int is = 0;is < size_scr_Y;is++) {
					for (int js = 0;js < size_scr_X;js++) {
						scr_col[(js * size_scr_X) + is] = func(is, js, scr_col[(js * size_scr_X) + is]);
					}
				}

				for (int is = 0;is < size_scr_X * size_scr_Y;is++) {
					SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), scr_col[is]);
					if (sizeof(TEXT) == 1)
						putchar(scr_text[is]);
					if (sizeof(TEXT) == 2)
						putwchar(scr_text[is]);
					if ((is + 1) % size_scr_X == 0 && is != 0) {
						SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), 0);
						printf("\n");
					}
				}
				SetAtr(GetStdHandle(STD_OUTPUT_HANDLE), end_clr);
				if (need_comment) {
					printf("%s\n", this->Comment.c_str());
				}
				delete[] scr_col, scr_text;
			}
		};
	}
}
