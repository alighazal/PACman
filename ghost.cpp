#include "stdafx.h"
#include "ghost.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "time.h"
#include "maps.h"
#include "player.h"

using namespace std;

//constructors

ghost::ghost(string c) {

	g.setPosition(0, 0);

	x = 0; y = 0;
	direction = "up";


}

ghost::ghost(int i, int j, string c) {
	cout << "Loading Ghost" << endl;
	killed = false;
	t.loadFromFile("spritesheetGhostNEW30.png");
	spritesheet.left = 0;
	spritesheet.top = 0;
	spritesheet.height = 30;
	spritesheet.width = 30;
	g.setTexture(t);
	g.setTextureRect(spritesheet);
	g.setPosition(i * 30, j * 30);
	if (c == "Red") {
		g.setColor(Color::Red);
		colour = "Red";
	}
	else if (c == "Blue") {
		g.setColor(Color::Blue);
		colour = "Blue";
	}
	else if (c == "Green") {
		g.setColor(Color::Green);
		colour = "Green";
	}
	else if (c == "White") {
		g.setColor(Color::White);
		colour = "White";
	}
	x = i; y = j;
	direction = "up";
	cout << "Ghosts Loaded " << c << endl;

}
ghost::ghost() {

}

//setters

void ghost::initialize(int i, int j, string c) {
	cout << "Loading Ghost" << endl;
	killed = false;
	t.loadFromFile("spritesheetGhostNEW30.png");
	spritesheet.left = 0;
	spritesheet.top = 0;
	spritesheet.height = 30;
	spritesheet.width = 30;
	g.setTexture(t);
	g.setTextureRect(spritesheet);
	g.setPosition(i * 30, j * 30);
	if (c == "Red") {
		g.setColor(Color::Red);
		colour = "Red";
	}
	else if (c == "Blue") {
		g.setColor(Color::Blue);
		colour = "Blue";
	}
	else if (c == "Green") {
		g.setColor(Color::Green);
		colour = "Green";
	}
	else if (c == "White") {
		g.setColor(Color::White);
		colour = "White";
	}
	x = i; y = j;
	direction = "up";
	cout << "Ghosts Loaded " << c << endl;

}
//setters

void ghost::setGhostPosition(int i, int j) {
	x = i; y = j;
	g.setPosition(x, y);

}


void ghost::setDirection(string d) {
	direction = d;
}
void ghost::changeDirection(string d) {
	int r = rand() % 4;
	if (r == 0 && d != "up")
		direction = "up";
	else if (r == 1 && d != "down")
		direction = "down";
	else if (r == 2 && d != "left")
		direction = "left";
	else if (r == 3 && d != "right")
		direction = "right";
}



