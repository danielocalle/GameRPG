#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"

class Game
{
public:
	Game() {
	}
	~Game() {
	}

	void runGame();
	void initWorld();
	void render();
	void renderWorld();

private:
	sf::RenderWindow* window;

	sf::Texture worldBackgroundTexture;
	sf::Sprite worldBackground;
};