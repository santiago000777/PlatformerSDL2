#include "Texture.h"

void TTexture::CreateTexture(SDL_Renderer* renderer, const std::string& path) {
	surfacePicture = SDL_LoadBMP(path.c_str());
	texturePicture = SDL_CreateTextureFromSurface(renderer, surfacePicture);
	this->renderer = renderer;
	
	

	renderSurfaceColor = NULL;
}

void TTexture::CreateTexture(SDL_Renderer* renderer, TColor* color) {
	this->renderer = renderer;
	renderSurfaceColor = color;
}

void TTexture::SetRenderBox(TVec4 pos, TVec4 size) {
	box->x = pos.x;
	box->y = pos.y;
	box->w = size.x;
	box->h = size.y;
}

void TTexture::SetRenderBox(SDL_Rect* rect) {
	this->box = rect;

}


void TTexture::SetBackground(const std::string& path) {
	this->background->Init(800, 600, path);															///
	if (!path.empty()) {
		background->surface = SDL_LoadBMP(path.c_str());
		background->texture = SDL_CreateTextureFromSurface(renderer, background->surface);
	}
	else
		background->texture = NULL;
	
}



void TTexture::Render() {
	SDL_RenderClear(renderer);
	if (background->texture != NULL)
		SDL_RenderCopy(renderer, texturePicture, 0, box);
	else {
		SDL_SetRenderDrawColor(renderer, renderSurfaceColor->r, renderSurfaceColor->g, renderSurfaceColor->b, renderSurfaceColor->a); 
		SDL_RenderFillRect(renderer, box); 
	}
	SDL_RenderPresent(renderer);
}

void TTexture::Clear() {

	SDL_RenderClear(renderer);
	if(background->texture != NULL)
		SDL_RenderCopy(renderer, background->texture, box, box);
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, box);
	}
	SDL_RenderPresent(renderer);
}



TTexture::~TTexture() {
	SDL_FreeSurface(surfacePicture);
	SDL_FreeSurface(background->surface);
}
