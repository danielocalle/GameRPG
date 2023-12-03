#pragma once

#include "SFML/Graphics.hpp"

class Player : public sf::RectangleShape
{
public:
	Player()
	{
		hasAxe = false;
		hasPickaxe = false;
		hasBoatPart = false;
		woodQuantity = 0.0;
		stoneQuantity = 0;
	}
	Player(const sf::Vector2f& pos, const sf::Vector2f& size) :
		sf::RectangleShape(size)
	{
		this->setPosition(pos);
		hasAxe = false;
		hasPickaxe = false;
		hasBoatPart = false;
		woodQuantity = 0.0;
		stoneQuantity = 0;
	}

	void setTexture(const sf::Texture* texture)
	{
		sf::RectangleShape::setTexture(texture);
	}

	int getWoodQuantity() {
		return woodQuantity;
	}

	void incrementWoodQuantity() {
		woodQuantity = woodQuantity + 0.01;
	}

private:
	bool hasAxe;
	bool hasPickaxe;
	bool hasBoatPart;

	double woodQuantity;
	int stoneQuantity;
};