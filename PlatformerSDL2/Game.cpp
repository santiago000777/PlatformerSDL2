#include "Game.h"

void TGame::InitWindow(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags) {
	this->window = SDL_CreateWindow(windowName.c_str(), posX, posY, windowWidth, windowHeight, flags);
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->windowRect.x = 0;
	this->windowRect.y = 0;
	this->windowRect.w = windowWidth;
	this->windowRect.h = windowHeight;
}

void TGame::InitRenderer(SDL_Window* window, int index, int flags) {
	this->renderer = SDL_CreateRenderer(window, index, flags);
}

void TGame::Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags1) {
	SDL_Init(SDL_INIT_EVERYTHING);
	InitWindow(windowName, posX, posY, windowWidth, windowHeight, flags1);
	InitRenderer(window);
}

TGame::~TGame() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects.at(i);
		std::cout << "Deleted Object!" << std::endl;
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void TGame::Loop() {
	durationPosun = std::chrono::duration_cast<std::chrono::milliseconds>(secondPosun - firstPosun);
	if (durationPosun.count() >= posunPeriod) {
		firstPosun = std::chrono::high_resolution_clock::now();
		
		Posun();
	}
	else
		//std::cout << "Now, from POSUN\n";
	secondPosun = std::chrono::high_resolution_clock::now();
	
	durationFrame = std::chrono::duration_cast<std::chrono::milliseconds>(secondFrame - firstFrame);
	if (durationFrame.count() >= deltaTime) {
		firstFrame = std::chrono::high_resolution_clock::now();
		Clear();
		Render();
	}
	else
		//std::cout << "Now, from FRAME\n";
	secondFrame = std::chrono::high_resolution_clock::now();
}

void TGame::AddTexture(SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox) {
	TGameObject* object = new TGameObject(renderer, dstBox, path, fromBox);
	object->SetWindowSize(&windowRect);
	objects.push_back(object);
}

void TGame::AddPlayer(SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox) {
	auto player = new TPlayer(renderer, dstBox, path, fromBox);
	player->SetWindowSize(&windowRect);
	objects.push_back(player);
}

void TGame::SetBackGround(const std::string& BGpath) {
	backGround.Init(windowWidth, windowHeight, BGpath, renderer);
	//player->SetBackground(&backGround);
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->SetBackground(&backGround);
	}
}

void TGame::Clear() {
	for (auto& object : objects) {
		object->Clear();
	}
}

void TGame::Render() {
	SDL_RenderClear(renderer);

	backGround.Render(&windowRect);
	for (auto& object : objects) {
		object->Render();
	}
	
	SDL_RenderPresent(renderer);
}

void TGame::Posun() {
	//player->KeyboardInput();
	//player->Posun(&objects);
	
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Posun(&objects);
	}
}
