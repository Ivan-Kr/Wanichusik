#pragma once
#include "ScreenText.h"
#include "SScreenText.h"
#include <vector>
#include <fstream>
#include <string>

namespace kiwii {
	namespace monotext {
		class ObgectText
		{
			friend ScreenText;
			friend SScreenText;
			std::vector<std::vector<wchar_t>> _pic;
		public:
			ObgectText();

			void Import(std::wstring dir);
			~ObgectText();

		private:

		};
	}
}
