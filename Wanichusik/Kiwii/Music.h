#pragma once
#pragma comment(lib, "winmm.lib")

#include <list>
#include <Windows.h>
#include <string>
#include <ctime>
#include <map>

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

// 0 Double Pedal
// 1 Pedal
// 2 Deep
// 3 Normal
// 4 Middle
// 5 Tenor
// 6 Soprano
// 7 Double High
// 8 Eighth Octave
const std::map<std::string, double>octave = {
	{"C0+",16.35160},
	{"C#0/Db0",17.32391},{"D0",18.35405},{"D#0/Eb0",19.44544},{"E0",20.60172},
	{"F0",21.82676},{"F#0/Gb0",23.12465},{"G0",24.49971},{"G#0/Ab0",25.95654},
	{"A0",27.50000},{"A#0/Bb0",29.13524},{"B0",30.86771},{"C1+",32.70320},
	{"C#1/Db1",34.64783	},{"D1",36.70810},{"D#1/Eb1",38.89087},{"E1",41.20344},
	{"F1",43.65353},{"F#1/Gb1",46.24930},{"G1",48.99943},{"G#1/Ab1",51.91309},
	{"A1",55.00000},{"A#1/Bb1",58.27047},{"B1",61.73541},{"C2+",65.40639},
	{"C#2/Db2",69.29566	},{"D2",73.41619},{"D#2/Eb2",77.78175},{"E2",82.40689},
	{"F2",87.30706},{"F#2/Gb2",92.49861},{"G2",97.99886},{"G#2/Ab2",103.8262},
	{"A2",110.0000},{"A#2/Bb2",116.5409},{"B2",123.4708},{"C3+",130.8128},
	{"C#3/Db3",138.5913	},{"D3",146.8324},{"D#3/Eb3",155.5635},{"E3",164.8138},
	{"F3",174.6141},{"F#3/Gb3",184.9972},{"G3",195.9977},{"G#3/Ab3",207.6523},
	{"A3",220.0000},{"A#3/Bb3",233.0819},{"B3",246.9417},{"C4+",261.6256},
	{"C#4/Db4",277.1826},{"D4",293.6648},{"D#4/Eb4",311.1270},{"E4",329.6276},
	{"F4",349.2282},{"F#4/Gb4",369.9944},{"G4",391.9954},{"G#4/Ab4",415.3047},
	{"A4",440.0000},{"A#4/Bb4",466.1638},{"B4",493.8833},{"C5+",523.2511},
	{"C#5/Db5",554.3653	},{"D5",587.3295},{"D#5/Eb5",622.2540},{"E5",659.2551},
	{"F5",698.4565},{"F#5/Gb5",739.9888},{"G5",783.9909},{"G#5/Ab5",830.6094},
	{"A5",880.0000},{"A#5/Bb5",932.3275},{"B5",987.7666},{"C6+",1046.502},
	{"C#6/Db6",1108.731},{"D6",1174.659},{"D#6/Eb6",1244.508},{"E6",1318.510},
	{"F6",1396.913},{"F#6/Gb6",1479.978},{"G6",1567.982},{"G#6/Ab6",1661.219},
	{"A6",1760.000},{"A#6/Bb6",1864.655},{"B6",1975.533},{"C7+",2093.005},
	{"C#7/Db7",2217.461	},{"D7",2349.318},{"D#7/Eb7",2489.016},{"E7",2637.020},
	{"F7",2793.826},{"F#7/Gb7",2959.955},{"G7",3135.963},{"G#7/Ab7",3322.438},
	{"A7",3520.000},{"A#7/Bb7",3729.310},{"B7",3951.066},{"C8+",4186.009},
	{"C#8/Db8",4434.922	},{"D8",4698.636},{"D#8/Eb8",4978.032},{"E8",5274.041},
	{"F8",5587.652},{"F#8/Gb8",5919.911},{"G8",6271.927},{"G#8/Ab8",6644.875},
	{"A8",7040.000},{"A#8/Bb8",7458.620},{"B8",7902.133}
};

double own_octave(double num) {
	return pow(2, (num - 49) / 12) * 440;
}

