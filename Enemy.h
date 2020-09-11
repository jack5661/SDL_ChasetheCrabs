#pragma once

#include "Entity.h"
#include "Game.h"

static Direction DIRECTIONS[] = { Direction::DOWN, Direction::LEFT, Direction::RIGHT, Direction::UP };

class Enemy : public Entity
{
public:
	Enemy(int spd);
	~Enemy();

	void Move();

	static const int WIDTH = 26;
	static const int HEIGHT = 17;
private:
	
};
