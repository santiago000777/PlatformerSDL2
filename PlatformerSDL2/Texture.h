#pragma once
#include "BackGround.h"


class TTexture
{
public:
	
public:
	void CreateTexture(SDL_Renderer* renderer, const std::string& path);
	void CreateTexture(SDL_Renderer* renderer, TColor* color);
	void SetRenderBox(TVec4 pos, TVec4 size);
	void SetRenderBox(SDL_Rect* rect);
	void SetBackground(const std::string& path);
	void Render();
	void Clear();


	~TTexture();
private:
	SDL_Rect* box;
	SDL_Surface* surfacePicture;
	SDL_Texture* texturePicture;

	/*SDL_Surface* surfaceBackground;
	SDL_Texture* textureBackground;*/
	TBackGround* background = new TBackGround();

	SDL_Renderer* renderer;

	TColor* renderSurfaceColor;

private:
	
};

