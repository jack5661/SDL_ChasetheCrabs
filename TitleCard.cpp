#include "TitleCard.h"

TitleCard::TitleCard(SDL_Renderer* renderer, SDL_Texture* font) {
	fontTexture = font;
	this->renderer = renderer;
	if (!ReadOldScores()) {
		scoreBoard[0] = 0;
		scoreBoard[1] = 0;
		scoreBoard[2] = 0;
	}
}

TitleCard::~TitleCard() {
	
}

bool TitleCard::ReadOldScores() {
	scoreFile = new std::fstream("scores.txt", std::ios::in | std::ios::out);
	int data;
	if (scoreFile->is_open()) {
		int i;
		for (i = 0; (*scoreFile) >> data; i++) {
			scoreBoard[i] = data;
		}
		while (i < MAX_SCORES) {
			scoreBoard[i++] = 0;
		}
	}
	else {
		printf("Could not open file\n");
		return false;
	}
}

void TitleCard::UpdateScoreBoard() {
	int temp = scoreBoard[0];
	scoreBoard[0] = score;
	scoreBoard[2] = scoreBoard[1];
	scoreBoard[1] = temp;
}

void TitleCard::WriteScoresToFile() {
	scoreFile->clear();
	scoreFile->seekg(0, std::ios::beg);
	(*scoreFile) << scoreBoard[0] << ' ' << scoreBoard[1] << ' ' << scoreBoard[2] << std::endl;
	if ((scoreFile->rdstate() & std::ifstream::failbit) != 0)
		std::cerr << "Error opening 'test.txt'\n";
	scoreFile->close();
	delete scoreFile;
}

void TitleCard::DisplayBoard() {
	char buf[15];
	size_t bufSize = sizeof(buf);

	TextureLoader::RenderText(renderer, fontTexture, HIGHSCORE_X, HIGHSCORE_Y, "SCORES");
	sprintf_s(buf, bufSize, "1... #%d", scoreBoard[0]);
	TextureLoader::RenderText(renderer, fontTexture, HIGHSCORE_X, HIGHSCORE_Y + TextureLoader::CHAR_HEIGHT, buf);
	sprintf_s(buf, bufSize, "2... #%d", scoreBoard[1]);
	TextureLoader::RenderText(renderer, fontTexture, HIGHSCORE_X, HIGHSCORE_Y + 2 * TextureLoader::CHAR_HEIGHT, buf);
	sprintf_s(buf, bufSize, "3... #%d", scoreBoard[2]);
	TextureLoader::RenderText(renderer, fontTexture, HIGHSCORE_X, HIGHSCORE_Y + 3 * TextureLoader::CHAR_HEIGHT, buf);
	TextureLoader::RenderText(renderer, fontTexture, HIGHSCORE_X - 4 * TextureLoader::CHAR_WIDTH, 
								HIGHSCORE_Y + 5 * TextureLoader::CHAR_HEIGHT, "PRESS SPACE TO EXIT");
}

