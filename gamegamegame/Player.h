#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>


class Inventory : public sf::RectangleShape {

public:

	// constructors
	Inventory() {
		woodQuantity = 0.0;
		metalQuantity = 0.0;
		ingotQuantity = 0;
		fishQuantity = 0.0;
		fuelQuantity = 0.0;
	}
	Inventory(const sf::Vector2f& pos, const sf::Vector2f& size) : sf::RectangleShape(size) {
		this->setPosition(pos);
		woodQuantity = 0.0;
		metalQuantity = 0.0;
		ingotQuantity = 0;
		fishQuantity = 0.0;
		fuelQuantity = 0.0;
	}

	// getters
	int getWoodQuantity() {
		return woodQuantity;
	}
	int getMetalQuantity() {
		return metalQuantity;
	}
	int getFishQuantity() {
		return fishQuantity;
	}
	int getIngotQuantity() {
		return ingotQuantity;
	}
	int getFuelQuantity() {
		return fuelQuantity;
	}

	// setters
	void setWoodQuantity(double newQuantity) {
		woodQuantity = newQuantity;
	}
	void setMetalQuantity(double newQuantity) {
		metalQuantity = newQuantity;
	}
	void setFishQuantity(double newQuantity) {
		fishQuantity = newQuantity;
	}
	void setIngotQuantity(int newQuantity) {
		ingotQuantity = newQuantity;
	}
	void setFuelQuantity(double newQuantity) {
		fuelQuantity = newQuantity;
	}

	// incrementers
	void incrementWoodQuantity() {
		woodQuantity += 0.04;
	}
	void incrementMetalQuantity() {
		metalQuantity += 0.05;
	}
	virtual void incrementFishQuantity() { // virtual because spaceship class redefines it
		fishQuantity += 0.03;
	}
	void incrementIngotQuantity() {
		ingotQuantity++;
	}
	virtual void incrementFuelQuantity() { // also virtual, same reason
		fuelQuantity += 0.045;
	}

protected:
	double woodQuantity;
	double metalQuantity;
	double fishQuantity;
	int ingotQuantity;
	double fuelQuantity;
};

class Player : public Inventory {
public:
	// constructors
	Player()
	{
		hasAxe = false;
		hasPickaxe = false;
		hasBucket = false;
		hasFishingRod = false;
		if (texture.loadFromFile("Textures/ncrguy.png")) {
			sf::RectangleShape::setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load texture!" << std::endl;
		}
	}

	Player(const sf::Vector2f& pos, const sf::Vector2f& size) : Inventory(pos, size)
	{
		hasAxe = false;
		hasPickaxe = false;
		hasBucket = false;
		hasFishingRod = false;
		if (texture.loadFromFile("Textures/ncrguy.png")) {
			sf::RectangleShape::setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load texture!" << std::endl;
		}
	}

	// setters
	void setTexture(const sf::Texture* texture) {
		sf::RectangleShape::setTexture(texture);
	}
	void setHasAxe(bool status) {
		hasAxe = status;
	}
	void setHasFishingRod(bool status) {
		hasFishingRod = status;
	}
	void setHasPickaxe(bool status) {
		hasPickaxe = status;
	}
	void setHasBucket(bool status) {
		hasBucket = status;
	}

	// getters
	bool getHasAxe() {
		return hasAxe;
	}
	bool getHasPickaxe() {
		return hasPickaxe;
	}
	bool getHasFishingRod() {
		return hasFishingRod;
	}
	bool getHasBucket() {
		return hasBucket;
	}

private:
	sf::Texture texture;

	bool hasAxe;
	bool hasPickaxe;
	bool hasFishingRod;
	bool hasBucket;
};

class Spaceship : public Inventory
{
public:
	// thresholds (check resource amount against amount defined needed to "repair" that section)
	bool fishThreshold() {
		if (fishQuantity >= 10) { // 100
			return true;
		}
		else {
			return false;
		}
	}
	bool ingotThreshold() {
		if (ingotQuantity >= 10) { // 50
			return true;
		}
		else {
			return false;
		}
	}
	bool fuelThreshold() {
		if (fuelQuantity >= 10)	{ // 30
			return true;
		}
		else {
			return false;
		}
	}

	// if ship has enough resources to end the game (have all thresholds been met?)
	bool isRepaired() {
		if (fishThreshold() == true && ingotThreshold() == true && fuelThreshold() == true) {
			return true;
		}
		else {
			return false;
		}
	}

	// incrementers
	void incrementFishQuantity() {
		fishQuantity++;
	}
	void incrementFuelQuantity() {
		fuelQuantity++;
	}
};