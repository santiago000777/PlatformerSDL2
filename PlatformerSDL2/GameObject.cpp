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

void TGameObject::AddNewObject(const SDL_Rect& dstBox, const TVec2& vector) {
	otherObjects.push_back(TOtherObject(dstBox, vector));
}

void TGameObject::Posun(/*SDL_Rect* rect2, TVec2* posun2*/) {
	
	MistoKolize();


	//if (posledniKolize.x == eKolize::NONE) {	// TODO: Pridat kolize ze vsech stran (kdyz na nej bude neco padat a zaroven bude na zemi -> 2x kolize v ose Y) + Zmnenit kolize aby byly s timto pouzitelne
	//	this->dstBox.x += vector.x;
	//}
	if (this->kolize[LEFT]) {
		std::cout << "LEFT\n";

		if (this->vector.x > 0)
			this->dstBox.x += this->vector.x;
		this->dstBox.y += this->vector.y;
	}
	if (this->kolize[RIGHT]) {
		std::cout << "RIGHT\n";

		if (this->vector.x < 0)
			this->dstBox.x += this->vector.x;
		this->dstBox.y += this->vector.y;
	}
	if (this->kolize[UP]) {
		std::cout << "UP\n";

		if (this->vector.y > 0)
			this->dstBox.y += this->vector.y;
		this->dstBox.x += this->vector.x;
	}
	if (this->kolize[DOWN]) {
		std::cout << "DOWN\n";

		if (this->vector.y < 0)
			this->dstBox.y += this->vector.y;
		this->dstBox.x += this->vector.x;
	}
	else {
		this->dstBox.x += vector.x;
		this->dstBox.y += vector.y;
	}
	

	this->texture.SetRenderBox(&this->dstBox);
}

void TGameObject::MistoKolize() {
	
	for (int i = 0; i < otherObjects.size(); i++) {
		
		this->kolize[LEFT] = false;
		this->kolize[RIGHT] = false;
		this->kolize[UP] = false;
		this->kolize[DOWN] = false;

		if ((this->dstBox.x + this->vector.x + this->dstBox.w > otherObjects[i].dstBox.x && this->dstBox.x + this->vector.x < otherObjects[i].dstBox.x + otherObjects[i].dstBox.w)
			&& (this->dstBox.y + this->vector.y + this->dstBox.h > otherObjects[i].dstBox.y && this->dstBox.y + this->vector.y < otherObjects[i].dstBox.y + otherObjects[i].dstBox.h)) {

			if (this->vector.x > 0 && (this->dstBox.x + this->dstBox.w <= otherObjects[i].dstBox.x)) {
				this->vector.x = otherObjects[i].dstBox.x - (this->dstBox.x + this->dstBox.w) + otherObjects[i].vector.x;
				this->dstBox.x += this->vector.x;

				this->kolize[RIGHT] = true;
			}
			if (this->vector.x < 0 && (this->dstBox.x >= otherObjects[i].dstBox.x + otherObjects[i].dstBox.w)) {
				this->vector.x = this->dstBox.x - (otherObjects[i].dstBox.x + otherObjects[i].dstBox.w) - otherObjects[i].vector.x;
				this->vector.x *= -1;
				this->dstBox.x += this->vector.x;

				this->kolize[LEFT] = true;
			}
			if (this->vector.y > 0 && (this->dstBox.y + this->dstBox.h <= otherObjects[i].dstBox.y)) {

				this->vector.y = otherObjects[i].dstBox.y - (this->dstBox.y + this->dstBox.h) + otherObjects[i].vector.y;
				this->dstBox.y += this->vector.y;

				this->kolize[DOWN] = true;
			}
			if (this->vector.y < 0 && (this->dstBox.y >= otherObjects[i].dstBox.y + otherObjects[i].dstBox.h)) {
				this->vector.y = this->dstBox.y - (otherObjects[i].dstBox.y + otherObjects[i].dstBox.h) - otherObjects[i].vector.y;
				this->vector.y *= -1;
				this->dstBox.y += this->vector.y;

				this->kolize[UP] = true;
			}
		}
	}
	
}

