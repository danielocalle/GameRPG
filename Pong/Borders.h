#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

private:
};