#include "Texture.h"

void TTexture::CreateTexture(SDL_Renderer* renderer, const std::string& path) {
	//SDL_Tex
	try {
		if (path.empty()) {
			throw (std::string)"Textura nema prirazenou cestu, cesta je prazdna";
		}
		else if (SDL_LoadBMP(path.c_str()) == NULL) {
			throw (std::string)"Nelze nalezt soubor s cestou na nastaveni obrazku Textury: " + path;
		}
		surfacePicture = *SDL_LoadBMP(path.c_str());
	}
	catch (const std::string& msg) {
		std::cout << "Error: " << msg << "\n";
	}
	
	Uint32 transparentColor = SDL_MapRGBA(surfacePicture.format, 255, 255, 255, 0);
	SDL_SetColorKey(&surfacePicture, SDL_ENABLE, transparentColor);
	this->renderer = renderer;
}

void TTexture::CreateTexture(SDL_Renderer* renderer, TColor* color) {
	this->renderer = renderer;
	renderSurfaceColor = *color;
}

void TTexture::SetRenderBox(SDL_Rect* rect) {
	dstBox = *rect;
}

void TTexture::SetRenderBox(TVec2 pos, TVec2 size) {
	dstBox.x = pos.x;
	dstBox.y = pos.y;
	dstBox.w = size.x;
	dstBox.h = size.y;
}

void TTexture::SetRenderBox(SDL_Rect* rect, TVec2 fromXY, float percentX, float percentY) {
	this->srcBox.x = fromXY.x;
	this->srcBox.y = fromXY.y;
	this->srcBox.w = this->surfacePicture.w * percentX;
	this->srcBox.h = this->surfacePicture.h * percentY;

	this->dstBox = *rect;
}


void TTexture::SetBackground(const std::string& path) {
	this->background.Init(800, 600, path, this->renderer);
	try {
		if (SDL_LoadBMP(path.c_str()) == NULL) {
			throw (std::string)"Nelze nalezt soubor s cestou na nastaveni obrazku Backgroundu: " + path;
		}
		surfacePicture = *SDL_LoadBMP(path.c_str());
	}
	catch (const std::string& msg) {
		std::cout << "Error: " << msg << "\n";
		BREAK();
	}
	if (!path.empty()) {
		background.surface = *SDL_LoadBMP(path.c_str());
		background.texture = SDL_CreateTextureFromSurface(renderer, &background.surface);
	}
	else
		background.texture = NULL;
	
}

void TTexture::SetBackground(TColor color) {
	this->background.Init(800, 600, color);
	background.bgColor = color;
}

void TTexture::SetBackground(TBackGround* bg) {
	this->background = *bg;
}

void TTexture::SetWindowSize(SDL_Rect* rect) {
	this->window = rect;
}



void TTexture::Render() {
	if (this->texturePicture != NULL)
		SDL_RenderCopy(renderer, texturePicture, &srcBox, &dstBox);
	else {
		SDL_SetRenderDrawColor(renderer, renderSurfaceColor.r, renderSurfaceColor.g, renderSurfaceColor.b, renderSurfaceColor.a); 
		SDL_RenderFillRect(renderer, &dstBox);
	}
	
}

void TTexture::Clear() {

	if(background.texture != NULL)
		SDL_RenderCopy(renderer, background.texture, &srcBox, &dstBox);
	else {
		SDL_SetRenderDrawColor(renderer, background.bgColor.r, background.bgColor.g, background.bgColor.b, background.bgColor.a);
		SDL_RenderFillRect(renderer, &dstBox);
	}
}

SDL_Surface* TTexture::GetSurface() {
	if (background.texture != NULL) {
		return &this->surfacePicture;
	}
	else
		return NULL;
}

SDL_Rect* TTexture::GetSrcRect() {
	if (background.texture != NULL) {
		return &this->srcBox;
	}
	else
		return NULL;
}

SDL_Rect* TTexture::GetDstRect() {
	/*if (background->texture != NULL) {
		return &this->dstBox;
	}
	else
		return NULL;*/
	return &this->dstBox;
}





TTexture::~TTexture() {
	SDL_FreeSurface(&surfacePicture);
	//SDL_FreeSurface(background->surface);
}
