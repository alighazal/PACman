#include "EnterText.h"


EnterText::EnterText (RenderWindow& rw) {
	active = false;
	w = &rw;
	text.setPosition(Vector2f(200, 325));
	font.loadFromFile("impact.ttf");
	text.setCharacterSize(60);
	text.setFont(font);
	text.setFillColor(Color::White);
}

bool EnterText::textEntered(const Event& e) {
	if (active) {
		switch (e.type) {
			case Event::KeyPressed: {
				if (e.key.code == Keyboard::Return && s.length() > 0) {
					return true;
				}
			}
			break;
			case Event::TextEntered: {
				// Handle ASCII characters only
				if (e.text.unicode < 128 && e.text.unicode != '\r' && e.text.unicode != '\n')
				{
					if (e.text.unicode != 8 && s.length() < 10) {
						s += (char)(e.text.unicode);
					}
					else if (s.length() > 0 && e.text.unicode == 8) {
						s.pop_back();
					}
					text.setString(s);
				}
			}
			break;
		}
	}
	return false;
}

void EnterText::display() const {
	if (active) {
		w->draw(text);
	}
}

string EnterText::getText() const {
	return s;
}

void EnterText::setActive(bool a) {
	active = a;
}