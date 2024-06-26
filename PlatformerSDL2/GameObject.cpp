#include "GameObject.h"


TGameObject::TGameObject(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox) 
	: dstBox(dstBox), texture(TTexture::Create(renderer, path, fromBox)), renderer(renderer) {
	
}

void TGameObject::Init(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox) {
	
	this->texture = TTexture::Create(renderer, path, fromBox);
	this->dstBox = dstBox;
	this->renderer = renderer;
}

void TGameObject::SetBackground(const std::string& path) {
	background = new TBackGround(1200, 600, path, renderer); // 800, 600
}

void TGameObject::SetWindowSize(SDL_Rect* rect) {
	windowRect = rect;
}

void TGameObject::SetBackground(TBackGround* bg) {
	background = bg;
}

TGameObject::~TGameObject() {
	SDL_DestroyTexture(texture);
}

TVec2* TGameObject::GetVector() {
	return &vector;
}

void TGameObject::Render() {
	SDL_RenderCopy(renderer, texture, NULL, &dstBox);
}

void TGameObject::Posun(std::vector<TGameObject*>* otherObjects) {
	
	MistoKolize(otherObjects);
	
	if (this->kolize[LEFT]) {

		if (this->vector.x > 0 && !this->kolize[RIGHT])
			this->dstBox.x += this->vector.x;

		if (this->vector.y < 0 && !this->kolize[UP]
			|| this->vector.y > 0 && !this->kolize[DOWN]) {

			this->dstBox.y += this->vector.y;
		}
	}
	if (this->kolize[RIGHT]) {

		if (this->vector.x < 0 && !this->kolize[LEFT]) {
			this->dstBox.x += this->vector.x;
		}
		if (this->vector.y < 0 && !this->kolize[UP]
			|| this->vector.y > 0 && !this->kolize[DOWN]) {

			this->dstBox.y += this->vector.y;
		}
	}
	if (this->kolize[UP]) {

		if (this->vector.y > 0 && !this->kolize[DOWN])
			this->dstBox.y += this->vector.y;

		if (this->vector.x < 0 && !this->kolize[LEFT]
			|| this->vector.x > 0 && !this->kolize[RIGHT]) {

			this->dstBox.x += this->vector.x;
		}
	}
	if (this->kolize[DOWN]) {

		if (this->vector.y < 0 && !this->kolize[UP])
			this->dstBox.y += this->vector.y;

		if (this->vector.x < 0 && !this->kolize[LEFT]
			|| this->vector.x > 0 && !this->kolize[RIGHT]) {

			this->dstBox.x += this->vector.x;
		}
	}
	if(!this->kolize[LEFT] && !this->kolize[RIGHT] && !this->kolize[UP] && !this->kolize[DOWN]) {
		this->dstBox.x += vector.x;
		this->dstBox.y += vector.y;
	}
}

void TGameObject::Clear() {
	SDL_RenderCopy(renderer, background->texture, &srcBox, &dstBox);
}

bool TGameObject::operator==(TGameObject obj) {
	if (this->dstBox.x != obj.dstBox.x || this->dstBox.y != obj.dstBox.y
		|| this->dstBox.w != obj.dstBox.w || this->dstBox.h != obj.dstBox.h) {

		return false;
	}
	return true;
}

void TGameObject::MistoKolize(std::vector<TGameObject*>* otherObjects) {
	
	this->kolize[LEFT] = false;
	this->kolize[RIGHT] = false;
	this->kolize[UP] = false;
	this->kolize[DOWN] = false;
	
	for (int i = 0; i < otherObjects->size(); i++) {
		if (otherObjects->at(i) == this) {
			continue;
		}

		if ((this->dstBox.x + this->vector.x + this->dstBox.w > otherObjects->at(i)->dstBox.x && this->dstBox.x + this->vector.x < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w)
			&& (this->dstBox.y + this->vector.y + this->dstBox.h > otherObjects->at(i)->dstBox.y && this->dstBox.y + this->vector.y < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h)) {

			if (this->vector.x > 0 && this->dstBox.x + this->dstBox.w >= otherObjects->at(i)->dstBox.x
				&& this->dstBox.y < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h && this->dstBox.y + this->dstBox.h > otherObjects->at(i)->dstBox.y) {

				this->kolize[RIGHT] = true;
				std::cout << "RIGHT\n";
			}
			if (this->vector.x < 0 && this->dstBox.x <= otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w
				&& this->dstBox.y < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h && this->dstBox.y + this->dstBox.h > otherObjects->at(i)->dstBox.y) {

				this->kolize[LEFT] = true;
				std::cout << "LEFT\n";
			}
			if (this->vector.y > 0 && this->dstBox.y + this->dstBox.h>= otherObjects->at(i)->dstBox.y
				&& this->dstBox.x < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w && this->dstBox.x + this->dstBox.w > otherObjects->at(i)->dstBox.x) {

				this->kolize[DOWN] = true;
				std::cout << "DOWN\n";
			}
			if (this->vector.y < 0 && this->dstBox.y <= otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h
				&& this->dstBox.x < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w && this->dstBox.x + this->dstBox.w > otherObjects->at(i)->dstBox.x) {

				this->kolize[UP] = true;
				std::cout << "UP\n";
			}
		}
	}
}

