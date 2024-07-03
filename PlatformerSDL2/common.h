#pragma once

#include <cmath>
#include <conio.h>  
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <dos.h>
#include <fcntl.h>
#include <fstream>
#include<iostream>
#include <locale.h>
#include <map>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <string>       
#include <thread>
#include <windows.h>
#include <winuser.h>

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
struct TVec4 {
public:
	int x, y, w, h;

public:
	TVec4(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	TVec4() {
		x = 0;
		y = 0;
		w = 0;
		h = 0;
	}

	void operator+=(const TVec4& vec) {
		this->x += vec.x;
		this->y += vec.y;
	}
	TVec4& operator+(TVec4 vec) {
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