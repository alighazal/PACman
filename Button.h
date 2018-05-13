#ifndef BUTTON_H
#define BUTTON_H

#include "Globals.h"
using namespace sf;
using namespace std;
class Button
{
private:
	RenderWindow * window;
	Texture texture, hoverTexture;
	Sprite sprite, hoverSprite;
	bool active;
	bool hovered;
	bool displayed;
public:
	Button(const string & imageFilePath, const string & hoverImageFilePath, RenderWindow & window, const Vector2f & position = Vector2f(0, 0), bool active = true, bool display = true);
	void setHover(bool h);
	void setActive(bool active);
	void setDisplay(bool display);
	void display() const;
	bool isActive() const;
	~Button();
};

#endif