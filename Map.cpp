#include "Map.h"

Map::Map(SDL_Renderer* rend) {
	renderer = rend;

}

Map::~Map() {

}
	
int Map::CreateTileSet(int arr[20][20]) {

	SDL_Rect box;
	box.x = 0;
	box.y = 0;
	box.w = 32;
	box.h = 32;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);

	if (arr == NULL) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int tile = tiles[i][j];
				switch (tile) {
					case TileType::Block:
						SDL_SetRenderDrawColor(renderer, 60, 179, 113, 1);
						SDL_RenderFillRect(renderer, &box);
						break;
					case TileType::Wall:
						SDL_SetRenderDrawColor(renderer, 168, 168, 168, 1);
						SDL_RenderFillRect(renderer, &box);
						break;
					default:
						printf("wut tile is this?\n");
						return -1;
				}

				box.x += 32;
			}
			box.y += 32;
			box.x = 0;
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				int tile = arr[i][j];

				tiles[i][j] = tile;
				switch (tile) {
					case TileType::Block:
						SDL_SetRenderDrawColor(renderer, 60, 179, 113, 1);
						SDL_RenderFillRect(renderer, &box);
						break;
					case TileType::Wall:
						SDL_SetRenderDrawColor(renderer, 168, 168, 168, 1);
						SDL_RenderFillRect(renderer, &box);
						break;
					default:
						printf("wut tile is this?\n");
						return -1;
				}

				box.x += 32;
			}
			box.y += 32;
			box.x = 0;
		}
	}


	SDL_RenderPresent(renderer);

	return 0;
}

int Map::CreateBackground(char* source) {
	return 0;
}