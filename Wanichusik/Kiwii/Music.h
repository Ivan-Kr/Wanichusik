#pragma once
#pragma comment(lib, "winmm.lib")

#include "Explorer.h"
#include <list>
#include <Windows.h>
#include <string>

namespace kiwii {
	class Music {
	private:
		std::list<double> Inton;
		std::list<double> Tempr;
		double static_Tempr = 1, static_Inton = 1;
	public:
		void set_tempr(double tempr) {
			static_Tempr = tempr;
		}
		void set_inton(double inton) {
			static_Inton = inton;
		}
		void set_ascelator(double bpm) {
			static_Tempr = 60 / bpm;
		}

		void add_note_t(double tempr) {
			double inton = static_Inton;
			Inton.push_back(inton);
			Tempr.push_back(tempr);
		}

		void add_note_i(double inton) {
			double tempr = static_Tempr;
			Inton.push_back(inton);
			Tempr.push_back(tempr);
		}


		void add_note(double inton, double tempr) {
			Inton.push_back(inton);
			Tempr.push_back(tempr);
		}

		void out_notes() {
			auto i = Inton.begin(), j = Tempr.begin();
			printf("\nIntonation:\t");
			while (i != Inton.end()) {
				printf("%f\t", *i);
				i++;
			}
			printf("\nDuration:\t");
			while (j != Tempr.end()) {
				printf("%f\t", *j);
				j++;
			}
		}

		void play() {
			auto i = Inton.begin(), j = Tempr.begin();
			while (i != Inton.end() && j != Tempr.end()) {
				Beep(*i, *j);

				i++;
				j++;
			}
		}
	};

	inline bool is_asound(const wchar_t* dir_wav) {
		return PlaySound(dir_wav, NULL, SND_ASYNC);
	}

	inline bool is_alsound(const wchar_t* dir_wav) {
		return PlaySound(dir_wav, NULL, SND_LOOP | SND_ASYNC);
	}

	inline bool is_lsound(const wchar_t* dir_wav) {
		return PlaySound(dir_wav, NULL, SND_LOOP);
	}

	inline bool stop_sound() {
		return PlaySound(NULL, NULL, 0);
	}

	inline bool is_sound(const wchar_t* dir_wav) {
		return PlaySound(dir_wav, NULL, SND_SYNC);
	}

	double own_octave(double num) {
		return pow(2, (num - 49) / 12) * 440;
	}

	void play_test_song() {
		std::wstring author_songs = L"https://www.cyberforum.ru/members/116421.html";
		//in https://www.cyberforum.ru/cpp-beginners/thread235154.html

		file_text file_i, file_d;

		int a = 0;

		if (a) {
			file_i.open("Kiwii\\Hash\\Iyolochka_i Music.txt", std::ios::out);
			file_d.open("Kiwii\\Hash\\Iyolochka_d Music.txt", std::ios::out);
			if (file_d.is_openn() && file_i.is_openn()) {
				for (int i = 0;i < 29;i++) {
					file_d.write(1);
					file_i.write(1);
					double du = stod(file_d.get_insert());
					double in = stod(file_i.get_insert());
					Beep(in, du);
				}
			}
		}
		else {
			file_i.open("Kiwii\\Hash\\Test_i Music.txt", std::ios::out);
			file_d.open("Kiwii\\Hash\\Test_d Music.txt", std::ios::out);
			if (file_d.is_openn() && file_i.is_openn()) {
				for (int i = 0;i < 160;i++) {
					double du = stod(file_d.write(1));
					double in = stod(file_i.write(1));
					Beep(in, du);
				}
			}
		}
		file_d.close();
		file_i.close();
	}
}
