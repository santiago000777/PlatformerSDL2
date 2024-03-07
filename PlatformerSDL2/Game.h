#pragma once
#include "Texture.h"

#define FPS		165 

class TGame
{
public:

public:
	void InitWindow(const std::string& windowName = "Window", int posX = SDL_WINDOWPOS_CENTERED, 
		int posY = SDL_WINDOWPOS_CENTERED, int windowWidth, int windowHeight, int flags = SDL_WINDOW_SHOWN);
	void InitRenderer(SDL_Window* window, int index = -1, int flags = 1);

	~TGame();

	void Loop();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<TTexture*> textures;

	const float deltaTime = 1000.0f / FPS;
	std::chrono::time_point<std::chrono::high_resolution_clock> first, second;
	std::chrono::milliseconds duration;

private:
	void Clear();
	void Render();
};

