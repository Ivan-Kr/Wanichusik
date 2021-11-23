#pragma once
#include "ScreenText.h"
#include "Explorer.h"

namespace kiwii {
	class GradientText :
		public ScreenText
	{
		unsigned __int8* BRIGHTNESS;
		std::wstring GRADIENT;
	public:
		void Setup() override {
			BRIGHTNESS = new unsigned __int8[SQUARE()];
			GRADIENT.resize(256);
		}

		unsigned __int8 Brightness(int index);
		void Brightness(int index, unsigned __int8 val);

		void ImportS(std::wstring);
		void Import(std::wstring dir);

		wchar_t Gradient(unsigned __int8 index) {
			return GRADIENT[index];
		}

		void Paint();

		~GradientText() {
			delete[] BRIGHTNESS;
		}
	};
}
