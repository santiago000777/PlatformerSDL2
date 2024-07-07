#include "Game.h"
/* 
	1. "Active solution platform" -> x64
*/

int main(int argc, char* args[]) {
	
	TGame game("TITLE", 2560, 500, 1200, 600, SDL_WINDOW_SHOWN); // SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED

	for (int i = 0; i < 6; i++) {
		game.AddTexture({ 300, 90 * i, 30, 90}, "Pictures/verticalWall.bmp", {0, 0, 7, 9});
	}
	for (int i = 0; i < 6; i++) {
		game.AddTexture({ 900, 90 * i, 30, 90 }, "Pictures/verticalWall.bmp", { 0, 0, 7, 9 });
	}
	for (int i = 0; i < 10; i++) {
		game.AddTexture({ 330 + (70*i), 0, 90, 30}, "Pictures/horizontalWall.bmp", {0, 0, 9, 7});
	}
	game.AddPlayer({ 550, 500, 100, 24 }, "Pictures/paddle.bmp", {0, 0, 25, 6});

	const float ballScale = 3.0f;
	game.AddTexture({ 500, 200, (int)roundf(7 * ballScale), (int)roundf(7 * ballScale) }, "Pictures/BallBmp.bmp", { 0, 0, 7, 8 });

	game.SetBackGround("Pictures/veitImg.bmp");
	
	while (!PressedKey(VK_SPACE)) {
		game.Loop();
	}
	
		// opravit vraceni u drzeni left i right nebo up i down klavesy
	return 0;
}
