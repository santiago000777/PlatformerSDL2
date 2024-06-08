#include "GameObject.h"

TGameObject::TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, std::string path, TVec2 fromXY, float percentX, float percentY) {

	dstBox.x = pos.x;
	dstBox.y = pos.y;
	dstBox.w = size.x;
	dstBox.h = size.y;
	this->texture.CreateTexture(renderer, path);
	this->texture.SetRenderBox(&dstBox, fromXY, percentX, percentY);
}

TGameObject::TGameObject(SDL_Renderer* renderer, TVec2 pos, TVec2 size, TColor* color) {
	dstBox.x = pos.x;
	dstBox.y = pos.y;
	dstBox.w = size.x;
	dstBox.h = size.y;
	this->texture.CreateTexture(renderer, color); 
	this->texture.SetRenderBox(pos, size);
}

void TGameObject::Init(SDL_Renderer* renderer, TVec2 pos, TVec2 size, std::string path, TVec2 fromXY, float percentX, float percentY) {
	dstBox.x = pos.x;
	dstBox.y = pos.y;
	dstBox.w = size.x;
	dstBox.h = size.y;
	this->texture.CreateTexture(renderer, path);
	this->texture.SetRenderBox(&dstBox, fromXY, percentX, percentY);
}

void TGameObject::SetBackground(const std::string& path) {
	this->texture.SetBackground(path);
}

void TGameObject::SetWindowSize(SDL_Rect* rect) {
	this->texture.SetWindowSize(rect);
}

void TGameObject::SetBackground(TColor color) {
	this->texture.SetBackground(color);
}

void TGameObject::SetBackground(TBackGround* bg) {
	this->texture.SetBackground(bg);
}

TGameObject::~TGameObject() {
	//delete texture;
}


TVec2* TGameObject::GetVector() {
	return &vector;
}

void TGameObject::Posun(std::vector<TGameObject*>* otherObjects) {
	
	MistoKolize(otherObjects);


	//if (posledniKolize.x == eKolize::NONE) {	// TODO: Pridat kolize ze vsech stran (kdyz na nej bude neco padat a zaroven bude na zemi -> 2x kolize v ose Y) + Zmnenit kolize aby byly s timto pouzitelne
	//	this->dstBox.x += vector.x;
	//}
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
	

	this->texture.SetRenderBox(&this->dstBox);
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

