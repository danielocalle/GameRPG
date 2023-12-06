#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include <string>

// things with collision (walls)
class Border : public sf::RectangleShape
{
public:
	Border(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

	void enableCollision(Player player, sf::Vector2f& velocity) const;

private:

};

// objects in game world that can usually be interacted with. almost always have a texture
class Object : public sf::RectangleShape
{
public:
	Object(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

	// loads object texture from a file from the textures folder
	void loadTexture(std::string fileName) {
		if (texture.loadFromFile(fileName)) {
			setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load tree texture!" << std::endl;
		}
	}

private:
	sf::Texture texture;
};

// objects with collision that are moved outside the map based off an external check (if player has relevant tool)
class Door : public sf::RectangleShape
{
public:
	Door(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) :
		RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

	// loads texture from file
	void loadTexture(std::string fileName) {
		if (texture.loadFromFile(fileName)) {
			setTexture(&texture);
		}
		else {
			std::cerr << "Failed to load texture!" << std::endl;
		}
	}

	void enableCollision(Player player, sf::Vector2f& velocity) const;

private:
	sf::Texture texture;
};

// text that is present in the game world (unmoving, on the ground)
class GameText : public sf::Text
{
public:
	GameText() {
		// loads custom font (dotumche pixel) from file in fonts folder
		if (font.loadFromFile("Fonts/dotumche-pixel.ttf")) {
			setFont(font);
		}
		else {
			std::cerr << "Failed to load font!";
		}
		setCharacterSize(30);
		setFillColor(sf::Color::White);
		setStyle(sf::Text::Bold);
		setPosition(sf::Vector2f(0, 0));
	}
	GameText(int size, sf::Color color, sf::Text::Style style, sf::Vector2f pos) {
		if (font.loadFromFile("Fonts/dotumche-pixel.ttf")) {
			setFont(font);
		}
		else {
			std::cerr << "Failed to load font!";
		}
		setCharacterSize(size);
		setFillColor(color);
		setStyle(style);
		setPosition(pos);
	}

private:
	sf::Font font;
};