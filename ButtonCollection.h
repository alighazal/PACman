#ifndef BUTTON_COLLECTION_H
#define BUTTON_COLLECTION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

using namespace std;
using namespace sf;

class ButtonCollection {

private:
	vector <Button> buttons;
	int buttonselected;
	bool active;

public:
	ButtonCollection(bool active = true);
	
	int buttonClicked(const Event& e);
	void display() const;
	void setActive(bool active);
	void setDisplay(bool display);
	void addButton(const Button& b);

};








#endif