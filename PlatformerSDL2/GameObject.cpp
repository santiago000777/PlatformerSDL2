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

void TGameObject::SetBackground(const std::string& path) {
	this->texture.SetBackground(path);
}

void TGameObject::SetBackground(TColor color) {
	this->texture.SetBackground(color);
}

TGameObject::~TGameObject() {
	//delete texture;
}

void TGameObject::Posun() {

	dstBox.x += vector.x + 1;
	dstBox.y += vector.y;

	this->texture.SetRenderBox(&this->dstBox);
}

void TGameObject::Frame() {
	this->texture.Render();
	this->texture.Clear();
	Posun(); ///
}
