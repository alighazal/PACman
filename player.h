#pragma once
#ifndef player_h
#define player_h

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include "maps.h"
#include <SFML/Graphics.hpp>
#include"coins.h"
#include "sounds.h"

// ADD
#include <SFML/Audio.hpp>
#include "score.h"

using namespace sf;



class player
{

private:
	enum status { up, down, left, right, dead };
	bool immune, canKill, bomb;
	Sprite sprite;
	Texture texture;
	Clock clock;
	int x;
	int y;
	status dir;
	IntRect spritesheet;
	int counter;
	Text special;
	Font font;
	sounds sound;

	

public:
	player();

	void initialize();
	void drawplayer(sf::RenderWindow&);
	void move(maps, coins&, Clock&, Clock&, score&); // added parameter score and did the adjustmenets in cpp to increment score
	void getPosition(int&, int&);
	string playerDirection();
	int getX();
	int getY();
	bool checkImmunity();
	bool checkCanDie();
	bool checkBomb();
	void setImmune();
	void setMortal();
	void isDead();

	
};

#endif // !1