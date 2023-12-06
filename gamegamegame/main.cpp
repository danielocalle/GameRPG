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
    Test2 t2;

    app.runGame();

    t.testGetWoodQuantity();
    t.testIncrementFishQuantity();

    t2.testThresholds();
    t2.testIsRepaired();

    return 0;
}