#include "ScreenText.h"

ScreenText::ScreenText(
	WORD width,
	WORD height
)
{
	Width = width;
	Height = height;
	screen = new CHARR[Width * Height];
	_setsize(sizeof(ScreenText));
	hConsole = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
	);

	SetConsoleActiveScreenBuffer(hConsole);

}

void ScreenText::Write(unsigned __int32 index, CHARR sym) {
	screen[index] = sym;
}

CHARR ScreenText::Read(unsigned __int32 index) {
	return screen[index];
}

void ScreenText::Out() {
	swprintf_s(screen, 40, L"X=0, Y=0, A=0 FPS=0 " );
	screen[Width * Height - 1] = '\0';
	WriteConsoleOutputCharacter(
		hConsole,
		screen,
		Width * Height,
		{ 0,0 },
		&dwBytesWritten);
}