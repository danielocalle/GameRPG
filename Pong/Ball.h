#pragma once

//#include <include/SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(const sf::Vector2f& pos, const float &radius, const sf::Color& color) : 
		sf::CircleShape(radius)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

	void setTexture(const sf::Texture* texture)
	{
		sf::CircleShape::setTexture(texture);
	}

private:

};