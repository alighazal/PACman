#include "stdafx.h"
#include "coins.h"
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

coins::coins() {

}

coins::coins(string map)
{
	int random = rand() % 4;
	everything.loadFromFile("everything.png");
	spritesheet2.top = 0;
	spritesheet2.left = 0;
	spritesheet2.width = 30;
	spritesheet2.height = 30;
	spritesheet.top = 0;
	spritesheet.left = 0;
	spritesheet.width = 30;
	spritesheet.height = 30;
	char k; ifstream f;
	f.open(map);
	if (f.is_open()) {
		cout << "loading coin's map" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				f >> k;
				if (k == '#') {
					// c[i][j].setRadius(10);
					c[i][j].setPosition(j * 30 + 10, i * 30 + 10);
					//c[i][j].setColor(sf::Color::Yellow);
					vc[j][i] = false;

				}
				else if (k == '-') {
					spritesheet.top = 0;
					c[i][j].setTexture(everything);
					c[i][j].setTextureRect(spritesheet);
					spritesheet.top = 0;
					spritesheet.left = 0;
					c[i][j].setPosition(j * 30, i * 30);
					//c[i][j].setColor(sf::Color::Yellow);
					vc[j][i] = true;
					array[j][i] = 0;

				}
				else {
					spritesheet2.left = 0;
					spritesheet2.top = 30 * random;
					c[i][j].setTexture(everything);
					c[i][j].setTextureRect(spritesheet2);
					c[i][j].setPosition(j * 30, i * 30);
					//c[i][j].setColor(sf::Color::Green);
					vc[j][i] = true;
					array[j][i] = 1;
				}

			}
		}
	}
	f.close();
	cout << "coins Loaded" << endl;
}

void coins::drawcoins(sf::RenderWindow& window) {
	int random = 1 + rand() % 3;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (vc[j][i] && array[j][i] == 0) {
				c[i][j].setTextureRect(spritesheet);

				window.draw(c[i][j]);
			}
			else if (vc[j][i] && array[j][i] == 1) {
				c[i][j].setTextureRect(spritesheet2);
				window.draw(c[i][j]);
			}
		}
	}
}

bool coins::noteaten(int x, int y) {
	return (vc[x][y]);
}

void  coins::eat(int x, int y) {
	vc[x][y] = false;
	//  s.increment(); // added score as paramater to incremetn score
}

bool coins::isSpecialCoin(int i, int j) {
	if ((i == 18 && j == 1) || (i == 18 && j == 18) || (i == 1 && j == 1) || (i == 1 && j == 18))
		return true;
	else return false;
}


int coins::kindOfSpecialCoin(int i, int j) {
	// if((i == 18 && j == 1) || (i == 18 && j == 18) || (i == 1 && j == 1) || (i == 1 && j == 18) ){
	if (spritesheet2.top == 30)
		return 1;
	else if (spritesheet2.top == 60)
		return 2;
	else 
		return 3;
}



void coins::spritesheetchange() {
	int random = 1 + rand() % 3;
	if (clock.getElapsedTime().asSeconds() > 1) {
		spritesheet2.top = 30 * random;
		spritesheet2.left = 0;
		spritesheet.top = 0;
		if (spritesheet.left == 0)
			spritesheet.left = 30;
		else
			spritesheet.left = 0;
		clock.restart();
	}

}
void coins::initialize(string map) {
	int random = rand() % 4;
	everything.loadFromFile("everything.png");
	spritesheet2.top = 0;
	spritesheet2.left = 0;
	spritesheet2.width = 30;
	spritesheet2.height = 30;
	spritesheet.top = 0;
	spritesheet.left = 0;
	spritesheet.width = 30;
	spritesheet.height = 30;
	char k; ifstream f;
	f.open(map);
	if (f.is_open()) {
		cout << "loading coin's map" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				f >> k;
				if (k == '#') {
					// c[i][j].setRadius(10);
					c[i][j].setPosition(j * 30 + 10, i * 30 + 10);
					//c[i][j].setColor(sf::Color::Yellow);
					vc[j][i] = false;

				}
				else if (k == '-') {
					spritesheet.top = 0;
					c[i][j].setTexture(everything);
					c[i][j].setTextureRect(spritesheet);
					spritesheet.top = 0;
					spritesheet.left = 0;

					c[i][j].setPosition(j * 30, i * 30);
					//c[i][j].setColor(sf::Color::Yellow);
					vc[j][i] = true;
					array[j][i] = 0;

				}
				else {
					spritesheet2.top = 30 * random;
					c[i][j].setTexture(everything);
					c[i][j].setTextureRect(spritesheet2);
					spritesheet2.left = 0;

					c[i][j].setPosition(j * 30, i * 30);
					//c[i][j].setColor(sf::Color::Green);
					vc[j][i] = true;
					array[j][i] = 1;
				}

			}
		}
	}
	f.close();
	cout << "coins Loaded" << endl;
}