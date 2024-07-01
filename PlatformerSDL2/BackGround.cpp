#include "BackGround.h"

TBackGround::TBackGround(int width, int height, TColor color) {
 	this->box.x = 0;
	this->box.y = 0;

	bgColor = color;
	//this->texture = NULL;
}

TBackGround::TBackGround(int width, int height, std::string path, SDL_Renderer* renderer) {
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = width;
	this->box.h = height;

	//bgColor = NULL;
	this->renderer = renderer;
	this->surface = *SDL_LoadBMP(path.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, &this->surface);
}

void TBackGround::Init(int width, int height, TColor color) {
	this->box.x = 0;
	this->box.y = 0;

	bgColor = color;
	//this->texture = NULL;
}

void TBackGround::Init(int width, int height, std::string path, SDL_Renderer* renderer) {
	this->box.x = 0;
	this->box.y = 0;
	this->box.w = width;
	this->box.h = height;

	//bgColor = NULL;
	this->renderer = renderer;
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void TBackGround::SetRenderer(SDL_Renderer* renderer) {
	this->renderer = renderer;
}



void TBackGround::Render(SDL_Surface* fSurface) {
	SDL_BlitScaled(&surface, NULL, fSurface, NULL);
}
