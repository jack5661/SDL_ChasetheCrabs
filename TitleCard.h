#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <fstream>

#include "TextureLoader.h"

class TitleCard
{
public:
	TitleCard(SDL_Renderer* renderer, SDL_Texture* font);
	~TitleCard();
	void UpdateScore() { score++; };
	bool ReadOldScores();
	void UpdateScoreBoard();
	void WriteScoresToFile();
	void DisplayBoard();
	int GetScore() { return score; };
private:
	std::fstream* scoreFile;
	SDL_Texture* fontTexture = NULL;
	SDL_Renderer* renderer = NULL;
	int score = 0;
	const int MAX_SCORES = 3;
	int scoreBoard[3];

	const int HIGHSCORE_X = 250;
	const int HIGHSCORE_Y = 200;
};

