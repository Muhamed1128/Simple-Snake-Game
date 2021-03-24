#pragma once
#include "snake.h"
#include "player.h"
class map
{
	// Map properties.
	int width,
		height,
		pointX,
		pointY;
public:
	map();
	void draw(snake& s, player& p);
};