void play_test_song() {
	std::wstring author_songs = L"https://www.cyberforum.ru/members/116421.html";
	//in https://www.cyberforum.ru/cpp-beginners/thread235154.html

	time_t now = std::time(NULL);
#pragma warning(suppress : 4996)
	tm* ltm = localtime(&now);
	//tm* ltm = localtime(&now);

	if ((1 + ltm->tm_mon == 12 && (31 >= ltm->tm_mday >= 24)))
	{
		wprintf(L"Happy Christmas and %d! \n", 1901 + ltm->tm_year);
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(329, 500);
		Beep(247, 500);
		Beep(247, 500);
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(497, 500);
		Sleep(500);
		Beep(497, 500);
		Beep(277, 500);
		Beep(277, 500);
		Beep(440, 500);
		Beep(440, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(329, 500);
		Beep(247, 500);
		Beep(417, 500);
		Beep(417, 500);
		Beep(370, 500);
		Beep(417, 500);
		Beep(329, 500);
	}
	else
	{
		Beep(1480, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(369.99, 200);
		Beep(392, 200);
		Beep(369.99, 200);
		Beep(392, 200);
		Beep(392, 400);
		Beep(196, 400);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(880, 200);
		Beep(830.61, 200);
		Beep(880, 200);
		Beep(987.77, 400);
		Beep(880, 200);
		Beep(783.99, 200);
		Beep(698.46, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(880, 200);
		Beep(830.61, 200);
		Beep(880, 200);
		Beep(987.77, 400);
		Sleep(200);
		Beep(1108, 10);
		Beep(1174.7, 200);
		Beep(1480, 10);
		Beep(1568, 200);
		Sleep(200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(783.99, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(880, 200);
		Beep(830.61, 200);
		Beep(880, 200);
		Beep(987.77, 400);
		Beep(880, 200);
		Beep(783.99, 200);
		Beep(698.46, 200);
		Beep(659.25, 200);
		Beep(698.46, 200);
		Beep(784, 200);
		Beep(880, 400);
		Beep(784, 200);
		Beep(698.46, 200);
		Beep(659.25, 200);
		Beep(587.33, 200);
		Beep(659.25, 200);
		Beep(698.46, 200);
		Beep(784, 400);
		Beep(698.46, 200);
		Beep(659.25, 200);
		Beep(587.33, 200);
		Beep(523.25, 200);
		Beep(587.33, 200);
		Beep(659.25, 200);
		Beep(698.46, 400);
		Beep(659.25, 200);
		Beep(587.33, 200);
		Beep(493.88, 200);
		Beep(523.25, 200);
		Sleep(400);
		Beep(349.23, 400);
		Beep(392, 200);
		Beep(329.63, 200);
		Beep(523.25, 200);
		Beep(493.88, 200);
		Beep(466.16, 200);
		Beep(440, 200);
		Beep(493.88, 200);
		Beep(523.25, 200);
		Beep(880, 200);
		Beep(493.88, 200);
		Beep(880, 200);
		Beep(1760, 200);
		Beep(440, 200);
		Beep(392, 200);
		Beep(440, 200);
		Beep(493.88, 200);
		Beep(783.99, 200);
		Beep(440, 200);
		Beep(783.99, 200);
		Beep(1568, 200);
		Beep(392, 200);
		Beep(349.23, 200);
		Beep(392, 200);
		Beep(440, 200);
		Beep(698.46, 200);
		Beep(415.2, 200);
		Beep(698.46, 200);
		Beep(1396.92, 200);
		Beep(349.23, 200);
		Beep(329.63, 200);
		Beep(311.13, 200);
		Beep(329.63, 200);
		Beep(659.25, 200);
		Beep(698.46, 400);
		Beep(783.99, 400);
		Beep(440, 200);
		Beep(493.88, 200);
		Beep(523.25, 200);
		Beep(880, 200);
		Beep(493.88, 200);
		Beep(880, 200);
		Beep(1760, 200);
		Beep(440, 200);
		Beep(392, 200);
		Beep(440, 200);
		Beep(493.88, 200);
		Beep(783.99, 200);
		Beep(440, 200);
		Beep(783.99, 200);
		Beep(1568, 200);
		Beep(392, 200);
		Beep(349.23, 200);
		Beep(392, 200);
		Beep(440, 200);
		Beep(698.46, 200);
		Beep(659.25, 200);
		Beep(698.46, 200);
		Beep(739.99, 200);
		Beep(783.99, 200);
		Beep(392, 200);
		Beep(392, 200);
		Beep(392, 200);
		Beep(392, 200);
		Beep(196, 200);
		Beep(196, 200);
		Beep(196, 200);
		Beep(185, 200);
		Beep(196, 200);
		Beep(185, 200);
		Beep(196, 200);
		Beep(207.65, 200);
		Beep(220, 200);
		Beep(233.08, 200);
		Beep(246.94, 200);
	}

	delete ltm;
}

