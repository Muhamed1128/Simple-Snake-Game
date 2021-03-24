#pragma once
#include "player.h"
class snake
{
	//Snake porperties.
	enum directions {   top=1 ,down ,right ,left };
	directions dir;
	int headX,
		headY,
		tailLength;
public:
	int tailX[100],
		tailY[100];
	snake();
	int getHeadX();
	int getHeadY();
	int getTailLength();
	void setHeadX(int newHeadX);
	void setHeadY(int newHeadY);
	void setTailLength(int newTailLength);
	void shiftTail(int arr[], int s, int head);
	void input();
	void move(player&p);
};

