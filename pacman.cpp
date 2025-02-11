// pacman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "maps.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include "coins.h"
#include <sstream>
#include "ghost.h"
#include "sounds.h"
#include "score.h"
#include "level.h"




using namespace sf;
int main()
{

	RenderWindow window(sf::VideoMode(600, 600), "PACMAN");


	level one(0, 0, 0);
	transitions t;
	
	while (window.isOpen())
	{
				
		window.pushGLStates();
		window.clear();
		
		
		one.playlevel(window);
		
	
		window.popGLStates();
		window.display();
	}


return 0;
}