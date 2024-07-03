#pragma once
#include "BackGround.h"


class TTexture
{
public:
	static SDL_Texture* Create(SDL_Renderer* renderer, const std::string& path);

};

