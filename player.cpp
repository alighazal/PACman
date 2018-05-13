#include "stdafx.h"
#include "player.h"
#include "coins.h"
#include "sounds.h"
#include "score.h"

using namespace sf;

player::player()
{
	if (font.loadFromFile( "sansation.ttf")) {
		special.setFont(font);
		special.setFillColor(Color::White);
		special.setCharacterSize(25);
		special.setPosition(8 * 30, 19 * 30);
	}

	x = 10;
	y = 12;
	texture.loadFromFile("spritesheetNEW.png");
	dir = right;
	spritesheet.left = 0;
	spritesheet.top = 0;
	spritesheet.height = 30;
	spritesheet.width = 30;
	sprite.setPosition(x * 30, y * 30);
	sprite.setTexture(texture);
	sprite.setTextureRect(spritesheet);
	immune = false;
	canKill = false;
	bomb = false;
	counter = 0;

}
	
void player::initialize() {
	x = 10;
	y = 12;
	texture.loadFromFile("spritesheetNEW.png");
	dir = right;
	spritesheet.left = 0;
	spritesheet.top = 0;
	spritesheet.height = 30;
	spritesheet.width = 30;
	sprite.setPosition(x * 30, y * 30);
	sprite.setTexture(texture);
	sprite.setTextureRect(spritesheet);
	immune = false;
	canKill = false;
	bomb = false;
	counter = 0;
}


void player::drawplayer(RenderWindow& window) {
	

	switch (dir) {
	case right:
		spritesheet.top = 0;
		
		if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
			if (spritesheet.left == 90)
				spritesheet.left = 0;
			else
				spritesheet.left += 30;

			sprite.setTextureRect(spritesheet);
			clock.restart();
		}

		window.draw(sprite);
		break;
	
	case left:

		
		spritesheet.top = 60;


		if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
			if (spritesheet.left == 90)
				spritesheet.left = 0;
			else
				spritesheet.left += 30;

			sprite.setTextureRect(spritesheet);
			clock.restart();
		}

		window.draw(sprite);
		break;
	case down:

		
		spritesheet.top = 30;


		if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
			if (spritesheet.left == 90)
				spritesheet.left = 0;
			else
				spritesheet.left += 30;

			sprite.setTextureRect(spritesheet);
			clock.restart();
		}

		window.draw(sprite);
		break;
	case up:

		
		spritesheet.top = 90;


		if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
			if (spritesheet.left == 90)
				spritesheet.left = 0;
			else
				spritesheet.left += 30;

			sprite.setTextureRect(spritesheet);
			clock.restart();
		}

		window.draw(sprite);
	case dead:


		spritesheet.top = 120;


		if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
			if (spritesheet.left == 90)
				spritesheet.left = 0;
			else
				spritesheet.left += 30;

			sprite.setTextureRect(spritesheet);
			clock.restart();
		}

		window.draw(sprite);
	}
	window.draw(special);
}
	
void player::move(maps level, coins &coin, Clock& pc, Clock& ImmunityClock, score& sc) {
	if (immune) {
		sc.specialTimer(ImmunityClock);
		special.setString("IMMUNE");
	}
	else if (canKill) {
		sc.specialTimer(ImmunityClock);
		special.setString("KILLER");
	}
	else if (bomb) {
		sc.specialTimer(ImmunityClock);
		special.setString("TERRORIST");
	}
	else special.setString("");

	if (ImmunityClock.getElapsedTime().asSeconds() > 10) {
		if (immune) {
			sc.restart();
			sc.specialTimer(ImmunityClock);
			immune = false;
		}
		else if (canKill) {
			sc.restart();
			sc.specialTimer(ImmunityClock);
			canKill = false;
		}
		else if (bomb) {
			sc.restart();
			sc.specialTimer(ImmunityClock);
			bomb = false;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (level.isAvailable(x - 1, y))
		{
			dir = left;

			sprite.move(-30, 0);
			x--;

			if (coin.noteaten(x, y)) {
				coin.eat(x, y);
				if (coin.isSpecialCoin(x, y)) {
					if (coin.kindOfSpecialCoin(x, y) == 1) {
						canKill = true; immune = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 3) {
						immune = true; canKill = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 2) {
						bomb = true; immune = false; canKill = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
				}
				else sc.incrementScore(10);
			}


		}
		pc.restart();
	}

	else if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (level.isAvailable(x + 1, y))
		{

			dir = right;
			sprite.move(30, 0);
			x++;
			if (coin.noteaten(x, y)) {
				coin.eat(x, y);
				if (coin.isSpecialCoin(x, y)) {
					if (coin.kindOfSpecialCoin(x, y) == 1) {
						canKill = true; immune = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 3) {
						immune = true; canKill = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 2) {
						bomb = true; immune = false; canKill = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
				}
				else sc.incrementScore(10);
			}
		}

		pc.restart();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) {
		if (level.isAvailable(x, y - 1))
		{
			dir = up;
			sprite.move(0, -30);
			y--;
			if (coin.noteaten(x, y)) {
				coin.eat(x, y);
				if (coin.isSpecialCoin(x, y)) {
					if (coin.kindOfSpecialCoin(x, y) == 1) {
						canKill = true; immune = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 3) {
						immune = true; canKill = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 2) {
						bomb = true; immune = false; canKill = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
				}
				else sc.incrementScore(10);
			}

		}
		pc.restart();
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down)) {
		if (level.isAvailable(x, y + 1))
		{
			dir = down;
			sprite.move(0, 30);
			y++;
			if (coin.noteaten(x, y)) {
				coin.eat(x, y);
				if (coin.isSpecialCoin(x, y)) {
					if (coin.kindOfSpecialCoin(x, y) == 1) {
						canKill = true; immune = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 3) {
						immune = true; canKill = false; bomb = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
					else if (coin.kindOfSpecialCoin(x, y) == 2) {
						bomb = true; immune = false; canKill = false; ImmunityClock.restart(); sc.incrementScore(100); sc.restart(); sound.playEatingFruit();
					}
				}
				else sc.incrementScore(10);
			}

		}
		pc.restart();
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		dir = dead;
	}

}

void player::getPosition(int& i, int& j) {
	i = x; j = y;
}

string player::playerDirection() {
	if (dir == right)
		return "right";
	else if (dir == left)
		return "left";
	else if (dir == up)
		return "up";
	else 
		return "down";
}
int player::getX() {
	return x;
}
int player::getY() {
	return y;
}



bool player::checkImmunity() {
	if (immune)
		return true;
	else return false;
}

void player::setImmune() {
	immune = true;
}
void player::setMortal() {
	immune = false;
}

void player::isDead() {
	spritesheet.top = 120;
	//sound.playDyingSound();

	if (clock.getElapsedTime().asMilliseconds() > 100.0f && counter < 4) {
		if (spritesheet.left == 90)
			spritesheet.left = 0;
		else
		spritesheet.left += 30;

		sprite.setTextureRect(spritesheet);
		clock.restart(); counter++;
	
	}
}
bool player::checkBomb() {
	return (bomb);
}

bool player::checkCanDie() {
	return (canKill);
}
