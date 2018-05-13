#ifndef GLOBALS_H
#define GLOBALS_H

#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>

void setImage(const std::string & file, sf::Texture & texture, sf::Sprite & sprite, const sf::Vector2f & position);

#endif