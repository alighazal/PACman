#ifndef START_MENU_H
#define START_MENU_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include "ButtonCollection.h"
#include "Scoreboard.h"
#include "EnterText.h"

using namespace sf;
using namespace std;

class StartMenu {
private:

	RenderWindow* window;
	Music menu_song;
	bool song_play;
	Texture background_texture;
	Sprite background_sprite;
	Texture score_texture;
	Sprite score_sprite;
	Texture start_texture;
	Sprite start_sprite;
	int menu_displayed;
	string username;
	Button start_button;
	Button score_button;
	Button mute_button;
	Button exit_button;
	Button back_button;
	ButtonCollection StartMenuButtons;
	ButtonCollection back;
	Scoreboard scoreboard;
	EnterText enter_username;
public:
	
	StartMenu(RenderWindow&);
	StartMenu();

	void handleEvents(const Event&);

	void display() const;

	bool isGameRunning() const;
	
	void returnToMenu();
	void showback();
	
	string getUsername() const;
};

#endif