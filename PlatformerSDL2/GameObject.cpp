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

void TGameObject::Posun(SDL_Rect* rect2, TVec2* posun2) {
	posledniKolize = MistoKolize(rect2, posun2);
	dstBox.x += vector.x;
	dstBox.y += vector.y;

	this->texture.SetRenderBox(&this->dstBox);
}

TGameObject::eBodKolize TGameObject::MistoKolize(SDL_Rect* rect2, TVec2* posun2) {
	if ((this->dstBox.x + this->vector.x + this->dstBox.w > rect2->x && this->dstBox.x + this->vector.x < rect2->x + rect2->w)
		&& (this->dstBox.y + this->vector.y + this->dstBox.h > rect2->y && this->dstBox.y + this->vector.y < rect2->y + rect2->h)) {

		if (this->vector.x > 0 && (this->dstBox.x + this->dstBox.w <= rect2->x)) {
			this->vector.x = rect2->x - (this->dstBox.x + this->dstBox.w) + posun2->x;
			this->dstBox.x += this->vector.x;
			return eBodKolize::RIGHT;
		}
		else if (this->vector.x < 0 && (this->dstBox.x >= rect2->x + rect2->w)) {
			this->vector.x = this->dstBox.x - (rect2->x + rect2->w) - posun2->x;
			this->vector.x *= -1;
			this->dstBox.x += this->vector.x;
			return eBodKolize::LEFT;
		}
		else if (this->vector.y > 0 && (this->dstBox.y + this->dstBox.h <= rect2->y)) {

			this->vector.y = rect2->y - (this->dstBox.y + this->dstBox.h) + posun2->y;
			this->dstBox.y += this->vector.y;
			return eBodKolize::DOWN;
		}
		else if (this->vector.y < 0 && (this->dstBox.y >= rect2->y + rect2->h)) {
			this->vector.y = this->dstBox.y - (rect2->y + rect2->h) - posun2->y;
			this->vector.y *= -1;
			this->dstBox.y += this->vector.y;
			return eBodKolize::UP;
		}
	}
	else
		return eBodKolize::NONE;

	
}

