#include "stdafx.h"
#include "level.h"


level::level(int x, int y ,int z, string input, string map, bool flag)
{
	levelname = input;
	pass = null;
	m.initialize(map, x, y, z);
	coin.initialize(map);
	g1.initialize(8, 9, "Red");
	g2.initialize(9, 9, "Green");
	g3.initialize(10, 9, "White");
	if (flag) g4.initialize(11, 9, "Blue");
	s.initialize();
	trans.initialize(x,y,z);
	lives = 3;
	
}
void level::playlevel(RenderWindow &window, int max) {
	
	trans.setWelcome(window, levelname);

	if (lives > 0 ) {
		if (s.getscore() < max) {
			m.drawMap(window);
			coin.drawcoins(window);
			coin.spritesheetchange();
			g1.drawGhost(window);
			g2.drawGhost(window);
			g3.drawGhost(window);
			g4.drawGhost(window);
			s.drawScore(window);
			pac.drawplayer(window);
			

			if (!g1.checkPlayer(pac, g1, s) &&
				!g2.checkPlayer(pac, g2, s) &&
				!g3.checkPlayer(pac, g3, s)) {

				if (pc.getElapsedTime().asMilliseconds() >= 150.0f) {
					pac.move(m, coin, pc, IMMUNE, s);

				}

				if (c.getElapsedTime().asMilliseconds() >= 300.0f) {
					g1.moveGhost(m, pac);
					g2.moveGhost(m, pac);
					g3.moveGhost(m, pac);
					g4.moveGhost(m, pac);
					c.restart();
				}
			}
			else {
				pac.isDead();
				sound.playDyingSound();
				pac.initialize();
				g1.initialize(8, 9, "Red");
				g2.initialize(9, 9, "Green");
				g3.initialize(10, 9, "White");
				g4.initialize(11, 9, "Blue");
				lives--;
			}
		}
		else {
			pass = won;
			trans.setYOUWIN(window);
		}
	}
	else{
		pass = lost;
		trans.setYOULOST(window);
	}
	/*else { trans.setYOUWIN(window); 
	pass = won;
	}*/
}

state level::GetState() {
	return pass;
}

int level::getlives() {
	return lives;
}
int level::getscore() {
	return s.getscore();
}
void level::nullify() {
	pass = null;
}

void level::drawinto(RenderWindow &window) {

	window.clear();
	window.draw(into);
	window.draw(text1);
	window.display();
	
}

level::~level()
{
}
