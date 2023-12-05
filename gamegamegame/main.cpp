#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"
#include "Game.h"
#include "Test.h"

int main()
{
    Game app;

    Test t;

    app.runGame();

    t.testGetWoodQuantity();
    t.testIncrementFishQuantity();

    return 0;
}