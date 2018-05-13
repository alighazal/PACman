#include "Globals.h"

void setImage(const std::string & file, sf::Texture & texture, sf::Sprite & sprite, const sf::Vector2f & position)
{
	if (texture.loadFromFile(file))
	{
		sprite.setTexture(texture);
		sprite.setPosition(position);
	}
	else
		std::cerr << "Failed to open " << file << '\n';
}