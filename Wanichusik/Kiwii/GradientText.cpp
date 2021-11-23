#include "GradientText.h"

unsigned __int8 kiwii::GradientText::Brightness(int index)
{
	if (!(index < 0 || index >= SQUARE()))
		return BRIGHTNESS[index];
	else
		return 0;
}

void kiwii::GradientText::Brightness(int index, unsigned __int8 val)
{
	if (!(index < 0 || index >= SQUARE()))
		BRIGHTNESS[index] = val;
}

void kiwii::GradientText::ImportS(std::wstring grad)
{
	GRADIENT = grad.c_str();
}

void kiwii::GradientText::Import(std::wstring dir)
{
	wfile_t file;
	file.open(dir, std::ios::out);
	if (file.is_openn()) {
		GRADIENT = file.write(1).c_str();
	}
	file.close();
}

void kiwii::GradientText::Paint()
{
	for (int i = 0;i < SQUARE();i++) {
		SCREEN[i] = GRADIENT[BRIGHTNESS[i]];
	}
}
