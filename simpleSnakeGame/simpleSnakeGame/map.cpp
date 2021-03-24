#include "map.h"
#include <iostream>
#include <ctime>
#include "snake.h"
#include "player.h"

// I used constructor for initialize the map properties.
map::map():width(40),height(20) {
	srand(time(NULL));
	pointX = rand() % 38 + 1;
	pointY = rand() % 18 + 1;
}

// This Fun used to draw  map , snake ,and player score. 
void map::draw(snake &s, player &p) {
	system("cls");
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//To draw the x borders of the map.
			if (i == 0 || i == 19)
				printf("\xCD");
			//To draw the Y borders of the map.
			else if (j == 0 || j == 39)
				printf("\xBA");
			//To draw the snake head.
			else if (j == s.getHeadX() && i == s.getHeadY()) {
				printf("\xDF");
			}
			//To draw the fruit.
			else if (j == pointX && i == pointY)
				printf("+");
			else {
				bool printed = false,
					 overlap = false;
				for (int t = 0; t < s.getTailLength(); t++){
					if (s.tailX[t] == s.getHeadX() && s.tailY[t] == s.getHeadY())
						p.setGameOver(true);
					if (s.tailX[t]==j && s.tailY[t] == i) {
						printf("\xDC");
						printed = true;
						break;
					}
				}
				if(!printed) printf(" ");
			}
			// to change the fruit position. when snake eat it.
			if (s.getHeadX() == pointX && s.getHeadY() == pointY) {
				srand(time(NULL));
				pointX = rand() % 38 + 1;
				pointY = rand() % 18 + 1;
				p.setScore(p.getScore()+1);
				s.setTailLength(s.getTailLength() + 1);
			}
		}
		printf("\n");
	}
}
