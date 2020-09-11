#include "TextureLoader.h"

void TextureLoader::RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void TextureLoader::RenderText(SDL_Renderer* renderer, SDL_Texture* fontTexture, int x, int y, const char* text) {
	SDL_Rect src, dest;

	dest.y = y;
	src.y = 0;
	src.h = dest.h = TextureLoader::CHAR_HEIGHT;
	src.w = dest.w = TextureLoader::CHAR_WIDTH;


	for (int i = 0; text[i] != '\0'; ++i) {
		dest.x = x;
		src.x = (text[i] - ' ') * TextureLoader::CHAR_WIDTH;

		SDL_RenderCopy(renderer, fontTexture, &src, &dest);

		x += TextureLoader::CHAR_WIDTH;
	}

	SDL_RenderPresent(renderer);
}