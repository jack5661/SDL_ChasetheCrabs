#include "Enemy.h"

Enemy::Enemy(int spd) {
	speed = spd;

	x = rand() % Game::GAME_WIDTH;
	if (x < Game::TILE_SIZE) x += Game::TILE_SIZE;

	y = rand() % Game::GAME_HEIGHT;
	if (y < Game::TILE_SIZE) y += Game::TILE_SIZE;
}

Enemy::~Enemy() {
	
}

void Enemy::Move() {
	int dirNum = rand() % 4;
	Direction dir = DIRECTIONS[dirNum];

	switch (dir) {
		case Direction::DOWN:
			if (Game::GAME_HEIGHT > speed + y)
				y += speed;
			break;
		case Direction::LEFT:
			if (Game::TILE_SIZE < x - speed)
				x -= speed;
			break;
		case Direction::RIGHT:
			if (Game::GAME_WIDTH > x + speed)
				x += speed;
			break;
		case Direction::UP:
			if (Game::TILE_SIZE < y - speed)
				y -= speed;
			break;
		default:
			printf("Something Messed up in Enemy Movement\n");
	}
}