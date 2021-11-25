#pragma once
#
#include <chrono>
#include <string>
#include <iostream>

namespace kiwii{
#define NOW_T std::chrono::system_clock::now()
	typedef std::chrono::system_clock::time_point TIME_POINT;

	class time {
		unsigned __int8 min, hou, se;
	public:
		time(bool is_NULL) {
			min = 0;
			se = 0;
			hou = 0;
		}
		unsigned __int8 second() {
			return se % 60;
		}
		void second(unsigned __int8 seconds) {
			se = seconds;
		}
		unsigned __int8 minute() {
			return min % 60;
		}
		void minute(unsigned __int8 minutes) {
			min = minutes;
		}
		unsigned __int8 hour() {
			return hou % 24;
		}
		void hour(unsigned __int8 hours) {
			hou = hours;
		}
	private:

	};

	class date {
	private:
		unsigned __int16 day = 0, month = 0;
		unsigned __int16 year = 0;
	public:
		date(double date) {
			date *= 100;
			day = date;
			day %= 100;
			day %= 32;
			month = date;
			month /= 100;
			month %= 13;
		}

		void operator= (double date) {
			date *= 100;
			day = date;
			day %= 100;
			day %= 32;
			month = date;
			month /= 100;
			month %= 13;
		}

		void set_year(unsigned __int16 year) {
			year = year;
		}

		void set_time_now() {
			time_t now = std::time(0);
	#pragma warning(suppress : 4996)
			tm* ltm = localtime(&now);

			day = ltm->tm_mday;
			month = ltm->tm_mon + 1;
			year = ltm->tm_year + 1900;

			delete ltm;
		}

