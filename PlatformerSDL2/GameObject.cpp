#include "GameObject.h"

TGameObject::TGameObject(SDL_Renderer* renderer, TVec4 pos, TVec4 size, std::string path) {
	posBox->x = pos.x;
	posBox->y = pos.y;
	posBox->w = size.x;
	posBox->h = size.y;
	this->texture->CreateTexture(renderer, path);
	this->texture->SetRenderBox(posBox);
}

TGameObject::TGameObject(SDL_Renderer* renderer, TVec4 pos, TVec4 size, TColor* color) {
	posBox->x = pos.x;
	posBox->y = pos.y;
	posBox->w = size.x;
	posBox->h = size.y;
	this->texture->CreateTexture(renderer, color); 
	this->texture->SetRenderBox(posBox);
}

void TGameObject::SetBackground(std::string& path) {
	this->texture->SetBackground(path);
}

void TGameObject::SetBackground(TColor&& color) {

}

TGameObject::~TGameObject() {
	delete texture;
}

void TGameObject::Posun() {

	posBox->x += vector.x;
	posBox->y += vector.y;

	this->texture->SetRenderBox(this->posBox); 
}

void TGameObject::Frame() {
	Posun(); ///
	this->texture->Render();
	this->texture->Clear();
}
