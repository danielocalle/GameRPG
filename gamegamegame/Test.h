#pragma once

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"
#include "Game.h"

class Test : public Player
{
public: 

	void testGetWoodQuantity(); // tests getWoodQuantity and setWoodQuantity

	void testIncrementFishQuantity();

	void testHasPickaxe();
};

class Test2 : public Spaceship
{
public:

	void testThresholds();

	void testIsRepaired();
};