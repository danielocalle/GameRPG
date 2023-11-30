#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::CircleShape
{
public:
	Player(const sf::Vector2f& pos, const float &radius) : 
		sf::CircleShape(radius)
	{
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

	bool hasAxe;
	bool hasPickaxe;
	bool hasBucket;

	int numberOfFish;
	int numberOfWood;
	int numberOfMetal;
	int numberOfFuel;
};