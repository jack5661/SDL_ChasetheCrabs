
#include <SDL.h>
#include <stdio.h>
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game();
	
	game->Init();

	const int FPS = 30;

	const int FRAME_DELAY = 1000 / FPS;

	while (game->IsRunning()) {

		Uint32 start = SDL_GetTicks();

		game->HandleEvent();

		if (!game->IsDisplayingBoard()) {
			game->Update();
			game->Render();
		}

		int frame = SDL_GetTicks() - start;

		if (FRAME_DELAY > frame) 
		{
			SDL_Delay(FRAME_DELAY - frame);
		}
	}

	game->Quit();

	return 0;
}
