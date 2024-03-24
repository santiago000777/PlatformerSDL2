#include "Game.h"


void TGame::InitWindow(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags) {
	this->window = SDL_CreateWindow(windowName.c_str(), posX, posY, windowWidth, windowHeight, flags);
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
}

void TGame::InitRenderer(SDL_Window* window, int index, int flags) {
	this->renderer = SDL_CreateRenderer(window, index, flags);
}

void TGame::Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags1) {
	SDL_Init(SDL_INIT_EVERYTHING);
	InitWindow(windowName, posX, posY, windowWidth, windowHeight, flags1);
	InitRenderer(window);
	//first = std::chrono::high_resolution_clock::now(); 
}

TGame::~TGame() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects.at(i);
	}
}

void TGame::Loop() {

	Sleep(5);
	Posun();

	duration = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);
	if (duration.count() >= deltaTime) {
		first = std::chrono::high_resolution_clock::now();
		Clear();
		Render();
	}
	second = std::chrono::high_resolution_clock::now();
}

void TGame::AddTexture(TVec4 pos, TVec4 size, const std::string& path) {
	TGameObject* object = new TGameObject(renderer, pos, size, path);
	objects.push_back(object);
}

void TGame::AddTexture(TVec4 pos, TVec4 size, TColor&& color) {
	TGameObject* object = new TGameObject(renderer, pos, size, &color);
	objects.push_back(object);
}

void TGame::SetBackGround(const std::string& BGpath) {
	TBackGround* bg = new TBackGround(windowWidth, windowHeight, BGpath);
	backGround = bg;

	for (int i = 0; i < objects.size(); i++) {

	}
}

void TGame::SetBackGround2(TColor&& color) {
	TBackGround* bg = new TBackGround(windowWidth, windowHeight, color);
	backGround = bg;

	for (int i = 0; i < objects.size(); i++) {
		//objects.at(i)->SetBackground(color);
	}
}

void TGame::Clear() {
	//backGround->Render();
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->texture->Clear();
	}
}

void TGame::Render() {
	SDL_RenderClear(renderer);
	backGround->Render();
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->texture->Render();
	}
	SDL_RenderPresent(renderer);
}

void TGame::Posun() {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->Posun();
	}
}
