#pragma once
#include "GameObject.h"

#define FPS		165

class TGame
{
public:

public:
	
	void Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags1);
	
	~TGame();

	void Loop();

	void AddTexture(TVec4 pos, TVec4 size, const std::string& path);
	void AddTexture(TVec4 pos, TVec4 size, TColor&& color);

	void SetBackGround(const std::string& BGpath);
	void SetBackGround2(TColor&& color);

	void Render();
	void Clear();
	void Posun();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	TBackGround* backGround;

	std::vector<TGameObject*> objects;

	const float deltaTime = 1000.0f / FPS;
	std::chrono::time_point<std::chrono::high_resolution_clock> first, second;
	std::chrono::milliseconds duration;

	int windowWidth, windowHeight;

private:

	void InitWindow(const std::string& windowName = "Window", int posX = SDL_WINDOWPOS_CENTERED,
		int posY = SDL_WINDOWPOS_CENTERED, int windowWidth = 800, int windowHeight = 600, int flags = SDL_WINDOW_SHOWN);
	void InitRenderer(SDL_Window* window, int index = -1, int flags = 1);
};

