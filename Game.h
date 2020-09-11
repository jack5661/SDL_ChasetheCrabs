#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <time.h>

#include "Map.h"
#include "Entity.h"
#include "TextureLoader.h"
#include "CollisionDetector.h"
#include "TitleCard.h"

enum class Direction {UP, DOWN, LEFT, RIGHT, OTHER};

class Player;

class Enemy;

class Game {
public:
	Game();
	~Game();

	void Init();
	void HandleEvent();
	void Update();
	void Render();
	void Quit();

	bool IsRunning();

	bool IsDisplayingBoard() { return displayBoard; };

	static const int TILE_SIZE = 32;

	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 640;

	static const int GAME_WIDTH = SCREEN_WIDTH - 2 * TILE_SIZE;
	static const int GAME_HEIGHT = SCREEN_HEIGHT - 2 * TILE_SIZE;

private:
	void SetKey(SDL_KeyboardEvent* event);

	SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	
	bool gameRunning = false;

	Map* map;

	std::unordered_set<Entity*> entities;

	std::unordered_set<Enemy*> enemies;

	Player* player = nullptr;
	SDL_Texture* playerTexture = NULL;
	const int PLAYER_SPEED = 8;

	SDL_Texture* enemyTexture = NULL;
	const int ENEMY_SPEED = 12;
	const int SPAWN_COUNTER = 60;
	int spawnTimer = SPAWN_COUNTER;

	TitleCard* highScoreBoard = NULL;
	SDL_Texture* fontTexture = NULL;
	void GreetingsCard();
	bool displayBoard = true;
};
