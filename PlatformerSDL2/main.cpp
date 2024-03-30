#include "Game.h"


/* 
	1. "Solution Platforms" -> x64
*/

int main(int argc, char* args[]) {
	
	TGame* game = new TGame();
	game->Init("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	

	game->AddTexture({ 100, 200 }, { 40, 40 }, "Pictures/healer_f.bmp", {0, 0}, 1.0f, 1.0f);
	//game->AddTexture({ 100, 200 }, { 40, 40 }, { 127, 4, 0, 255 });
	
	//game->SetBackGround({ 0, 0, 0, 255 });
	game->SetBackGround("Pictures/veitImg.bmp");
	
	while (!PressedKey(VK_SPACE)) {
		game->Loop();
	}
	
	
	
	return 0;
}
