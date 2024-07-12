#pragma once
#include "common.h"

class TBackGround 
{
public:
		// Default ctor
	TBackGround() = default;
		// ctor s parametry
	TBackGround(int width, int height, std::string path, SDL_Renderer* renderer);
		// copy ctor (zakazany)
	TBackGround(const TBackGround& rhs) = delete;
		// move ctor (zakazany)
	TBackGround(TBackGround&& rhs) = delete;
		// copy prirazeni
	void operator=(const TBackGround& rhs);
		// move prirazeni
	void operator=(TBackGround&& rhs);
		// Destructor
	~TBackGround();

	void Render(SDL_Rect* windowRect);
	SDL_Texture* GetTexture();

private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	SDL_Rect box;
};

