#pragma once

//#include <include/SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(const sf::Vector2f& pos, const float &radius) : 
		sf::CircleShape(radius)
	{
		//this->setFillColor(color);
		this->setPosition(pos);
	}

	void setTexture(const sf::Texture* texture)
	{
		sf::CircleShape::setTexture(texture);
	}

	sf::Vector2f getSpeed(void)
	{
		return sf::Vector2f(this->xSpeed, this->ySpeed);
	}

	/*void pMove(void)
	{
		this->move
	}*/

private:
	double xSpeed;
	double ySpeed;
};