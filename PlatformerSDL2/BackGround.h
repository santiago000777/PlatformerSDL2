#pragma once
#include "common.h"

class TBackGround
{
public:
	TBackGround() = default;
	TBackGround(int width, int height, TColor color);
	TBackGround(int width, int height, std::string path);

	void Init(int width, int height, TColor color);
	void Init(int width, int height, std::string path);
public:
	void Render();

	SDL_Surface* surface;
	SDL_Texture* texture;

private:
	

	TColor* bgColor;
	SDL_Renderer* renderer;

	SDL_Rect* box = new SDL_Rect();
private:

protected:
	
};

