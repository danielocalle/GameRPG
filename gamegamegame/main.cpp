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

    // TEST CASES - Commented out so as to not mess with game values

    //t.testGetWoodQuantity();
    //t.testIncrementFishQuantity();
    //t.testHasPickaxe();

    app.runGame();

    return 0;
}