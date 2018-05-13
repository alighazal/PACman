#include "stdafx.h"
#include "score.h"

score::score() {
	texture.loadFromFile("heart.png");
	life[0].setTexture(texture);
	life[0].setPosition(16 * 30, 0);
	life[1].setTexture(texture);
	life[1].setPosition(17 * 30, 0);
	life[2].setTexture(texture);
	life[2].setPosition(18 * 30, 0);

	if (font.loadFromFile("sansation.ttf")) {
		text.setFont(font);
		text.setFillColor(Color::White);
		text.setCharacterSize(25);
		text.setString(std::to_string(s = 0));
		text.setPosition(75, 0);
		s = 0;
		text2.setFont(font);
		text2.setFillColor(Color::White);
		text2.setCharacterSize(25);
		text2.setString("Score:");
		text2.setPosition(0, 0);
		lives.setFont(font);
		lives.setFillColor(Color::White);
		lives.setCharacterSize(25);
		lives.setPosition(13 * 30, 0);
		lives.setString("Lives:");

		l = 3;
	}
	timer.setSize(Vector2f(0, 0));
	timer.setPosition(0 * 30, 19 * 30);
	timer.setFillColor(Color::Blue);
	counter = 1;
}
void score::initialize() {
	texture.loadFromFile("heart.png");
	life[0].setTexture(texture);
	life[0].setPosition(16 * 30, 0);
	life[1].setTexture(texture);
	life[1].setPosition(17 * 30, 0);
	life[2].setTexture(texture);
	life[2].setPosition(18 * 30, 0);

	if (font.loadFromFile("sansation.ttf")) {
		text.setFont(font);
		text.setFillColor(Color::White);
		text.setCharacterSize(25);
		text.setString(std::to_string(s = 0));
		text.setPosition(75, 0);
		s = 0;
		text2.setFont(font);
		text2.setFillColor(Color::White);
		text2.setCharacterSize(25);
		text2.setString("Score:");
		text2.setPosition(0, 0);
		lives.setFont(font);
		lives.setFillColor(Color::White);
		lives.setCharacterSize(25);
		lives.setPosition(13 * 30, 0);
		lives.setString("Lives:");
		l = 3;
		}
}
void score::drawScore(RenderWindow& window) {
	window.draw(text);
	window.draw(text2);
	window.draw(lives);
	for (int i = 0; i < l; i++) {
		window.draw(life[i]);

	}
	window.draw(timer);
	}
void score::incrementScore(int x) {
	text.setString(std::to_string(s + x));
	s += x;
}

int score::getscore() {
	return s;
}
void score::minusLife() {
	l--;
}

void score::specialTimer(Clock clock) {

	if (clock.getElapsedTime().asMilliseconds() > 250.0f * counter) {
		timer.setSize(Vector2f(15 * counter, 30));
		if (counter < 10)
			timer.setFillColor(Color(46, 204, 113));
		else if (counter < 20)
			timer.setFillColor(Color(241, 196, 15));
		else if (counter < 30)
			timer.setFillColor(Color(211, 84, 0));
		else
			timer.setFillColor(Color(192, 57, 43));
		counter++;
	}
	if (counter > 40)
		counter = 1;
	}

void score::restart() {
	counter = 0;
	timer.setSize(Vector2f(0, 0));
}