#include "player.h"
// I used constructor for initialize the player properties.
player::player():score(0),gameOver(false) {}

// Player properties geters.
int player::getScore() {
	return score;
}
bool player::getGameOver() {
	return gameOver;
}

// Player properties seters.
void player::setScore(int newScore) {
	score = newScore;
}
void player::setGameOver(bool newGameOver) {
	gameOver = newGameOver;
}
