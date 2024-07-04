#pragma once
#include "common.h"

class TBackGround 
{
public:
	TBackGround() = default;
	TBackGround(int width, int height, std::string path, SDL_Renderer* renderer);
	TBackGround(const TBackGround&& rhs) = delete;
	TBackGround(TBackGround&& rhs) = delete;
	void operator=(const TBackGround& rhs);
	void operator=(TBackGround&& rhs);

	void Init(int width, int height, std::string path, SDL_Renderer* renderer);

	~TBackGround();

	void Render(SDL_Rect* windowRect);

public:
	SDL_Texture* texture;

private:
	SDL_Renderer* renderer;
	SDL_Rect box;

private:

protected:
	
};

