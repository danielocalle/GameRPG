#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

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
		ingotQuantity = 0;
		fishQuantity = 0.0;
		fuelQuantity = 0.0;
		if (texture.loadFromFile("Textures/ncrguy.png")) {
			sf::RectangleShape::setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load texture!" << std::endl;
		}
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
		ingotQuantity = 0;
		fishQuantity = 0.0;
		fuelQuantity = 0.0;
		if (texture.loadFromFile("Textures/ncrguy.png")) {
			sf::RectangleShape::setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load texture!" << std::endl;
		}
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

	void setHasAxe(bool newHasAxe) {
		hasAxe = newHasAxe;
	}

	void setHasFishingRod(bool newHasFishingRod) {
		hasFishingRod = newHasFishingRod;
	}

	void setHasBucket(bool newHasBucket) {
		hasBucket = newHasBucket;
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
	sf::Texture texture;

	bool hasAxe;
	bool hasPickaxe;
	bool hasFishingRod;
	bool hasBucket;

	double woodQuantity;
	double metalQuantity;
	double fishQuantity;
	int ingotQuantity;
	double fuelQuantity;
};