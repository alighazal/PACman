#include "Button.h"

Button::Button(const std::string & file, const std::string & hoverFile, sf::RenderWindow & w, const sf::Vector2f & pos, bool act, bool display)
{
	hovered = false;
	active = act;
	displayed = display;
	setImage(file, texture, sprite, pos);
	setImage(hoverFile, hoverTexture, hoverSprite, pos);
	window = &w;
}

void Button::setActive(bool act)
{
	active = act;
}

void Button::setHover(bool h) {
	hovered = h;
}

void Button::setDisplay(bool display) {
	displayed = display;
}

void Button::display() const
{
	if (displayed) {
		if (hovered)
			window->draw(hoverSprite);
		else
			window->draw(sprite);
	}
}

bool Button::isActive() const {
	return active;
}

Button::~Button()
{
}