#pragma once

#include<iostream>
#include <cmath>
#include <string>       
#include <windows.h>
#include <winuser.h>
#include <conio.h>  
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <fcntl.h>
#include <locale.h>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <random>
#include <ctime>
#include <map>

#define DEBUG()	if(GetAsyncKeyState(VK_ESCAPE)) {__debugbreak();}
#define BREAK	__debugbreak
#define PI		3.14159265359


	// SDL2
#include "SDL.h"


static bool PressedKey(short key) {
	short i = GetAsyncKeyState(toupper(key));
	if ((i & 0x8000) == 0) {
		return false;
	}
	return true;
}


struct TVec2 {
public:
	int x, y;

public:
	TVec2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	TVec2() {
		x = 0;
		y = 0;
	}

	void operator+=(const TVec2& vec) {
		this->x += vec.x;
		this->y += vec.y;
	}
	TVec2& operator+(TVec2 vec) {
		vec += *this;
		return vec;
	}
};


struct TColor {
public:
	unsigned char r, g, b, a;

public:
	TColor() = default;
	TColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alfa) {
		this->r = red;
		this->g = green;
		this->b = blue;
		this->a = alfa;
	}
};