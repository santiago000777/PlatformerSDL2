#pragma once
#include "Player.h"

#define FPS		165

class TGame
{
public:

public:
	
	void Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags1);
	
	~TGame();

	void Loop();

	void AddTexture(TVec2 pos, TVec2 size, const std::string& path, TVec2 fromXY, float percentX, float percentY);
	void AddPlayer(TVec2 pos, TVec2 size, const std::string& path, TVec2 fromXY, float percentX, float percentY);
	void AddTexture(TVec2 pos, TVec2 size, TColor&& color);

	void SetBackGround(const std::string& BGpath);
	void SetBackGround(TColor&& color);
	void SetInfoForEachObject();

	void Render();
	void Clear();
	void Posun();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect* windowRect = new SDL_Rect();

	TBackGround backGround;

	TPlayer* player = new TPlayer();
	std::vector<TGameObject*> objects;

	const float deltaTime = 1000.0f / FPS;
	const float posunPeriod = deltaTime / 24;
	std::chrono::time_point<std::chrono::high_resolution_clock> firstFrame, secondFrame, firstPosun, secondPosun;
	std::chrono::milliseconds durationFrame, durationPosun;

	SDL_Surface finalSurface;
	SDL_Texture* finalTexture;
	int windowWidth, windowHeight;

private:

	void InitWindow(const std::string& windowName = "Window", int posX = SDL_WINDOWPOS_CENTERED,
		int posY = SDL_WINDOWPOS_CENTERED, int windowWidth = 800, int windowHeight = 600, int flags = SDL_WINDOW_SHOWN);
	void InitRenderer(SDL_Window* window, int index = -1, int flags = 1);
};

