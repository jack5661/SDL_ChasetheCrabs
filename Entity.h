#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Entity {
public:
	int GetX() { return x; }
	int GetY() { return y; }
protected:
	int x, y;
	int speed;
};