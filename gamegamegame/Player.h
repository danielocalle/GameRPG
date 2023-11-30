#pragma once

#include "SFML/Graphics.hpp"

class Player : public sf::RectangleShape
{
public:
	Player(const sf::Vector2f& pos, const float& radius) :
		sf::RectangleShape(pos)
	{
		this->setPosition(pos);
	}

	void setTexture(const sf::Texture* texture)
	{
		sf::RectangleShape::setTexture(texture);
	}

private:

};