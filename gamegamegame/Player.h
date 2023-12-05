#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>


class Inventory : public sf::RectangleShape {

public:
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

protected:
	double woodQuantity;
	double metalQuantity;
	double fishQuantity;
	int ingotQuantity;
	double fuelQuantity;
};

class Player : public Inventory {
public:
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

	void setTexture(const sf::Texture* texture) {
		sf::RectangleShape::setTexture(texture);
	}

	void incrementWoodQuantity() {
		woodQuantity += 0.11;
	}
	void incrementMetalQuantity() {
		metalQuantity += 0.108;
	}
	void incrementFishQuantity() {
		fishQuantity += 0.106;
	}
	void incrementIngotQuantity() {
		ingotQuantity++;
	}
	void incrementFuelQuantity() {
		fuelQuantity += 0.02;
	}

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

	bool isRepaired() {
		if (fishThreshold() == true, ingotThreshold() == true, fuelThreshold() == true) {
			return true;
		}
		else {
			return false;
		}
	}
};