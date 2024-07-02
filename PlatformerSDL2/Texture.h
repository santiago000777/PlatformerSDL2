#pragma once
#include "BackGround.h"


class TTexture
{
public:
	static SDL_Texture* Create(SDL_Renderer* renderer, const std::string& path, SDL_Rect from);


//	void SetRenderBox(SDL_Rect rect);
//	void SetRenderBox(TVec2 pos, TVec2 size);
//	//void SetRenderBox(SDL_Rect* rect, TVec2 fromXY);
//	void SetBackground(const std::string& path);
//	void SetBackground(TBackGround* bg);
//	void SetWindowSize(SDL_Rect* rect);
//
//	void Render();
//	void Clear();
//
//	SDL_Surface* GetSurface();
//	SDL_Rect* GetSrcRect();
//	SDL_Rect* GetDstRect();
//
//
//	~TTexture();
//private:
//	SDL_Rect srcBox;
//	SDL_Rect dstBox;
//	SDL_Texture* texturePicture;
//	
//	SDL_Rect* window;
//
//	TBackGround background;
//
//	SDL_Renderer* renderer;

	
};

