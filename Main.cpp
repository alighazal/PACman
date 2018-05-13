#include "StartMenu.h"

#include "maps.h"

#include "player.h"

#include <SFML/Graphics.hpp>

#include "coins.h"

#include <sstream>

#include "ghost.h"

#include "sounds.h"

#include "score.h"

#include "level.h"

#include "transitions.h"

#include <fstream>


using namespace sf;



void handleEvent(RenderWindow &window)

{

	Event event;

	while (window.pollEvent(event))

	{

		switch (event.type)

		{

		case Event::Closed:

			window.close();

			break;

		case Event::KeyPressed:

			//if(event.key.code == Keyboard::Space)

			// initialize(window, island, rows, cat1, cat2, cat3, cat4, bridge, mouse);

			break;

		}

	}

}

fstream file("scores.txt", ios::app);

level one(119, 140, 163, "Level One", "map.txt", false);

level two(41, 128, 185, "Level Two", "map.txt", true);

level three(22, 160, 133, " Bonus Level ", "bmap.txt", true);

level four(0, 0, 0, "Level Four", "map2.txt", true);



int main()

{
	sf::RenderWindow window(sf::VideoMode(600, 600), "PacMan"); //1920, 1080
	StartMenu startMenu(window);

	

	// Game initializations code

	while (window.isOpen())

	{

		sf::Event e;

		while (window.pollEvent(e))

		{

			startMenu.handleEvents(e);

			if (startMenu.isGameRunning()) {

				// Game events code

			}

		}



		window.clear();

		startMenu.display();

		if (startMenu.isGameRunning()) {

			one.playlevel(window, 1000);
			
				if (one.GetState() == won){

				two.playlevel(window,1000);

				if (two.GetState() == won)

					three.playlevel(window,1000);
				if (three.GetState() == won) {

					four.playlevel(window, 1000);
				}
				else if (three.GetState() == lost) startMenu.returnToMenu();
				
				if (four.GetState() == won || four.GetState() == lost) {

					startMenu.returnToMenu(); file << startMenu.getUsername() << endl << one.getscore() + two.getscore() + three.getscore() << endl;
				}

				else if (two.GetState() == lost) {

					file << startMenu.getUsername() << endl << one.getscore() + two.getscore() + three.getscore() << endl;

					startMenu.returnToMenu();
				}
			}

			else if (one.GetState() == lost) {
				startMenu.returnToMenu();

				file << startMenu.getUsername() << endl << one.getscore() + two.getscore() + three.getscore() << endl;

			}





		}

		window.display();

	}

		return 0;

}