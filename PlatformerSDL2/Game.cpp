#include "Game.h"


void TGame::InitWindow(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags) {
	this->window = SDL_CreateWindow(windowName.c_str(), posX, posY, windowWidth, windowHeight, flags);
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	this->windowRect->x = 0;
	this->windowRect->y = 0;
	this->windowRect->w = windowWidth;
	this->windowRect->h = windowHeight;
}
void TGame::InitRenderer(SDL_Window* window, int index, int flags) {
	this->renderer = SDL_CreateRenderer(window, index, flags);
}

void TGame::Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags1) {
	SDL_Init(SDL_INIT_EVERYTHING);
	InitWindow(windowName, posX, posY, windowWidth, windowHeight, flags1);
	InitRenderer(window);

	finalSurface = *SDL_CreateRGBSurface(NULL, windowWidth, windowHeight, 32, 0, 0, 0, 0);
}

TGame::~TGame() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects.at(i);
		std::cout << "Deleted Object!" << std::endl;
	}
}

void TGame::Loop() {
	durationPosun = std::chrono::duration_cast<std::chrono::milliseconds>(secondPosun - firstPosun);
	if (durationPosun.count() >= posunPeriod) {
		firstPosun = std::chrono::high_resolution_clock::now();
		Posun();
	}
	else
		std::cout << "Now, from POSUN\n";
	secondPosun = std::chrono::high_resolution_clock::now();

	durationFrame = std::chrono::duration_cast<std::chrono::milliseconds>(secondFrame - firstFrame);
	if (durationFrame.count() >= deltaTime) {
		firstFrame = std::chrono::high_resolution_clock::now();
		Clear();
		Render();
	}
	else
		std::cout << "Now, from FRAME\n";
	secondFrame = std::chrono::high_resolution_clock::now();
}

void TGame::AddTexture(TVec2 pos, TVec2 size, const std::string& path, TVec2 fromXY, float percentX, float percentY) {
	TGameObject* object = new TGameObject(renderer, pos, size, path, fromXY, percentX, percentY);
	object->SetWindowSize(windowRect);
	std::cout << "Created Texture!" << std::endl;
	objects.push_back(object);
}

void TGame::AddTexture(TVec2 pos, TVec2 size, TColor&& color) {
	TGameObject* object = new TGameObject(renderer, pos, size, &color);
	object->SetWindowSize(windowRect);
	std::cout << "Created Texture!" << std::endl;
	objects.push_back(object);
	delete object;
	std::cout << "Deleted Texture!" << std::endl;
}

void TGame::SetBackGround(const std::string& BGpath) {
	backGround.Init(windowWidth, windowHeight, BGpath, renderer);
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->SetBackground(&backGround);
	}
}

void TGame::SetBackGround(TColor&& color) {
	TBackGround* bg = new TBackGround(windowWidth, windowHeight, color);
	std::cout << "Created Texture!" << std::endl;
	backGround = *bg;

	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->SetBackground(&backGround);
	}
}

void TGame::Clear() {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->texture.Clear();
	}
}

void TGame::Render() {
	SDL_BlitScaled(backGround.surface, NULL, &finalSurface, NULL);
	for (int i = 0; i < objects.size(); i++) {
		SDL_BlitScaled(objects.at(i)->texture.GetSurface(), objects.at(i)->texture.GetSrcRect(), &this->finalSurface, objects.at(i)->texture.GetDstRect());
	}
	finalTexture = SDL_CreateTextureFromSurface(renderer, &this->finalSurface);
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, finalTexture, 0, windowRect);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(finalTexture);
}

void TGame::Posun() {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->Posun();
	}
}
