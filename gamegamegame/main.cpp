// ~~~~~~~~~~~~~~~ WORST VACATION ~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Co-Creators: Daniel Calle, Sam Holttum, Anna Feric
// 
// Class:       CPTS 122
// Assignment:  PA9 
// Date:        12/5/2023
//
// Description: RPG STYLE SPEED RUN ESCAPE GAME
// 
// Gameplay Walkthrough: Start in the spawn room, go to the orange rectangle and press "x"
// to go to the main map area. Timer will start to show how long you are taking to escape.
// Go to the southeast corner through the open door towards the beach, find the crashed ship
// and grab the axe sticking out of the ground. Now the left door coming from the main room
// should be open. Go up to the tree and hold "x" to harvest wood. You will need 25 wood to 
// make a pickaxe. With the pickaxe, you should now be able to get into the mine area, which
// is to through the right door coming from the main room. You have a couple options now, either
// grab the empty fuel canister to the left of the furnace and go collect fuel, or start with
// mining some ore, you will need 50 ore to complete the game. Once you have 10 fuel (10 is the
// max you can carry at a time) and 50 ore you can go up to the furnace, hold "x", and notice
// that the resources have been smelted down into ingots. Before you can beat the game, you must
// go collect another 10 fuel, and go to the bottom left of the map on the beach, where you will 
// find a fishing rod on the ground you can pick up next to the fishing hut. With this fishing rod
// you can fish in the designated area, where you will need to catch 10 fish before your escape can
// be completed. Once you have the resources needed, requirements shown in the top right list. You
// can go back to the crashed ship and hold "x" to fill it with your gathered resources and finally
// escape earth. Now you can just close the window and boot it back up to try and get a better 
// escape time.


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