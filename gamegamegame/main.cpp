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

    // TEST CASES - Commented out so as to not mess with game values

    //t.testGetWoodQuantity();
    //t.testIncrementFishQuantity();
    //t.testHasPickaxe();
    //t2.testThresholds();
    //t2.testIsRepaired();

    app.runGame();

    return 0;
}