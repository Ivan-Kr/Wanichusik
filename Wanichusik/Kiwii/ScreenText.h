#pragma once
#include "Kiwii.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>

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

int Normalize(int val, int maxx, int minn) {
	return min(max(val, minn), maxx);
}

class ScreenText :
    public Kiwii
{
	WORD width=0;
	WORD height=0;

	HANDLE hConsole;
	DWORD dwBytesWritten = 0;

	wchar_t* screen;

	double aspect;
public:
	ScreenText(WORD Width, WORD Height) {
		hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		width = Width;
		height = Height;
		aspect = (double)width / height;
		SetWindow(width, height);
		screen = new wchar_t[width * height + 1];
	}

	void _aspect(double asp) {
		aspect = asp;
	}
	double _aspect() {
		return aspect;
	}

	int _width() {
		return width;
	}
	int _height() {
		return height;
	}

	void write(int x, int y,wchar_t pix) {
		if (x >= 0 && x < width && y>=0 && y < height)
			screen[y * width + x] = pix;
	}

	wchar_t read(int x, int y) {
		if (x > 0 && x < width && y>0 && y < height)
			return screen[y * width + x];
		else
			return 0;
	}

	void out() {
		screen[width * height] = L'\0';
		WriteConsoleOutputCharacter(hConsole, screen, width * height, { 0, 0 }, &dwBytesWritten);
	}

	~ScreenText() {
		delete[] screen;
	}

};

