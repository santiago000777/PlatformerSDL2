#pragma once
#include "BackGround.h"


class TTexture
{
public:
	
public:
	void CreateTexture(SDL_Renderer* renderer, const std::string& path);
	void CreateTexture(SDL_Renderer* renderer, TColor* color);
	void SetRenderBox(SDL_Rect* rect);
	void SetRenderBox(TVec2 pos, TVec2 size);
	void SetRenderBox(SDL_Rect* rect, TVec2 fromXY, float percentX, float percentY);
	void SetBackground(const std::string& path);
	void SetBackground(TColor color);
	void SetBackground(TBackGround* bg);
	void SetWindowSize(SDL_Rect* rect);

	void Render();
	void Clear();

	SDL_Surface* GetSurface();
	SDL_Rect* GetSrcRect();
	SDL_Rect* GetDstRect();

	~TTexture();
private:
	SDL_Rect srcBox;
	SDL_Rect dstBox;
	SDL_Surface* surfacePicture;
	SDL_Texture* texturePicture;

	SDL_Rect* window;

	/*SDL_Surface* surfaceBackground;
	SDL_Texture* textureBackground;*/
	TBackGround *background;

	SDL_Renderer* renderer;

	TColor renderSurfaceColor;

private:
	
};

