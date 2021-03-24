#include "snake.h"
#include "player.h"
#include <conio.h>
#include <iostream>
using namespace std;
 // I used constructor for initialize the snake properties.
snake::snake():headX(20),headY(10),tailLength(0)
{
}

// snake properties geters.
int snake::getHeadX() {
	return headX;
}
int snake::getHeadY() {
	return headY;
}
int snake::getTailLength() {
	return tailLength;
}

// snake properties seters.
void snake::setHeadX(int newHeadX) {
	headX = newHeadX;
}
void snake::setHeadY(int newHeadY) {
	headY = newHeadY;
}
void snake::setTailLength(int newTailLength) {
	tailLength = newTailLength;
}

//To shift tail.
void snake::shiftTail(int arr[], int s,int head)
{
	for (int i = s-1 ; i > 0; i--){
		arr[i] = arr[i-1];
	}
}
//To receive value from kbd.
void snake::input() {
	if (_kbhit()) {
		char kbdInput = _getch() ;
		static char lastKbdIn;
		if (tailLength == 0) {
			lastKbdIn == kbdInput;
			switch (kbdInput) {
			case 'w': dir = top; break;
			case 's': dir = down; break;
			case 'a': dir = left; break;
			case 'd': dir = right; break;
			case'x': exit(0);    break;
			}
		}
		else {
			if ((kbdInput == 'w' && headY - 1 != tailY[0]) || (kbdInput == 's' && headY + 1 != tailY[0])
				|| (kbdInput == 'a' && headX - 1 != tailX[0]) || (kbdInput == 'd' && headX + 1 != tailX[0])) {
				switch (kbdInput) {
				case 'w': dir = top; break;
				case 's': dir = down; break;
				case 'a': dir = left; break;
				case 'd': dir = right; break;
				case'x': exit(0);    break;
				}
				lastKbdIn == kbdInput;
			}
			else {
				switch (lastKbdIn) {
				case 'w': dir = top; break;
				case 's': dir = down; break;
				case 'a': dir = left; break;
				case 'd': dir = right; break;
				case'x': exit(0);    break;
				}
			}
		}
	}
}
//To change values of head X and Y .
void snake::move(player& p) {
	shiftTail(tailX, tailLength, headX);
	shiftTail(tailY, tailLength, headY);
	tailX[0] = headX;
	tailY[0] = headY; 
		switch (dir) {
		case snake::top: if (headY-1 == tailY[0])
		{
			break;
		}	headY--;
			break;
		case snake::down: 	headY++;
			break;
		case snake::right: 	headX++;
			break;
		case snake::left: 	headX--;
			break;
		}
		
	//This Condition to Game over when the snake reached to the map borders.
	if (headX > 38 || headX < 1 || headY > 18 || headY < 1 ) {
		p.setGameOver(true);
	}
}
