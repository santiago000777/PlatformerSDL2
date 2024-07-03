#include "BackGround.h"

TBackGround::TBackGround(int width, int height, std::string path, SDL_Renderer* renderer) 
	: box{0, 0, width, height}, renderer(renderer) {

	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void TBackGround::Init(int width, int height, std::string path, SDL_Renderer* renderer) {
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = width;
	this->box.h = height;

	this->renderer = renderer;
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

TBackGround::~TBackGround() {
	SDL_DestroyTexture(texture);
}

void TBackGround::Render(SDL_Rect* windowRect) {
		// Uprava pomoci SDL_RenderCopy() -> zavolani SDL_RenderPresent() na vykresleni naraz v Game.cpp
	SDL_RenderCopy(renderer, texture, NULL, windowRect);
}
