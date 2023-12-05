#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"

class Game
{
public:
	Game() {
		createBorders();
		createObjects();
		createText();
		createBackground();
		createPlayer();
	}
	~Game() {
	}

	void runGame();

	const std::vector<Border>& getBorders() const {
		return borders;
	}

	sf::Sprite getWorldBackground() {
		return worldBackground;
	}

private:
	std::vector<Border> borders;

	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;

	sf::RenderWindow window{ sf::VideoMode(1100, 800), "RPG GAME" };
	sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };

	Player character{ sf::Vector2f(400, 500), sf::Vector2f(70, 80) };

	void createBorders();
	void createObjects();
	void createPlayer();
	void createText();
	void createBackground();
	void drawObjects();
	void interactWithObjects();

	Object harvestTree{ sf::Vector2f(-1050, -300), sf::Vector2f(700, 700), sf::Color::White };
	Object harvestIngot{ sf::Vector2f(1355, -400), sf::Vector2f(600, 400), sf::Color::White };
	Object harvestMetal{ sf::Vector2f(1355, 675), sf::Vector2f(780, 700), sf::Color::White };
	Object harvestFuel{ sf::Vector2f(160, -1400), sf::Vector2f(200, 200), sf::Color::White };
	Object axeBuried{ sf::Vector2f(1470, 1800), sf::Vector2f(75, 75), sf::Color::White };
	Object fishingRod{ sf::Vector2f(-1050, 1700), sf::Vector2f(100, 100), sf::Color::White };
	Object fuelCanister{ sf::Vector2f(1150, -200), sf::Vector2f(60, 60), sf::Color::White };
	Object ship{ sf::Vector2f(1300, 1600), sf::Vector2f(600, 300), sf::Color::White };
	Object fishHut{ sf::Vector2f(-700, 1450), sf::Vector2f(300, 400), sf::Color::White };
	Object harvestFish{ sf::Vector2f(-850, 2110), sf::Vector2f(600, 365), sf::Color::Transparent };

	Object crafter{ sf::Vector2f(-1050, 700), sf::Vector2f(100, 80), sf::Color::White };

	Door leftRoomDoor{ sf::Vector2f(-20, 435), sf::Vector2f(80, 125), sf::Color::White };
	Door rightRoomDoor{ sf::Vector2f(940, 445), sf::Vector2f(75, 105), sf::Color::White };
	Door topRoomDoor{ sf::Vector2f(445, -35), sf::Vector2f(100, 90), sf::Color::White };

	GameText woodText{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(-950,375) };
	GameText metalText{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1450,600) };
	GameText fishText{ 30, sf::Color::Black, sf::Text::Bold, sf::Vector2f(-825,1990) };
	GameText ingotText{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1420,0) };
	GameText fuelText{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(170,-1170) };


	// UI STUFF
	Object compass{ sf::Vector2f(0, 0), sf::Vector2f(150, 150), sf::Color::White };
	Object axeUI{ sf::Vector2f(1470, 1800), sf::Vector2f(100, 100), sf::Color::Black };
	Object pickaxeUI{ sf::Vector2f(1470, 1800), sf::Vector2f(75, 75), sf::Color::Black };
	Object canisterUI{ sf::Vector2f(1470, 1800), sf::Vector2f(50, 50), sf::Color::Black };
	Object fishingRodUI{ sf::Vector2f(1470, 1800), sf::Vector2f(100, 100), sf::Color::Black };

	GameText woodQuantity{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(-950,750) };
	GameText metalQuantity{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1450,350) };
	GameText fishQuantity{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1450,350) };
	GameText ingotQuantity{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1450,250) };
	GameText fuelQuantity{ 30, sf::Color::White, sf::Text::Bold, sf::Vector2f(1450,350) };

	GameText woodQuantity2{ 30, sf::Color::Black, sf::Text::Bold, sf::Vector2f(-950,750) };
	GameText metalQuantity2{ 30, sf::Color::Black , sf::Text::Bold, sf::Vector2f(1450,350) };
	GameText fishQuantity2{ 30, sf::Color::Black, sf::Text::Bold, sf::Vector2f(1450,350) };
	GameText ingotQuantity2{ 30, sf::Color::Black, sf::Text::Bold, sf::Vector2f(1450,250) };
	GameText fuelQuantity2{ 30, sf::Color::Black, sf::Text::Bold, sf::Vector2f(1450,350) };

};