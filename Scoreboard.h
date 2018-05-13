#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML\Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Scoreboard {

private:
	RenderWindow * window;
	string filename;
	string fontfilepath;
	int fontsize;
	bool displayed;

public:
	Scoreboard(RenderWindow & window);
	void setDisplay(bool display);
	void display() const;
};

#endif