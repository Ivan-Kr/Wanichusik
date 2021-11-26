#pragma once
#include "ScreenText.h"
#include <string>
#include <list>

namespace kiwii {
	class ShaderText {
		friend ScreenText;
		ScreenText ConnectedScreen;
		std::list<std::string> action;
		bool is_connected=0;
	public:

		void Connect(ScreenText screentext);

		void Noise();

		void Color(unsigned __int8 color);

		std::string ShowList(int index);

		void Disconnect();

		~ShaderText() {}
	};
}
