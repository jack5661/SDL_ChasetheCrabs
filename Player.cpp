#define _CRT_SECURE_NO_WARNINGS

#include "Player.h"

Player::Player(int spd) {
	speed = spd;
	x = START_X;
	y = START_Y;

}

Player::~Player() {

}

void Player::Move(Direction dir) {
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
			printf("Something Messed up in Player Movement\n");
	}
}
