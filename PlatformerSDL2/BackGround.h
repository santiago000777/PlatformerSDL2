#pragma once
#include "common.h"

class TBackGround
{
public:
	TBackGround() = default;
	TBackGround(int width, int height, std::string path, SDL_Renderer* renderer);
	void Init(int width, int height, std::string path, SDL_Renderer* renderer);
	~TBackGround();

	void SetRenderer(SDL_Renderer* renderer);
public:
	void Render(SDL_Rect* windowRect);

	
	SDL_Texture* texture;
	TColor bgColor;

private:
	

	SDL_Renderer* renderer;

	SDL_Rect box;
private:

protected:
	
};

