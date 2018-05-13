#include "Scoreboard.h"
#include <fstream>

Scoreboard::Scoreboard(RenderWindow & w) {
	window = &w;
	filename = "scores.txt";
	fontfilepath = "font.ttf";
	fontsize = 25;
	displayed = false;
}

void Scoreboard::display() const {
	if (!displayed) {
		return;
	}
	ifstream input(filename);
	string name; string score;
	Font font;
	font.loadFromFile(fontfilepath);
	int offset = 0;

	while (!input.eof())
	{
		getline(input, name);
		getline(input, score);
		Text nametext(name, font, fontsize);
		nametext.setPosition(Vector2f(250, 200 + offset * 50));
		Text scoretext(score, font, fontsize);
		scoretext.setPosition(Vector2f(450, 200 + offset * 50));
		window->draw(nametext);
		window->draw(scoretext);
		++offset;
	}
}

void Scoreboard::setDisplay(bool d) {
	displayed = d;
}