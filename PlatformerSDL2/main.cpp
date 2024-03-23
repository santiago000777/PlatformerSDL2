#include "Game.h"


/* 
	1. "Solution Platforms" -> x64
*/

int main(int argc, char* args[]) {

	TGame* game = new TGame();
	game->Init("TITLE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	game->SetBackGround2({ (unsigned char)0, (unsigned char)0, (unsigned char)0, (unsigned char)255 });

	game->AddTexture({ 400, 200 }, { 40, 40 }, { (unsigned char)0, (unsigned char)255, (unsigned char)0, (unsigned char)255 });
	
	game->Render();
	
	while (!PressedKey(VK_SPACE)) {
		//game->Loop();
	}
	
	game->Clear();
	SDL_Delay(3000);

	return 0;
}
