#include "Player.h"

TPlayer::TPlayer(SDL_Renderer* renderer, SDL_Rect dstBox, const std::string& path, SDL_Rect from, SDL_Rect windowRect)
	: TGameObject(renderer, dstBox, path, from, windowRect) {
	vector.x = 1;
	vector.y = 1;
}
TPlayer::TPlayer(TPlayer&& rhs) 
	: TGameObject(std::move(rhs)) {

}

void TPlayer::operator=(const TPlayer& rhs) {
	BREAK();
}
void TPlayer::operator=(TPlayer&& rhs) {
	BREAK();
}


TPlayer::~TPlayer() {
	std::cout << "Deleted player\n";
}

void TPlayer::HandleEvents() {
	
	if (this->kolize[eIndex::UP]) {
		vector.y *= -1;
	}
	if (this->kolize[eIndex::DOWN]) {
		vector.y *= -1;
	}
	if (this->kolize[eIndex::LEFT]) {
		vector.x *= -1;
	}
	if (this->kolize[eIndex::RIGHT]) {
		vector.x *= -1;
	}
	/*
	vector.x = 0;
	vector.y = 0;
	if (PressedKey(eControls::UP)) {
		
		vector.y = -1;
	}
	if (PressedKey(eControls::LEFT)) {

		vector.x = -1;
	}
	if (PressedKey(eControls::DOWN)) {
		
		vector.y = 1;
	}
	if (PressedKey(eControls::RIGHT)) {

		vector.x = 1;
	}*/
}