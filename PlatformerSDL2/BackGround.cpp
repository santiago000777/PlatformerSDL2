#include "BackGround.h"

TBackGround::TBackGround(int width, int height, std::string path, SDL_Renderer* renderer) 
	: box{0, 0, width, height}, renderer(renderer) {

	SDL_Surface* surface = SDL_LoadBMP(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void TBackGround::operator=(const TBackGround& rhs) {
	BREAK();
}
void TBackGround::operator=(TBackGround&& rhs) {
	BREAK();
}

TBackGround::~TBackGround() {
	SDL_DestroyTexture(texture);
	std::cout << "Deleted background\n";
}

void TBackGround::Render(SDL_Rect* windowRect) {
		// Uprava pomoci SDL_RenderCopy() -> zavolani SDL_RenderPresent() na vykresleni naraz v Game.cpp
	SDL_RenderCopy(renderer, texture, NULL, windowRect);
}

SDL_Texture* TBackGround::GetTexture() {
	return texture;
}