void ghost::moveGhost(maps m, player pac) {
	if (!killed) {
		if ((x == 10 && y == 9) || (x == 19 && y == 9) || (x == 10 && y == 8) || (x == 9 && y == 8)) {
			g.move(0, -30);
			y--;
		}
		else {
			if (pac.checkCanDie())
				spritesheet.left = 60;
			else {
				if (spritesheet.left == 30)
					spritesheet.left = 0;
				else
					spritesheet.left = 30;
			}



			bool flag = false;
			if (pac.playerDirection() == "up" && pac.getY() < y && !pac.checkImmunity() && !pac.checkCanDie() && !pac.checkBomb()) {
				if (m.isAvailable(x, y - 1)) {
					g.move(0, -30);
					y--;
					flag = true;
					direction = "up";

				}
			}
			else if (pac.playerDirection() == "down" && pac.getY() > y && (!pac.checkImmunity() && !pac.checkCanDie() && !pac.checkBomb())) {
				if (m.isAvailable(x, y + 1)) {
					g.move(0, 30);
					y++;
					flag = true;
					direction = "down";

				}
			}
			else if (pac.playerDirection() == "left" && pac.getX() < x && (!pac.checkImmunity() && !pac.checkCanDie() && !pac.checkBomb())) {
				if (m.isAvailable(x - 1, y)) {
					g.move(-30, 0);
					x--;
					flag = true;
					direction = "left";

				}
			}
			else if (pac.playerDirection() == "right" && pac.getX() > x && (!pac.checkImmunity() && !pac.checkCanDie() && !pac.checkBomb())) {
				if (m.isAvailable(x + 1, y)) {
					g.move(30, 0);
					x++;
					flag = true;
					direction = "right";

				}
			}

			while (!flag) {
				if (direction == "up") {
					if (m.isAvailable(x, y - 1)) {
						g.move(0, -30);
						y--; flag = true;
						if (pac.checkImmunity()) {
							spritesheet.top = 120; g.setColor(Color::White);
						}
						else {
							spritesheet.top = 30;
							if (colour == "Red") {
								g.setColor(Color::Red);
							}
							else if (colour == "Blue") {
								g.setColor(Color::Blue);
							}
							else if (colour == "Green") {
								g.setColor(Color::Green);

							}
							else if (colour == "White") {
								g.setColor(Color::White);

							}
						}
					}
					else changeDirection(direction);
				}
				else if (direction == "down") {
					if (m.isAvailable(x, y + 1)) {
						g.move(0, 30);
						y++;
						flag = true;
						if (pac.checkImmunity()) {
							spritesheet.top = 120; g.setColor(Color::White);
						}
						else {
							spritesheet.top = 90;
							if (colour == "Red") {
								g.setColor(Color::Red);
							}
							else if (colour == "Blue") {
								g.setColor(Color::Blue);
							}
							else if (colour == "Green") {
								g.setColor(Color::Green);

							}
							else if (colour == "White") {
								g.setColor(Color::White);

							}
						}
					}
					else changeDirection(direction);
				}
				else if (direction == "left") {
					if (m.isAvailable(x - 1, y)) {
						g.move(-30, 0);
						x--;
						flag = true;
						if (pac.checkImmunity()) {
							spritesheet.top = 120; g.setColor(Color::White);
						}
						else {
							spritesheet.top = 0;
							if (colour == "Red") {
								g.setColor(Color::Red);
							}
							else if (colour == "Blue") {
								g.setColor(Color::Blue);
							}
							else if (colour == "Green") {
								g.setColor(Color::Green);

							}
							else if (colour == "White") {
								g.setColor(Color::White);

							}
						}
					}
					else changeDirection(direction);
				}
				else {
					if (m.isAvailable(x + 1, y)) {
						g.move(30, 0);
						x++;
						flag = true;
						if (pac.checkImmunity()) {
							spritesheet.top = 120; g.setColor(Color::White);
						}
						else {
							spritesheet.top = 60;
							if (colour == "Red") {
								g.setColor(Color::Red);
							}
							else if (colour == "Blue") {
								g.setColor(Color::Blue);
							}
							else if (colour == "Green") {
								g.setColor(Color::Green);

							}
							else if (colour == "White") {
								g.setColor(Color::White);

							}
						}
					}
					else changeDirection(direction);
				}
			}
		}
	}
	else {
		if (clock.getElapsedTime().asSeconds() < 6) {
			spritesheet.top = 150;
			g.setColor(Color::White);
			if (spritesheet.left == 30)
				spritesheet.left = 0;
			else
				spritesheet.left = 30;

		}
		else {
			killed = false;
			if (colour == "Red") {
				g.setColor(Color::Red);
			}
			else if (colour == "Blue") {
				g.setColor(Color::Blue);
			}
			else if (colour == "Green") {
				g.setColor(Color::Green);

			}
			else if (colour == "White") {
				g.setColor(Color::White);

			}

		}

	}

}


void ghost::drawGhost(sf::RenderWindow& window) {
	g.setTextureRect(spritesheet);
	window.draw(g);
}


//getters
int ghost::getXposition() {

	return x * 30;
}

int ghost::getYposition() {
	return y * 30;;
}
bool ghost::nextMoveAvailable(string d, maps m) {
	if (d == "up")
		return   m.isAvailable(x, y - 1);
	else if (d == "down")
		return   m.isAvailable(x, y + 1);
	else if (d == "left")
		return   m.isAvailable(x - 1, y);
	else
		return m.isAvailable(x + 1, y);
}

bool ghost::checkPlayer(player p, ghost& gh, score& s) {
	int i, j;
	p.getPosition(i, j);

	if (x == i && y == j && !p.checkImmunity() && !p.checkCanDie() && !p.checkBomb() && !killed) {
		s.minusLife();
		return true;

	}
	else if (x == i && y == j && p.checkBomb()) {
		sound.playbomb();
		gh.setGhostPosition(11 * 30, 9 * 30);
		gh.setXY(11, 9);
		cout << "set " << endl;
		return false;
	}
	else if (x == i && y == j && p.checkCanDie()) {
		sound.playswordsound();
		killed = true; clock.restart();
		return false;
	}
	else return false;

}
void ghost::setXY(int i, int j) {
	x = i; y = j;
}




