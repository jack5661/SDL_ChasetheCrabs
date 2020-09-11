#include "Game.h"
#include "Player.h"
#include "Enemy.h"


Game::Game() {
	
}

void Game::Init() {

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

		//Create window
		window = SDL_CreateWindow("Project One", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, 0);

			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 255);

			SDL_RenderClear(renderer);

			map = new Map(renderer);

			int arr[20][20] = {
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
						{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
			};
			map->CreateTileSet(arr);
			gameRunning = true;

			player = new Player(PLAYER_SPEED);

			playerTexture = IMG_LoadTexture(renderer, "Crab.png");
			enemyTexture = IMG_LoadTexture(renderer, "Spider.png");
			fontTexture = IMG_LoadTexture(renderer, "font.png");

			highScoreBoard = new TitleCard(renderer, fontTexture);

			GreetingsCard();

			srand(time(NULL));
		}
	}
}

Game::~Game() {


}

void Game::GreetingsCard() {
	int POS_X = 150;
	int POS_Y = 150;
	TextureLoader::RenderText(renderer, fontTexture, POS_X, POS_Y, "WELCOME TO THE GAME!");
	TextureLoader::RenderText(renderer, fontTexture, POS_X, POS_Y + TextureLoader::CHAR_HEIGHT * 2, "EAT ALL THE CRABS!!!");
	TextureLoader::RenderText(renderer, fontTexture, POS_X, POS_Y + TextureLoader::CHAR_HEIGHT * 4, "PRESS SPACE TO START");

	TextureLoader::RenderText(renderer, fontTexture, POS_X + TextureLoader::CHAR_WIDTH * 1,
							POS_Y + TextureLoader::CHAR_HEIGHT * 8, "PRESS ESC TO PAUSE");
	TextureLoader::RenderText(renderer, fontTexture, POS_X + TextureLoader::CHAR_WIDTH * 9, 
							POS_Y + TextureLoader::CHAR_HEIGHT * 9, "&");
	TextureLoader::RenderText(renderer, fontTexture, POS_X + TextureLoader::CHAR_WIDTH * 3,
							POS_Y + TextureLoader::CHAR_HEIGHT * 10, "SEE OLD SCORES");
}

void Game::HandleEvent() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) 
	{
		switch(event.type) 
		{
			case SDL_QUIT:
				gameRunning = false;
				break;
			case SDL_KEYDOWN:
				SetKey(&event.key);
				break;
			default:
				break;
		}
	}
}

void Game::SetKey(SDL_KeyboardEvent* event) {

	switch (event->keysym.scancode) {
		case SDL_SCANCODE_UP:
			player->Move(Direction::UP);
			break;
		case SDL_SCANCODE_DOWN:
			player->Move(Direction::DOWN);
			break;
		case SDL_SCANCODE_LEFT:
			player->Move(Direction::LEFT);
			break;
		case SDL_SCANCODE_RIGHT:
			player->Move(Direction::RIGHT);
			break;
		case SDL_SCANCODE_ESCAPE:
			displayBoard = true;
			highScoreBoard->DisplayBoard();
			break;
		case SDL_SCANCODE_SPACE:
			displayBoard = false;
			break;
	}

}

void Game::Update() {

	std::vector<Enemy*> toRemove;
	
	for (Enemy* en : enemies) {
		int collision = CollisionDetector::RectCollision(player->GetX(), player->GetY(), Player::WIDTH, Player::HEIGHT, 
															en->GetX(), en->GetY(), Enemy::WIDTH, Enemy::HEIGHT);
		if (collision) {
			highScoreBoard->UpdateScore();
			toRemove.push_back(en);
			printf("You ate an Enemy!!!\n");
		}

	}

	for (Enemy* en : toRemove) {
		enemies.erase(en);
		entities.erase(en);
	}

	//Add Enemies
	spawnTimer--;
	if (spawnTimer == 0) {
		Enemy* newEnemy = new Enemy(ENEMY_SPEED);
		enemies.insert(newEnemy);
		spawnTimer = SPAWN_COUNTER;
		
	}

	if (spawnTimer % 10 == 0) 
		for (auto en : enemies) en->Move();
}

void Game::Render() {
	SDL_RenderClear(renderer);
	map->CreateTileSet(NULL);
	TextureLoader::RenderTexture(renderer, playerTexture, player->GetX(), player->GetY());
	for (Enemy* ent : enemies) {
		TextureLoader::RenderTexture(renderer, enemyTexture, ent->GetX(), ent->GetY());
	}
	char buf[15];
	sprintf_s(buf, sizeof(buf), "SCORE: %d", highScoreBoard->GetScore());
	TextureLoader::RenderText(renderer, fontTexture, 0, 0, buf);
	SDL_RenderPresent(renderer);
}

void Game::Quit() {

	printf("Final Score: %d\n", highScoreBoard->GetScore());

	highScoreBoard->UpdateScoreBoard();

	highScoreBoard->WriteScoresToFile();

	SDL_DestroyTexture(playerTexture);

	SDL_DestroyTexture(enemyTexture);

	SDL_DestroyTexture(fontTexture);

	//Destroy window
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	//Quit SDL subsystems
	SDL_Quit();
}

bool Game::IsRunning() {
	return gameRunning;
}