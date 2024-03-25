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
	this->background->Init(800, 600, path, this->renderer);															///
	if (!path.empty()) {
		background->surface = SDL_LoadBMP(path.c_str());
		background->texture = SDL_CreateTextureFromSurface(renderer, background->surface);
	}
	else
		background->texture = NULL;
	
}

void TTexture::SetBackground(TColor color) {
	this->background->Init(800, 600, color);
	background->bgColor = color;
}



void TTexture::Render() {
	if (this->texturePicture != NULL)
		SDL_RenderCopy(renderer, texturePicture, 0, box);
	else {
		SDL_SetRenderDrawColor(renderer, renderSurfaceColor->r, renderSurfaceColor->g, renderSurfaceColor->b, renderSurfaceColor->a); 
		SDL_RenderFillRect(renderer, box); 
	}
	
}

void TTexture::Clear() {

	if(background->texture != NULL)
		SDL_RenderCopy(renderer, background->texture, box, box);
	else {
		SDL_SetRenderDrawColor(renderer, background->bgColor.r, background->bgColor.g, background->bgColor.b, background->bgColor.a);
		SDL_RenderFillRect(renderer, box);
	}
}



TTexture::~TTexture() {
	SDL_FreeSurface(surfacePicture);
	SDL_FreeSurface(background->surface);
}
