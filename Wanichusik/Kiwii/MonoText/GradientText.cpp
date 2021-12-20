#include "GradientText.h"

unsigned __int8 Kiwii::monotext::GradientText::Brightness(int index)
{
	if (!(index < 0 || index >= Square()))
		return BRIGHTNESS[index];
	else
		return 0;
}

void Kiwii::monotext::GradientText::Brightness(int index, unsigned __int8 val)
{
	if (!(index < 0 || index >= Square()))
		BRIGHTNESS[index] = val;
}

void Kiwii::monotext::GradientText::BrightnessDiff(int index, __int8 val)
{
	if (!(index < 0 || index >= Square()))
		BRIGHTNESS[index] += val;
}

void Kiwii::monotext::GradientText::ImportS(std::wstring grad)
{
	GRADIENT = grad.c_str();
}

void Kiwii::monotext::GradientText::ImportL(std::wstring dir)
{
	std::wifstream file;
	file.open(dir,std::ios::in);
	if (file.is_open()) {
		std::getline(file, GRADIENT);
	}
	file.close();
}

void Kiwii::monotext::GradientText::ImportLS(std::wstring dir)
{
	std::wifstream file;
	file.open(dir, std::ios::in);
	if (file.is_open()) {
		
		std::wstring s=L"";

		while (file) {
			std::getline(file, s);
			if (s[s.length() - 1] != L'>')
				GRADIENT += s;
			else break;
		}
	}
	file.close();
}

void Kiwii::monotext::GradientText::Paint()
{
	for (int i = 0;i < Square();i++) {
		_screen[i] = GRADIENT[min(BRIGHTNESS[i], GRADIENT.size() - 1)];
	}
}
