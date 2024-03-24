#pragma once
#include "Texture.h"

class TGameObject
{
public:
	TTexture* texture = new TTexture();

public:
	TGameObject(SDL_Renderer* renderer, TVec4 pos, TVec4 size, std::string path);
	TGameObject(SDL_Renderer* renderer, TVec4 pos, TVec4 size, TColor* color);

	void SetBackground(const std::string& path);
	void SetBackground(TColor color);

	~TGameObject();

	void Posun();
	void Frame();
private:
	TVec4 vector;
	SDL_Rect* posBox = new SDL_Rect();

private:

};

