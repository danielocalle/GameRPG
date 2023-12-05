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
		woodQuantity = 0.0;
		metalQuantity = 0;
		ingotQuantity = 0;
	}
	Player(const sf::Vector2f& pos, const sf::Vector2f& size) :
		sf::RectangleShape(size)
	{
		this->setPosition(pos);
		hasAxe = false;
		hasPickaxe = false;
		hasBucket = false;
		woodQuantity = 0.0;
		metalQuantity = 0;
		ingotQuantity = 0;
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

	void setMetalQuantity(int newQuantity) {
		metalQuantity = newQuantity;
	}

	int getFishQuantity() {
		return fishQuantity;
	}

	void incrementFishQuantity() {
		fishQuantity = fishQuantity + 0.006;
	}

	int getIngotQuantity() {
		return ingotQuantity;
	}

	void incrementIngotQuantity() {
		ingotQuantity++;
	}

	int getFuelQuantity() {
		return fuelQuantity;
	}

	void incrementFuelQuantity() {
		fuelQuantity += 0.05;
	}

	void setFuelQuantity(double newQuantity) {
		fuelQuantity = newQuantity;
	}

	bool getHasAxe()
	{
		return hasAxe;
	}

	bool getHasPickaxe()
	{
		return hasPickaxe;
	}

	bool getHasBucket()
	{
		return hasBucket;
	}

private:
	bool hasAxe;
	bool hasPickaxe;
	bool hasBucket;

	double woodQuantity;
	double metalQuantity;
	double fishQuantity;
	int ingotQuantity;
	double fuelQuantity;
};