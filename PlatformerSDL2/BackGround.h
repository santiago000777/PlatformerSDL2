#pragma once
#include "common.h"

class TBackGround
{
public:
	TBackGround() = default;
	TBackGround(int width, int height, TColor color);
	TBackGround(int width, int height, std::string path, SDL_Renderer* renderer);

	void Init(int width, int height, TColor color);
	void Init(int width, int height, std::string path, SDL_Renderer* renderer);

	void SetRenderer(SDL_Renderer* renderer);
public:
	void Render(SDL_Surface* surface);

	
	SDL_Texture* texture;
	TColor bgColor;

private:
	

	SDL_Renderer* renderer;

	SDL_Rect box;
private:

protected:
	
};

