#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "maps.h"



using namespace std;

//constructor

maps::maps(string name) {
	char c; ifstream f;
	f.open(name);
	if (f.is_open()) {
		cout << "loading map" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				f >> c;
				if (c == '#') {
					m[i][j].setSize(sf::Vector2f(30, 30));
					m[i][j].setPosition(j * 30, i * 30);
					m[i][j].setFillColor(sf::Color::Color(52, 73, 94));
					vm[j][i] = false;
				}
				else {
					m[i][j].setSize(sf::Vector2f(30, 30));
					m[i][j].setPosition(j * 30, i * 30);
					m[i][j].setFillColor(sf::Color::Color(236, 240, 241));
					vm[j][i] = true;
				}

			}


		}


	}
	f.close();
	cout << "Map Loaded" << endl;
}
void maps::initialize(string name, int x, int y, int z) {
	char c; ifstream f;
	f.open(name);
	if (f.is_open()) {
		cout << "loading map" << endl;
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				f >> c;
				if (c == '#') {
					m[i][j].setSize(sf::Vector2f(30, 30));
					m[i][j].setPosition(j * 30, i * 30);
					m[i][j].setFillColor(sf::Color::Color(x, y, z));
					vm[j][i] = false;
				}
				else {
					m[i][j].setSize(sf::Vector2f(30, 30));
					m[i][j].setPosition(j * 30, i * 30);
					m[i][j].setFillColor(sf::Color::Color(236, 240, 241));
					vm[j][i] = true;
				}

			}


		}
	}
	f.close();
	cout << "Map Loaded" << endl;
}


maps::maps() {

}

void maps::drawMap(sf::RenderWindow& window) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			window.draw(m[i][j]);
		}
	}
}

bool maps::isAvailable(int x, int y) {
	return (vm[x][y]);
}


