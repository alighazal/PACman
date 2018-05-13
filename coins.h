#pragma once


#ifndef coins_h
#define coins_h

#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class coins
{
private:
	sf::Sprite c[20][20];
	bool vc[20][20];
	int count;
	sf::IntRect spritesheet, spritesheet2;
	sf::Texture everything;
	sf::Clock clock;
	int array[20][20];

public:
	coins();
	coins(string map);
	//coins(string map, int size);
	void drawcoins(sf::RenderWindow& window);
	bool noteaten(int x, int y);
	void eat(int, int); // added score parameter
	bool isSpecialCoin(int, int);
	void spritesheetchange();
	void initialize(string map);
	int kindOfSpecialCoin(int, int);
};


#endif