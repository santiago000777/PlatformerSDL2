#include "Game.h"


/* 
	1. "Solution Platforms" -> x64
*/

int main(int argc, char* args[]) {
	
	TGame* game = new TGame();
	game->Init("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 600, SDL_WINDOW_SHOWN);

	

	game->AddPlayer({ 100, 200 }, { 100, 100 }, "Pictures/healer_f.bmp", {0, 0}, 0.33f, 0.25f);
	/*game->AddTexture({ 300, 50 }, { 30, 27 }, "Pictures/BallBmp.bmp", { 0, 0 }, 1.0f, 1.0f);
	game->AddTexture({ 400, 50 }, { 26, 30 }, "Pictures/BallBmp.bmp", { 0, 0 }, 1.0f, 1.0f);
	game->AddTexture({ 350, 50 }, { 30, 30 }, "Pictures/BallBmp.bmp", { 0, 0 }, 1.0f, 1.0f);*/
	//game->AddTexture({ 300, 400 }, { 100, 24 }, "Pictures/paddle.bmp", { 0, 0 }, 1.0f, 1.0f);
	game->AddTexture({ 300, 300 }, { 100, 24 }, "Pictures/paddle.bmp", { 0, 0 }, 1.0f, 1.0f);
	game->AddTexture({ 600, 500 }, { 100, 24 }, "Pictures/paddle.bmp", { 0, 0 }, 1.0f, 1.0f);
	//game->AddTexture({ 500, 400 }, { 100, 24 }, "Pictures/wall.bmp", { 0, 0 }, 1.0f, 1.0f);
	//game->AddTexture({ 100, 200 }, { 40, 40 }, { 127, 4, 0, 255 });
	
	//game->SetBackGround({ 0, 255, 0, 255 });
	game->SetBackGround("Pictures/veitImg.bmp");
	
	game->SetOtherObjects();

	while (!PressedKey(VK_SPACE)) {
		game->Loop();
	}
	
	
	
	return 0;
}
