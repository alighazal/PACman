#pragma once
#ifndef transitions_h
#define transitions_h

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "score.h"
#include <iostream>

using namespace sf;

class transitions
{
private:

	RectangleShape screen;
	Text t1, t2, t3;
	Font font;
	bool lost, win, welcome;
	
	
public:
	transitions();
	void initialize(int ,int , int);
	void setYOULOST(RenderWindow &window);
	void setYOUWIN(RenderWindow &window );
	void setWelcome(RenderWindow &window, std::string x);

	

};

#endif // !1