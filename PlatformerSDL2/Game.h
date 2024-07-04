#include "Player.h"

#define FPS		60

class TGame {
public:
	TGame(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags);
	void Init(const std::string& windowName, int posX, int posY, int windowWidth, int windowHeight, int flags);

	~TGame();

	/// <summary>
	/// Calculate and render a frame depends on Frequency
	/// </summary>
	void Loop();

	/// <summary>
	/// Create a new texture and stores it in vector objects
	/// </summary>
	/// <param name="pos">-> Position in the window</param>
	/// <param name="size">-> Size in the window</param>
	/// <param name="path">-> Path of a texture image</param>
	/// <param name="fromXY">-> Image source box</param>
	/// <param name="percentX">-> How many percent of the image will be visible (x axis)</param>
	/// <param name="percentY">-> How many percent of the image will be visible (y axis)</param>
	void AddTexture(SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox);
	
	
	/// <summary>
	/// Create a new player and stores it in vector objects
	/// </summary>
	/// <param name="pos">-> Position in the window</param>
	/// <param name="size">-> Size in the window</param>
	/// <param name="path">-> Path of a texture image</param>
	/// <param name="fromXY">-> Image source box</param>
	/// <param name="percentX">-> How many percent of the image will be visible (x axis)</param>
	/// <param name="percentY">-> How many percent of the image will be visible (y axis)</param>
	void AddPlayer(SDL_Rect dstBox, const std::string& path, SDL_Rect fromBox);


	/// <summary>
	/// Sets a background as texture and in every object sets it as backround
	/// </summary>
	/// <param name="BGpath">-> Path of a texture image</param>
	void SetBackGround(const std::string& BGpath);


	/// <summary>
	/// Links every texture of an object into one final surface witch is rendered
	/// </summary>
	void Render();

	/// <summary>
	/// "Clears" Replace every texture of an object by a piece of the background
	/// </summary>
	void Clear();

	/// <summary>
	/// Shifts every object of a vector and checks collisions
	/// </summary>
	void Posun(float delta);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect windowRect;
	TBackGround backGround;

	std::vector<TGameObject*> objects;

	const float deltaTime = 1000.0f / FPS;
	const float posunPeriod = 1000.0f / 9000;
	std::chrono::time_point<std::chrono::high_resolution_clock> firstFrame, secondFrame, firstPosun, secondPosun;
	std::chrono::milliseconds durationFrame, durationPosun;
	
	

private:
	void InitWindow(const std::string& windowName = "Window", int posX = SDL_WINDOWPOS_CENTERED,
		int posY = SDL_WINDOWPOS_CENTERED, int windowWidth = 800, int windowHeight = 600, int flags = SDL_WINDOW_SHOWN);
	void InitRenderer(SDL_Window* window, int index = -1, int flags = 1);
};

