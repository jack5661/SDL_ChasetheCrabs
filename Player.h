#pragma once

#include <stdio.h>

#include "Entity.h"
#include "Game.h"

class Player : public Entity 
{
public:
	Player(int spd);
	~Player();

	void Move(Direction dir);

	static const int WIDTH = 32;
	static const int HEIGHT = 26;

private:
	const int START_X = Game::SCREEN_WIDTH / 2;
	const int START_Y = Game::SCREEN_HEIGHT / 2;
};