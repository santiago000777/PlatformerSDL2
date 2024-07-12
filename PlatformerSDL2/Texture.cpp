#include "common.h"
#include "Texture.h"

SDL_Texture* TTexture::Create(SDL_Renderer* renderer, const std::string& path) {
	
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
