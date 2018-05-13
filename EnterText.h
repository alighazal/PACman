#ifndef ENTERTEXT_H
#define ENTERTEXT_H

#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class EnterText {

private:
	RenderWindow * w;
	Text text;
	string s;
	bool active;
	Font font;
public:
	EnterText(RenderWindow&);

	bool textEntered(const Event &e);
	
	void display() const;

	string getText() const;

	void setActive(bool);
};

#endif