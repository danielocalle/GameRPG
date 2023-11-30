#pragma once

#include "SFML/Graphics.hpp"

class Border : public sf::RectangleShape
{
public:
	Border(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

private:
};