#pragma once
#include "Kiwii.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

typedef wchar_t CHARR;

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

class ScreenText :
    public Kiwii
{
	WORD width;
	WORD height;

	HANDLE hConsole;
	DWORD dwBytesWritten = 0;

	CHARR gradient[256];
public:
	ScreenText(WORD Width, WORD Height,BYTE font_size[2]) {
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
	}
};

