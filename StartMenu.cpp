#include "StartMenu.h"

StartMenu::StartMenu(RenderWindow& w) : start_button("Button_start1.png", "Button_start21.png", w, Vector2f(225, 200)),
                                        score_button("Button_score.png", "Button_score2.png", w, Vector2f(225, 275)),
	                                    mute_button("Button_mute.png", "Button_mute2.png", w, Vector2f(220, 350)),
	                                    exit_button("Button_exit1.png", "Button_exit21.png", w, Vector2f(220, 420)),
	                                    back_button("Button_back1.png", "Button_back1.png", w, Vector2f(50, 50), false, false),
	                                    back(false),
	                                    scoreboard(w),
	                                    enter_username(w),
                                        song_play(true),
                                        menu_displayed(0) {
	window = &w;
	if (menu_song.openFromFile("dubstep.ogg")) {
		menu_song.play();
		menu_song.setLoop(true);
	}
	song_play = true;

	background_texture.loadFromFile("menu1.png");
	background_sprite.setTexture(background_texture);
	score_texture.loadFromFile("scores_menu1.png");
	score_sprite.setTexture(score_texture);
	start_texture.loadFromFile("start_game1.png");
	start_sprite.setTexture(start_texture);

	StartMenuButtons.addButton(start_button);
	StartMenuButtons.addButton(score_button);
	StartMenuButtons.addButton(mute_button);
	StartMenuButtons.addButton(exit_button);

	back.addButton(back_button);
}



void StartMenu::handleEvents(const Event& e) {
	bool scores = false;
	if (e.type == Event::Closed)
		window->close();
	switch (StartMenuButtons.buttonClicked(e)) {
	case 0:															//Start Menu case
		menu_displayed = 2;
		StartMenuButtons.setActive(false);				//Disables start menu buttons (key presses)
		StartMenuButtons.setDisplay(false);				// Disables start menu sprites (images/pictures)
		menu_song.stop();							//disables music
		song_play = false;
		enter_username.setActive(true);
		scores = true;
		break;
	case 1:												//Score case;
		menu_displayed = 1;
		StartMenuButtons.setActive(false);				//Disables start menu buttons
		StartMenuButtons.setDisplay(false);				//Diables start menu sprites
		back.setDisplay(true);							//enables back button (key press)
		back.setActive(true);							//enables back button sprite
		scoreboard.setDisplay(true);					//enables scoreboard visually
		scores = true;
		break;
	case 2:
		if (song_play) {
			menu_song.stop();
			song_play = false;
		}
		else {
			menu_song.play();
			song_play = true;
			menu_song.setLoop(true);
		}
		break;
	case 3:
		window->close();
		break;
	}
	if (!scores) {
		if (back.buttonClicked(e) == 0) {
			back.setDisplay(false);
			back.setActive(false);
			StartMenuButtons.setActive(true);
			StartMenuButtons.setDisplay(true);
			scoreboard.setDisplay(false);
			menu_displayed = 0;
		}
		if (enter_username.textEntered(e)) {
			username = enter_username.getText();
			enter_username.setActive(false);
			menu_displayed = 3;
		}
	}
}

void StartMenu::display() const {
	switch (menu_displayed) {
		case 0:
			window->draw(background_sprite);
			break;
		case 1:
			window->draw(score_sprite);
			break;
		case 2:
			window->draw(start_sprite);
			break;
	}
	StartMenuButtons.display();
	back.display();
	scoreboard.display();
	enter_username.display();
}

bool StartMenu::isGameRunning() const {
	return menu_displayed == 3;
}

void StartMenu::returnToMenu() {				//to return to menu from game
	StartMenuButtons.setActive(true);
	StartMenuButtons.setDisplay(true);
	menu_displayed = 0;
	menu_song.play();
	menu_song.setLoop(true);
	song_play = true;
}

string StartMenu::getUsername() const {   //for scores.txt
	return username;
}