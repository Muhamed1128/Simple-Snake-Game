#pragma once
class player
{
	// Player properties.
	int score;
	bool gameOver;
public:
	player();
	int getScore();
	bool getGameOver();
	void setScore(int newScore);
	void setGameOver(bool newGameOver);
};