		std::string out(const char* method) {
			std::string muck = "";
			day++;
			month++;

			if (method == "y.m.d") {
				muck += std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day);
			}
			else if (method == "m.d") {
				muck += std::to_string(month) + "." + std::to_string(day);
			}
			else if (method == "mm.dd") {
				if ((month / 10) * (day / 10) == 0) {
					muck += "0" + std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else if (month / 10 == 0) {
					muck += "0" + std::to_string(month);
					muck += "." + std::to_string(day);
				}
				else if (day / 10 == 0) {
					muck += std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else {
					muck += std::to_string(month) + "." + std::to_string(day);
				}
			}
			else if (method == "yy.mm.dd") {
				if (year % 100 < 10) {
					muck += "0" + std::to_string(year % 100);
					muck += ".";
					if ((month / 10) * (day / 10) == 0) {
						muck += "0" + std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else if (month / 10 == 0) {
						muck += "0" + std::to_string(month);
						muck += "." + std::to_string(day);
					}
					else if (day / 10 == 0) {
						muck += std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else {
						muck += std::to_string(month) + "." + std::to_string(day);
					}
				}
				else {
					muck += std::to_string(year % 100);
					muck += ".";
					if ((month / 10) * (day / 10) == 0) {
						muck += "0" + std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else if (month / 10 == 0) {
						muck += "0" + std::to_string(month);
						muck += "." + std::to_string(day);
					}
					else if (day / 10 == 0) {
						muck += std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else {
						muck += std::to_string(month) + "." + std::to_string(day);
					}
				}
			}
			else if (method == "y.mm.dd") {
				muck += std::to_string(year) + ".";
				if ((month / 10) * (day / 10) == 0) {
					muck += "0" + std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else if (month / 10 == 0) {
					muck += "0" + std::to_string(month);
					muck += "." + std::to_string(day);
				}
				else if (day / 10 == 0) {
					muck += std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else {
					muck += std::to_string(month) + "." + std::to_string(day);
				}
			}

			day--;
			month--;
			return muck;
		}

		void out_date(const char* method) {
			std::string muck = "";

			if (method == "y.m.d") {
				muck += std::to_string(year) + "." + std::to_string(month) + "." + std::to_string(day);
			}
			else if (method == "m.d") {
				muck += std::to_string(month) + "." + std::to_string(day);
			}
			else if (method == "mm.dd") {
				if ((month / 10) * (day / 10) == 0) {
					muck += "0" + std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else if (month / 10 == 0) {
					muck += "0" + std::to_string(month);
					muck += "." + std::to_string(day);
				}
				else if (day / 10 == 0) {
					muck += std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else {
					muck += std::to_string(month) + "." + std::to_string(day);
				}
			}
			else if (method == "yy.mm.dd") {
				if (year % 100 < 10) {
					muck += "0" + std::to_string(year % 100);
					muck += ".";
					if ((month / 10) * (day / 10) == 0) {
						muck += "0" + std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else if (month / 10 == 0) {
						muck += "0" + std::to_string(month);
						muck += "." + std::to_string(day);
					}
					else if (day / 10 == 0) {
						muck += std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else {
						muck += std::to_string(month) + "." + std::to_string(day);
					}
				}
				else {
					muck += std::to_string(year % 100);
					muck += ".";
					if ((month / 10) * (day / 10) == 0) {
						muck += "0" + std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else if (month / 10 == 0) {
						muck += "0" + std::to_string(month);
						muck += "." + std::to_string(day);
					}
					else if (day / 10 == 0) {
						muck += std::to_string(month);
						muck += ".0" + std::to_string(day);
					}
					else {
						muck += std::to_string(month) + "." + std::to_string(day);
					}
				}
			}
			else if (method == "y.mm.dd") {
				muck += std::to_string(year) + ".";
				if ((month / 10) * (day / 10) == 0) {
					muck += "0" + std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else if (month / 10 == 0) {
					muck += "0" + std::to_string(month);
					muck += "." + std::to_string(day);
				}
				else if (day / 10 == 0) {
					muck += std::to_string(month);
					muck += ".0" + std::to_string(day);
				}
				else {
					muck += std::to_string(month) + "." + std::to_string(day);
				}
			}

			printf("%s", muck.c_str());
		}
	};

	long get_diff_h(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::hours>(end - begin).count();
	}
	long get_diff_m(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::minutes>(end - begin).count();
	}
	long get_diff_s(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::seconds>(end - begin).count();
	}
	long get_diff_ms(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	}
	long get_diff_us(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	}
	long get_diff_ns(TIME_POINT begin = NOW_T, TIME_POINT end = NOW_T) {
		return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
	}

	void time_get(TIME_POINT begin, TIME_POINT end) {
		uint32_t nMax = 10000;
		std::string title = "Duration -> ";
		if (!(get_diff_ns(begin, end) > nMax))
			std::cout << title << get_diff_ns(begin, end) << " nanosec\n";
		else if (!(get_diff_us(begin, end) > nMax))
			std::cout << title << get_diff_us(begin, end) << " microsec\n";
		else if (!(get_diff_ms(begin, end) > nMax))
			std::cout << title << get_diff_ms(begin, end) << " millisec\n";
		else if (!(get_diff_s(begin, end) > nMax))
			std::cout << title << get_diff_s(begin, end) << " seconds\n";
		else if (!(get_diff_m(begin, end) > nMax))
			std::cout << title << get_diff_m(begin, end) << " minutes\n";
		else
			std::cout << title << get_diff_h(begin, end) << " hours\n";
		//std::cin.get();
	}

	long time_get_g(TIME_POINT begin, TIME_POINT end) {
		return get_diff_ms(begin, end);
	}

	void time_rps(TIME_POINT begin, TIME_POINT end) {
		std::wstring title = L"RPS(FPS) -> ";
		wprintf(L"%s%.3f\n", title.c_str(), (double)(pow(10, 3) / get_diff_ms(begin, end)));
		//std::cin.get();
	}
	double time_rps_g(TIME_POINT begin, TIME_POINT end) {
		return (double)(pow(10, 6) / get_diff_us(begin, end));
		//std::cin.get();
	}
}
