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

	finalSurface = *SDL_CreateRGBSurface(NULL, 600, 600, 32, 0, 0, 0, 0);
}

TGame::~TGame() {
	for (int i = 0; i < objects.size(); i++) {
		delete objects.at(i);
		std::cout << "Deleted Object!" << std::endl;
	}
}

void TGame::Loop() {

	Sleep(7);
	Posun();

	duration = std::chrono::duration_cast<std::chrono::milliseconds>(second - first);
	if (duration.count() >= deltaTime) {
		first = std::chrono::high_resolution_clock::now();
		Clear();
		Render();
	}
	second = std::chrono::high_resolution_clock::now();
}

void TGame::AddTexture(TVec2 pos, TVec2 size, const std::string& path, TVec2 fromXY, float percentX, float percentY) {
	TGameObject* object = new TGameObject(renderer, pos, size, path, fromXY, percentX, percentY);
	std::cout << "Created Texture!" << std::endl;
	objects.push_back(object);
}

void TGame::AddTexture(TVec2 pos, TVec2 size, TColor&& color) {
	TGameObject* object = new TGameObject(renderer, pos, size, &color);
	std::cout << "Created Texture!" << std::endl;
	objects.push_back(object);
	delete object;
	std::cout << "Deleted Texture!" << std::endl;
}

void TGame::SetBackGround(const std::string& BGpath) {
	backGround.Init(windowWidth, windowHeight, BGpath, renderer);
	//bg->SetRenderer(this->renderer);
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
	//backGround->Render();
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
	//SDL_FreeSurface(&this->finalSurface);
	//std::cout << "Deleted Surface!" << std::endl;

	SDL_RenderClear(renderer);
	SDL_Rect* rect1 = new SDL_Rect();
	std::cout << "Created Rect!" << std::endl;
	rect1->x = 0; 
	rect1->y = 0; 
	rect1->w = windowWidth; 
	rect1->h = windowHeight; 
	SDL_RenderCopy(renderer, finalTexture, 0, rect1);
	SDL_DestroyTexture(finalTexture);
	SDL_RenderPresent(renderer);
	delete rect1;
	std::cout << "Deleted Rect!" << std::endl;
}

void TGame::Posun() {
	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->Posun();
	}
}
