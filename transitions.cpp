#include "stdafx.h"
#include "transitions.h"



transitions::transitions()
{
	
}

void::transitions::initialize(int x, int y ,int z) {
	screen.setSize(Vector2f(600, 600));
	screen.setFillColor(Color::Color(x,y,z));
	lost = true;
	win = true;
	welcome = true; 
	if (font.loadFromFile("sansation.ttf")) {

		t1.setFont(font);
		t1.setFillColor(Color::White);
		t1.setCharacterSize(50);
		t1.setString("HARD LUCK");
		t1.setPosition(175, 250);
		t2.setFont(font);
		t2.setFillColor(Color::White);
		t2.setCharacterSize(50);
		t2.setString("AMAZING");
		t2.setPosition(175, 250);
		t3.setFont(font);
		t3.setFillColor(Color::White);
		t3.setCharacterSize(50);
		t3.setPosition(175, 250);

	}
}

void transitions::setYOULOST(RenderWindow &window) {
	//window.clear();

	int k = 0;

	if (lost) {

		while (k < 2000) {
			//window.clear();
			window.draw(screen);
			window.draw(t1);
			window.display();
			k++;
		}

	}
	lost = false;

	
}

void transitions::setYOUWIN(RenderWindow &window) {
	int m = 0;
	
	if (win) {

		while (m < 2000) {
			
			window.draw(screen);
			window.draw(t2);
			window.display();
			m++;
		}
		std::cout<< "Done";

	}
	win = false;

}

void transitions::setWelcome(RenderWindow &window, std::string x) {
	int k = 0;

	if (welcome) {

		while (k < 2000) {
		window.clear();
		t3.setString(x);
		window.draw(screen);
		window.draw(t3);
		window.display();
		k++;
	}

	}
	welcome = false;
}


