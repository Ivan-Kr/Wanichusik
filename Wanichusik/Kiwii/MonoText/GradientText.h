#pragma once
#include "ScreenText.h"
#include <fstream>
#include <string>

namespace kiwii {
	class GradientText :
		public ScreenText
	{
	protected:
		unsigned __int8* BRIGHTNESS;
		std::wstring GRADIENT;
	public:
		void Setup() override {
			BRIGHTNESS = new unsigned __int8[Square()];
		}

		unsigned __int8 Brightness(int index);
		void Brightness(int index, unsigned __int8 val);
		void BrightnessDiff(int index, __int8 val);

		void ImportS(std::wstring grad);
		void ImportL(std::wstring dir);
		void ImportLS(std::wstring dir);

		wchar_t Gradient(unsigned __int8 index) {
			return GRADIENT[index];
		}

		void Paint();

		~GradientText() {
			delete[] BRIGHTNESS;
		}
	};
}
