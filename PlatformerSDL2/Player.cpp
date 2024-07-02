#include "Player.h"

TPlayer::TPlayer(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect from) {
	
	this->texture = TTexture::Create(renderer, path, from);
	this->dstBox = dstBox;
}

TPlayer::~TPlayer() {
	SDL_DestroyTexture(texture);
}

void TPlayer::KeyboardInput() {
	vector.x = 0;
	vector.y = 0;
	if (PressedKey(eControls::UP))
		vector.y = -1;
	if (PressedKey(eControls::LEFT))
		vector.x = -1;
	if (PressedKey(eControls::DOWN))
		vector.y = 1;
	if (PressedKey(eControls::RIGHT))
		vector.x = 1;
}
