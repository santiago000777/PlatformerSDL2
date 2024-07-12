#include "GameObject.h"

TGameObject::TGameObject(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox, SDL_Rect windowRect)
	: dstBox(dstBox), renderer(renderer), srcBox(fromBox), windowRect(windowRect) {
	texture = TTexture::Create(renderer, path);
}

void TGameObject::SetBackground(TBackGround* bg) {
	background = bg;
}

TGameObject::TGameObject(TGameObject&& rhs) {
	this->dstBox = rhs.dstBox;
	this->srcBox = rhs.srcBox;
	this->windowRect = rhs.windowRect;

	this->renderer = rhs.renderer;
	this->texture = rhs.texture;
}

TGameObject::~TGameObject() {
	SDL_DestroyTexture(texture);
	std::cout << "Deleted Object!" << std::endl;
}

void TGameObject::operator=(const TGameObject& rhs) {
	BREAK();
}

void TGameObject::operator=(TGameObject&& rhs) {
	BREAK();
}

void TGameObject::Render() {
	SDL_RenderCopy(renderer, texture, &srcBox, &dstBox); // NULL -> pro cely obr.
}

void TGameObject::HandleEvents() {
	vector = { 0, 0 };
}

void TGameObject::Posun(std::vector<TGameObject*>* otherObjects, float delta) {
	
	MistoKolize(otherObjects, delta);
	
	if (this->kolize[LEFT]) {

		if (this->vector.x > 0 && !this->kolize[RIGHT])
			this->dstBox.x += this->vector.x * delta;

		if (this->vector.y < 0 && !this->kolize[UP]
			|| this->vector.y > 0 && !this->kolize[DOWN]) {

			this->dstBox.y += this->vector.y * delta;
		}
	}
	if (this->kolize[RIGHT]) {

		if (this->vector.x < 0 && !this->kolize[LEFT]) {
			this->dstBox.x += this->vector.x * delta;
		}
		if (this->vector.y < 0 && !this->kolize[UP]
			|| this->vector.y > 0 && !this->kolize[DOWN]) {

			this->dstBox.y += this->vector.y * delta;
		}
	}
	if (this->kolize[UP]) {

		if (this->vector.y > 0 && !this->kolize[DOWN])
			this->dstBox.y += this->vector.y * delta;

		if (this->vector.x < 0 && !this->kolize[LEFT]
			|| this->vector.x > 0 && !this->kolize[RIGHT]) {

			this->dstBox.x += this->vector.x * delta;
		}
	}
	if (this->kolize[DOWN]) {

		if (this->vector.y < 0 && !this->kolize[UP])
			this->dstBox.y += this->vector.y * delta;

		if (this->vector.x < 0 && !this->kolize[LEFT]
			|| this->vector.x > 0 && !this->kolize[RIGHT]) {

			this->dstBox.x += this->vector.x * delta;
		}
	}
	if(!this->kolize[LEFT] && !this->kolize[RIGHT] && !this->kolize[UP] && !this->kolize[DOWN]) {
		this->dstBox.x += vector.x * delta;
		this->dstBox.y += vector.y * delta;
	}
}

void TGameObject::Clear() {
	SDL_RenderCopy(renderer, background->GetTexture(), &srcBox, &dstBox);
}

bool TGameObject::operator==(TGameObject obj) {
	if (this->dstBox.x != obj.dstBox.x || this->dstBox.y != obj.dstBox.y
		|| this->dstBox.w != obj.dstBox.w || this->dstBox.h != obj.dstBox.h) {

		return false;
	}
	return true;
}

void TGameObject::MistoKolize(std::vector<TGameObject*>* otherObjects, float delta) { // zprovoznit s deltou

	this->kolize[LEFT] = false;
	this->kolize[RIGHT] = false;
	this->kolize[UP] = false;
	this->kolize[DOWN] = false;
	
	for (int i = 0; i < otherObjects->size(); i++) {
		if (otherObjects->at(i) == this) {
			continue;
		}

		if ((this->dstBox.x + this->vector.x * delta + this->dstBox.w > otherObjects->at(i)->dstBox.x && this->dstBox.x + this->vector.x * delta < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w)
			&& (this->dstBox.y + this->vector.y * delta + this->dstBox.h > otherObjects->at(i)->dstBox.y && this->dstBox.y + this->vector.y * delta < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h)) {

			if (this->vector.x * delta > 0 && this->dstBox.x + this->dstBox.w >= otherObjects->at(i)->dstBox.x
				&& this->dstBox.y < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h && this->dstBox.y + this->dstBox.h > otherObjects->at(i)->dstBox.y) {

				this->kolize[RIGHT] = true;
				std::cout << "RIGHT\n";
			}
			if (this->vector.x * delta < 0 && this->dstBox.x <= otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w
				&& this->dstBox.y < otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h && this->dstBox.y + this->dstBox.h > otherObjects->at(i)->dstBox.y) {

				this->kolize[LEFT] = true;
				std::cout << "LEFT\n";
			}
			if (this->vector.y * delta > 0 && this->dstBox.y + this->dstBox.h>= otherObjects->at(i)->dstBox.y
				&& this->dstBox.x < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w && this->dstBox.x + this->dstBox.w > otherObjects->at(i)->dstBox.x) {

				this->kolize[DOWN] = true;
				std::cout << "DOWN\n";
			}
			if (this->vector.y * delta < 0 && this->dstBox.y <= otherObjects->at(i)->dstBox.y + otherObjects->at(i)->dstBox.h
				&& this->dstBox.x < otherObjects->at(i)->dstBox.x + otherObjects->at(i)->dstBox.w && this->dstBox.x + this->dstBox.w > otherObjects->at(i)->dstBox.x) {

				this->kolize[UP] = true;
				std::cout << "UP\n";
			}
		}
	}
}

