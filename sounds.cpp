#include "stdafx.h"
#include "sounds.h"


sounds::sounds()
{
	move.loadFromFile("SFX/pacman_chomp.wav");
	die.loadFromFile("SFX/pacman_death.wav");
	eatghost.loadFromFile("SFX/pacman_eatghost.wav");
	win.loadFromFile("SFX/pacman_intermission.wav");
	bomb.loadFromFile("SFX/Bomb.wav");
	fruit.loadFromFile("SFX/pacman_eatfruit.wav");
	sword.loadFromFile("SFX/steelsword.wav");
}

void sounds::playbomb() {

	sound.setBuffer(bomb);
	sound.play();
}

void sounds::playswordsound() {

	sound.setBuffer(sword);
	sound.play();
}

void sounds::playMovingSound() {
	sound.setBuffer(move);
	sound.play();
}
void sounds::playDyingSound() {
	sound.setBuffer(die);
	sound.play();
}
void sounds::playGhostEatingSound() {
	sound.setBuffer(eatghost);
	sound.play();

}
void sounds::playWinningSound() {
	sound.setBuffer(win);
	sound.play();

}
void sounds::playEatingFruit() {

	sound.setBuffer(fruit);
	sound.play();
}