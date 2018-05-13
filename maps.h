
#ifndef maps_h
#define maps_h
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class maps {

private:

	sf::RectangleShape m[20][20];
	bool vm[20][20];
	

public:
	//constructor
	maps(string);
	maps();

	//setters
	void drawMap(sf::RenderWindow&);

	void initialize(string m, int x, int y , int z);
	//getters
	bool isAvailable(int, int);

};
#endif /* map_h */