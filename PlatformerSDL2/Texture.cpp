#include "Texture.h"

void TTexture::CreateTexture(int startX, int startY, SDL_Renderer* renderer, const std::string& path) {
	surfacePicture = SDL_LoadBMP(path.c_str());
	texturePicture = SDL_CreateTextureFromSurface(renderer, surfacePicture);
	this->renderer = renderer;
}

void TTexture::SetBackground(const std::string& path) {
	if (!path.empty()) {
		surfaceBackground = SDL_LoadBMP(path.c_str());
		textureBackground = SDL_CreateTextureFromSurface(renderer, surfaceBackground);
	}
	else
		textureBackground = NULL;
	
}

void TTexture::Render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texturePicture, 0, box);
	SDL_RenderPresent(renderer);
}

void TTexture::Clear() {

	SDL_RenderClear(renderer);
	if(textureBackground != NULL)
		SDL_RenderCopy(renderer, textureBackground, box, box);
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, box);
	}
	SDL_RenderPresent(renderer);
}

void TTexture::Posun() {

}

void TTexture::Frame() {

}

TTexture::~TTexture() {
	SDL_FreeSurface(surfacePicture);
	SDL_FreeSurface(surfaceBackground);
}
