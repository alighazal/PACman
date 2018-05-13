#pragma once

#ifndef score_h
#define score_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
using namespace sf;

class score
{
private:
	int s;
	int l;
	Text text;
	Text text2;
	Font font;
	Text lives;
	Sprite life[3];
	Texture texture;
	RectangleShape EndingScene;
	RectangleShape timer;
	int counter;


public:
	score();
	void initialize();
	void drawScore(RenderWindow&);
	void incrementScore(int);
	int getscore();
	void minusLife();
	void specialTimer(Clock);
	void restart();

};
#endif