#pragma once
#include "Kiwii.h"
#include <windows.h>
#include <stdio.h>

typedef wchar_t CHARR;

class ScreenText :
    public Kiwii
{
	WORD Width;
	WORD Height;

	CHARR* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten = 0;
public:
    ScreenText(WORD width, WORD height);

	void Write(unsigned __int32 index, CHARR sym);
	CHARR Read(unsigned __int32 index);

	void Out();
};

