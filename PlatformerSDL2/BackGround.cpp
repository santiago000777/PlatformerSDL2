#include "BackGround.h"

TBackGround::TBackGround(int width, int height, TColor color) {
 	this->box->x = 0;
	this->box->y = 0;

	bgColor = &color;
	this->texture = NULL;
}

TBackGround::TBackGround(int width, int height, std::string path) {
	this->box->x = 0;
	this->box->y = 0;
	this->box->w = width;
	this->box->h = height;

	bgColor = NULL;

	this->surface = SDL_LoadBMP(path.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);
}

void TBackGround::Init(int width, int height, TColor color) {
	this->box->x = 0;
	this->box->y = 0;

	bgColor = &color;
	this->texture = NULL;
}

void TBackGround::Init(int width, int height, std::string path) {
	this->box->x = 0;
	this->box->y = 0;
	this->box->w = width;
	this->box->h = height;

	bgColor = NULL;

	this->surface = SDL_LoadBMP(path.c_str());
	this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);
}

void TBackGround::Render() {
	SDL_RenderClear(renderer);
	if (this->texture != NULL) {
		SDL_RenderCopy(renderer, this->texture, 0, box);
	}
	else {
		SDL_SetRenderDrawColor(renderer, bgColor->r, bgColor->g, bgColor->b, bgColor->a);
		SDL_RenderFillRect(renderer, box); 
	}
	SDL_RenderPresent(renderer); 

}
