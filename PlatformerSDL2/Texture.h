#pragma once
#include "common.h"

struct TVec4 {
public:
	int x, y;

public:
	TVec4(int x, int y) {
		this->x = x;
		this->y = y;
	}
	TVec4() {
		x = 0;
		y = 0;
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
	TColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alfa) {
		this->r = red;
		this->g = green;
		this->b = blue;
		this->a = alfa;
	}
};

class TTexture
{
public:
	
public:
	void CreateTexture(int startX, int startY, SDL_Renderer* renderer, const std::string& path);
	void SetBackground(const std::string& path);
	void Render();
	void Clear();

	void Posun();
	void Frame();

	~TTexture();
private:
	TVec4 pos, vector;
	SDL_Rect* box;
	SDL_Surface* surfacePicture;
	SDL_Texture* texturePicture;

	SDL_Surface* surfaceBackground;
	SDL_Texture* textureBackground;

	SDL_Renderer* renderer;


private:
	
};

