#include "Game.h"


/* 
	1. "Solution Platforms" -> x64
*/

int main(int argc, char* args[]) {
	
	TGame game;
	game.Init("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 600, SDL_WINDOW_SHOWN);
	
	game.AddPlayer({ 300, 190, 100, 100 }, "Pictures/healer_f.bmp", {0, 0, 32, 36});
	game.AddTexture({ 300, 300, 100, 24 }, "Pictures/healer_f.bmp", { 0, 0, 32, 36 });
	game.AddTexture({ 1000, 500, 100, 24 }, "Pictures/paddle.bmp", { 0, 0, 25, 6 });
	game.AddTexture({ 500, 400, 100, 24 }, "Pictures/paddle.bmp", { 0, 0, 25, 6 });
	game.AddTexture({ 590, 375, 100, 24 }, "Pictures/paddle.bmp", { 0, 0, 25, 6 });
	game.SetBackGround("Pictures/veitImg.bmp");
	
	while (!PressedKey(VK_SPACE)) {
		game.Loop();
	}
	
	return 0;
}
