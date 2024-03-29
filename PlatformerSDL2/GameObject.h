#pragma once
#include "Texture.h"

class TGameObject
{
public:
	TTexture texture;

public:
	TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, std::string path, TVec2 fromXY, float percentX, float percentY);
	TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, TColor* color);

	void SetBackground(const std::string& path);
	void SetBackground(TColor color);

	~TGameObject();

	void Posun();
	void Frame();
private:
	TVec2 vector;
	SDL_Rect dstBox;
	SDL_Rect srcBox;
private:

};

