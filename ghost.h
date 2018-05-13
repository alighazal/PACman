
#ifndef ghost_h
#define ghost_h
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "maps.h"
#include "player.h"
#include "sounds.h"
using namespace std;

class ghost {

private:
	sf::Sprite g;
	int x, y;
	string direction;
	Texture t;
	int counter;
	IntRect spritesheet;
	sf::Clock clock;
	sf::Clock clock2;
	bool killed;
	string colour;

	sounds sound;

public:
	ghost(string); // default size 30, 30;
	ghost(int, int, string); // setting position;
	ghost();
	void initialize(int, int, string);
	//setters
	void setGhostPosition(int, int);
	void setGhostColor(string);
	void setGhostSize(int, int);
	void changeDirection(string);
	void setDirection(string);
	void moveGhost(maps, player);
	void drawGhost(sf::RenderWindow&);
	void setXY(int, int);
	//getters
	bool nextMoveAvailable(string, maps);
	int getYposition();
	int getXposition();
	bool movePossible(string, maps);
	bool checkPlayer(player p, ghost& gh, score& s);

};

#endif /* ghost_h */



