#pragma once
#ifndef sounds_h
#define sounds_h



#include "stdafx.h"
#include "coins.h"
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class sounds
{
private:
	SoundBuffer move,die,win,eatghost, bomb, fruit, sword;
	Sound sound;
	

public:
	sounds();
	void playMovingSound();
	void playDyingSound();
	void playGhostEatingSound();
	void playWinningSound();
	void playEatingFruit();
	void playbomb();
	void playswordsound();
	};

#endif // !sounds_h