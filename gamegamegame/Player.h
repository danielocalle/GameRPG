#pragma once

#include "SFML/Graphics.hpp"

class Player : public sf::RectangleShape
{
public:
	Player()
	{
		hasAxe = false;
		hasPickaxe = false;
		hasBucket = false;
		hasFishingRod = false;
		woodQuantity = 0.0;
		metalQuantity = 0.0;
		fishQuantity = 0.0;
	}
	Player(const sf::Vector2f& pos, const sf::Vector2f& size) :
		sf::RectangleShape(size)
	{
		this->setPosition(pos);
		hasAxe = false;
		hasPickaxe = false;
		hasBucket = false;
		hasFishingRod = false;
		woodQuantity = 0.0;
		metalQuantity = 0.0;
		fishQuantity = 0.0;
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

	int getMetalQuantity() {
		return metalQuantity;
	}

	void incrementMetalQuantity() {
		metalQuantity = metalQuantity + 0.008;
	}

	int getFishQuantity() {
		return fishQuantity;
	}

	void incrementFishQuantity() {
		fishQuantity = fishQuantity + 0.006;
	}

	void setHasAxe(bool newHasAxe) {
		hasAxe = newHasAxe;
	}

	void setHasFishingRod(bool newHasFishingRod) {
		hasFishingRod = newHasFishingRod;
	}

	bool getHasAxe()
	{
		return hasAxe;
	}

	bool getHasPickaxe()
	{
		return hasPickaxe;
	}

	bool getHasFishingRod()
	{
		return hasFishingRod;
	}

	bool getHasBucket()
	{
		return hasBucket;
	}

private:
	bool hasAxe;
	bool hasPickaxe;
	bool hasFishingRod;
	bool hasBucket;


	double woodQuantity;
	double metalQuantity;
	double fishQuantity;
};