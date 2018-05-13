#pragma once

#ifndef LEVEL_H
#define LEVEL_H


#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include <sstream>
#include "coins.h"
#include "ghost.h"
#include "sounds.h"
#include "score.h"
#include "maps.h"
#include "player.h"
#include "transitions.h"

enum state {won ,lost, null};

class level
{

private:
	coins coin;
	ghost g1, g2, g3, g4;
	score s;
	int lives;
	sounds sound;
	Clock c, pc, IMMUNE, clock,newc;
	maps m;
	player pac;
	RectangleShape into;
	Text text1;
	Font font;
	int counter;
	transitions trans;
	state pass;
	string levelname;

public:
	level(int x, int y, int z, string input, string map, bool flag);
	void playlevel(RenderWindow &window, int max);
	~level();
	int getlives();
	int getscore();
	void drawinto(RenderWindow &window);
	state GetState();
	void nullify();
	};
#endif 




