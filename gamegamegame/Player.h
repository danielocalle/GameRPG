#pragma once

#include "SFML/Graphics.hpp"

class Player : public sf::CircleShape
{
public:
	Player(const sf::Vector2f& pos, const float& radius) :
		sf::CircleShape(radius)
	{
		this->setPosition(pos);
	}

	void setTexture(const sf::Texture* texture)
	{
		sf::CircleShape::setTexture(texture);
	}

private:

};