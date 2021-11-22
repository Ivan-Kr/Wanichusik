#pragma once
#include "ScreenText.h"
#include <string>
#include <list>

namespace kiwii {
	class ShaderText {
		ScreenText& ConnectedScreen;
		std::list<std::string> action;
		bool is_connected;
	public:
		void Connect(ScreenText screentext);

		void Noise();

		std::string ShowList(int index);

		void Disconnect();
	};
}
