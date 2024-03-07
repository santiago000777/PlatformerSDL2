#include "Game.h"

void TGame::InitWindow(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags) {
	this->window = SDL_CreateWindow(windowName.c_str(), posX, posY, windowWidth, windowHeight, flags);
}

void TGame::InitRenderer(SDL_Window* window, int index, int flags) {
	this->renderer = SDL_CreateRenderer(window, index, flags);
}

TGame::~TGame() {
	for (int i = 0; i < textures.size(); i++) {
		delete textures.at(i);
	}
}

void TGame::Loop() {
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);
	if (duration.count() >= deltaTime) {
		for (int i = 0; i < textures.size(); i++) {
			textures.at(i)->Frame(); 
		}
	}
	second = std::chrono::high_resolution_clock::now();
	
}

void TGame::Clear() {
	for (int i = 0; i < textures.size(); i++) {
		textures.at(i)->Clear();
	}
}

void TGame::Render() {
	for (int i = 0; i < textures.size(); i++) {
		textures.at(i)->Render();
	}
}
