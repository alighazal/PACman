#include "ButtonCollection.h"

ButtonCollection::ButtonCollection(bool a) {
	active = a;
	buttonselected = 0;
}

int ButtonCollection::buttonClicked(const Event& e) {		//Arrow keys pressed to move up and down menu
	if (e.type == Event::KeyPressed && active) {
		switch (e.key.code) {
			case Keyboard::Up:
				buttons[buttonselected].setHover(false);
				--buttonselected;
				if (buttonselected == -1) {
					buttonselected = buttons.size() - 1;
				}
				break;
			case Keyboard::Down:
				buttons[buttonselected].setHover(false);
				buttonselected = (buttonselected + 1) % buttons.size();
				break;
			case Keyboard::Return:
				if (buttons[buttonselected].isActive()) {
					return buttonselected;
				}
				break;
		}
		buttons[buttonselected].setHover(true);
	}
	return -1;
}

void ButtonCollection::display() const {
	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i].display();
	}
}

void ButtonCollection::setActive(bool active) {
	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i].setActive(active);
	}
	this->active = active;
}

void ButtonCollection::setDisplay(bool display) {
	for (int i = 0; i < buttons.size(); ++i) {
		buttons[i].setDisplay(display);
	}
}

void ButtonCollection::addButton(const Button& b) {
	buttons.push_back(b);
	if (buttons.size() == 1) {
		buttons[buttons.size() - 1].setHover(true);
	}
}