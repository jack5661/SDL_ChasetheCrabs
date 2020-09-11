#pragma once

#include <SDL.h>

class TextureLoader
{
public:
	static void RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);

	static void RenderText(SDL_Renderer* renderer, SDL_Texture* fontTexture, int x, int y, const char* text);

	static const int CHAR_WIDTH = 18;
	static const int CHAR_HEIGHT = 28;
};

