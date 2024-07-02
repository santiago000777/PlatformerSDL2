#include "Texture.h"

SDL_Texture* TTexture::Create(SDL_Renderer* renderer, const std::string& path, SDL_Rect from) {
	
	if (path.empty()) {
		std::cout << "Textura nema prirazenou cestu, cesta je prazdna";
		BREAK();
	}
	else if (SDL_LoadBMP(path.c_str()) == NULL) {
		std::cout << "Nelze nalezt soubor s cestou na nastaveni obrazku Textury: " + path;
		BREAK();
	}
	
	SDL_Surface* surface = SDL_LoadBMP(path.c_str());

	Uint32 transparentColor = SDL_MapRGBA(surface->format, 255, 255, 255, 0);
	SDL_SetColorKey(surface, SDL_ENABLE, transparentColor);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	
	return texture;
}

//void TTexture::SetRenderBox(SDL_Rect rect) {
//	dstBox = rect;
//}
//
//void TTexture::SetRenderBox(TVec2 pos, TVec2 size) {
//	dstBox.x = pos.x;
//	dstBox.y = pos.y;
//	dstBox.w = size.x;
//	dstBox.h = size.y;
//}
//
////void TTexture::SetRenderBox(SDL_Rect* rect, TVec2 fromXY) {
////	this->srcBox.x = fromXY.x;
////	this->srcBox.y = fromXY.y;
////	this->srcBox.w = ;
////	this->srcBox.h = this->surfacePicture.h * percentY;
////	this->dstBox = *rect;
////}
//
//
//void TTexture::SetBackground(const std::string& path) {
//	this->background.Init(800, 600, path, this->renderer);
//	
//	if (SDL_LoadBMP(path.c_str()) == NULL) {
//		std::cout << "Nelze nalezt soubor s cestou na nastaveni obrazku Backgroundu: " + path;
//		BREAK();
//	}
//	
//	if (!path.empty()) {
//		SDL_Surface* bSurface = SDL_LoadBMP(path.c_str());
//		background.texture = SDL_CreateTextureFromSurface(renderer, bSurface);
//		SDL_FreeSurface(bSurface);
//	}
//	else
//		background.texture = NULL;
//	
//}
//
//void TTexture::SetBackground(TBackGround* bg) {
//	this->background = *bg;
//}
//
//void TTexture::SetWindowSize(SDL_Rect* rect) {
//	this->window = rect;
//}
//
//
//
//void TTexture::Render() {
//	// Uprava pomoci SDL_RenderCopy() -> zavolani SDL_RenderPresent() na vykresleni naraz
//	
//}
//
//void TTexture::Clear() {
//
//	if(background.texture != NULL)
//		SDL_RenderCopy(renderer, background.texture, &srcBox, &dstBox);
//	else {
//		SDL_SetRenderDrawColor(renderer, background.bgColor.r, background.bgColor.g, background.bgColor.b, background.bgColor.a);
//		SDL_RenderFillRect(renderer, &dstBox);
//	}
//}
//
//TTexture::~TTexture() {
//	SDL_DestroyTexture(texturePicture);
//	//SDL_FreeSurface(&surfacePicture);
//	//SDL_FreeSurface(background->surface);
//}
