#include "Game.h"


void Game::runGame()
{
    window.setFramerateLimit(120);

    // Movement stuff
    float dt = 0.0;
    sf::Clock dt_clock;

    // Track time it takes to escape earth
    sf::Clock clock;

    // Used for collision
    sf::FloatRect nextPos;
    
    // Setting movement speed, and velocity is used for movement
    const float movementSpeed = 350.f;
    sf::Vector2f velocity;

    // Spawning the character in the starting spawn room
    character.setPosition(550,-3700);

    // Loop for the actual game
    while (window.isOpen()) {

        dt = dt_clock.restart().asSeconds();

        // Event to stop the game if window is closed
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        velocity.y = 0.f;
        velocity.x = 0.f;

        // Movement keys
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            velocity.y += -movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            velocity.y += movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocity.x += -movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x += movementSpeed * dt;
        }

        // Mirroring the player texture to give the appearance of directional movement
        if (velocity.x < 0) {
            character.setScale(1, 1);
        }
        if (velocity.x > 0) {
            character.setScale(-1, 1);
        }

        // Loop for accessing the fixed walls and applying collision to them
        for (auto& wall : borders)
        {
            wall.enableCollision(character, velocity);
        }

        // Separate collision for the doors
        leftRoomDoor.enableCollision(character, velocity);
        rightRoomDoor.enableCollision(character, velocity);
        topRoomDoor.enableCollision(character, velocity);

        // moving the player using the velocity set above with WASD
        character.move(velocity);

        // Keeps the camera centered on the player
        camera.setCenter(character.getPosition().x + 25, character.getPosition().y + 50);
        window.setView(camera);

        // Moves the doors when conditions are met
        if (character.getHasAxe() == true)
        {
            leftRoomDoor.move(0, -500);
        }
        if (character.getHasPickaxe() == true)
        {
            rightRoomDoor.move(0, -500);
        }
        if (character.getHasBucket() == true)
        {
            topRoomDoor.move(0, -1600);
        }

        // UI Quantities
        woodQuantity.setString("Wood: " + std::to_string(character.getWoodQuantity()));
        metalQuantity.setString("Ore: " + std::to_string(character.getMetalQuantity()));
        ingotQuantity.setString("Metal: " + std::to_string(character.getIngotQuantity()));
        fishQuantity.setString("Fish: " + std::to_string(character.getFishQuantity()));
        fuelQuantity.setString("Fuel: " + std::to_string(character.getFuelQuantity()));

        woodQuantity2.setString("Wood: " + std::to_string(character.getWoodQuantity()));
        metalQuantity2.setString("Ore: " + std::to_string(character.getMetalQuantity()));
        ingotQuantity2.setString("Metal: " + std::to_string(character.getIngotQuantity()));
        fuelQuantity2.setString("Fuel: " + std::to_string(character.getFuelQuantity()));
        fishQuantity2.setString("Fish: " + std::to_string(character.getFishQuantity()));

        shipIngotQuantity.setString(std::to_string(brokenShip.getIngotQuantity()) + "/10 Metal");
        shipFuelQuantity.setString(std::to_string(brokenShip.getFuelQuantity()) + "/10 Fuel");
        shipFishQuantity.setString(std::to_string(brokenShip.getFishQuantity()) + "/10 Fish");

        shipIngotQuantity2.setString(std::to_string(brokenShip.getIngotQuantity()) + "/10 Metal");
        shipFuelQuantity2.setString(std::to_string(brokenShip.getFuelQuantity()) + "/10 Fuel");
        shipFishQuantity2.setString(std::to_string(brokenShip.getFishQuantity()) + "/10 Fish");

        // Interacting with all the harvesting stuff, and crafting
        interactWithObjects();

        // Interact with teleporter in spawn room
        if (character.getGlobalBounds().intersects(teleportToSpawn.getGlobalBounds())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                character.setPosition(500, 500);
                clock.restart();
            }
        }
        // Interact with the ship when at the end of the game
        if (character.getGlobalBounds().intersects(ship.getGlobalBounds())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && brokenShip.isRepaired() == true)
            {
                /// teleport to ending room
                character.setPosition(sf::Vector2f(600, 5350));
                std::string temp = std::to_string(clock.getElapsedTime().asSeconds());
                temp.erase(temp.length() - 3);
                endGameTotalCompletionTime.setString("It took you " + temp + " seconds to escape!");
            }
        }
        // Draw all other objects, pass in clock to allow me to display the time at the top of the screen
        drawObjects(clock);
    }
}

// General if statements for certain actions
void Game::interactWithObjects()
{
    if (character.getGlobalBounds().intersects(harvestTree.getGlobalBounds()) && character.getHasAxe() == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            character.incrementWoodQuantity();
        }
    }
    if (character.getGlobalBounds().intersects(harvestMetal.getGlobalBounds()) && character.getHasPickaxe() == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            character.incrementMetalQuantity();
        }
    }
    if (character.getGlobalBounds().intersects(harvestIngot.getGlobalBounds()) && character.getMetalQuantity() >= 5
        && character.getFuelQuantity() >= 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            character.incrementIngotQuantity();
            character.setMetalQuantity(character.getMetalQuantity() - 5);
            character.setFuelQuantity(character.getFuelQuantity() - 1);
        }
    }
    if (character.getGlobalBounds().intersects(harvestFish.getGlobalBounds()) && character.getHasFishingRod() == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            character.incrementFishQuantity();
        }
    }
    if (character.getGlobalBounds().intersects(harvestFuel.getGlobalBounds()) && character.getHasBucket() == true
        && character.getFuelQuantity() < 10) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            character.incrementFuelQuantity();
        }
    }
    if (character.getGlobalBounds().intersects(axeBuried.getGlobalBounds()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character.setHasAxe(true);
        }
    }
    if (character.getGlobalBounds().intersects(fishingRod.getGlobalBounds()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character.setHasFishingRod(true);
        }
    }
    if (character.getGlobalBounds().intersects(fuelCanister.getGlobalBounds()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character.setHasBucket(true);
        }
    }
    if (character.getGlobalBounds().intersects(crafter.getGlobalBounds()) && character.getWoodQuantity() >= 25
        && character.getHasPickaxe() == false)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            character.setHasPickaxe(true);
            character.setWoodQuantity(character.getWoodQuantity() - 25);
        }
    }
    if (character.getGlobalBounds().intersects(ship.getGlobalBounds()))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (character.getFuelQuantity() >= 1 || character.getIngotQuantity() >= 1
            || character.getFishQuantity() >= 1) && brokenShip.isRepaired() == false) 
        {
            if (brokenShip.fuelThreshold() == false && character.getFuelQuantity() >= 1)
            {
                character.setFuelQuantity(character.getFuelQuantity() - 1);
                brokenShip.incrementFuelQuantity();
            }
            if (brokenShip.ingotThreshold() == false && character.getIngotQuantity() >= 1)
            {
                character.setIngotQuantity(character.getIngotQuantity() - 1);
                brokenShip.incrementIngotQuantity();
            }
            if (brokenShip.fishThreshold() == false && character.getFishQuantity() >= 1)
            {
                character.setFishQuantity(character.getFishQuantity() - 1);
                brokenShip.incrementFishQuantity();
            }
        }
    }
}

// Borders that line up with the background texture
void Game::createBorders()
{
    // MIDDLE ROOM BORDERS
    Border mRoomTL(sf::Vector2f(60, -20), sf::Vector2f(375, 90), sf::Color{ 240,120,165 }), mRoomTR(sf::Vector2f(560, -20), sf::Vector2f(380, 90), sf::Color{ 240,120,165 }),
        mRoomLT(sf::Vector2f(-20, -410), sf::Vector2f(80, 830), sf::Color{ 140,120,165 }), mRoomLB(sf::Vector2f(-20, 575), sf::Vector2f(80, 925), sf::Color{ 240,120,165 }),
        mRoomRT(sf::Vector2f(940, -405), sf::Vector2f(75, 835), sf::Color{ 140,120,165 }), mRoomRB(sf::Vector2f(940, 565), sf::Vector2f(75, 930), sf::Color{ 240,120,165 }),
        mRoomBL(sf::Vector2f(60, 935), sf::Vector2f(375, 85), sf::Color{ 140,120,165 }), mRoomBR(sf::Vector2f(565, 935), sf::Vector2f(375, 85), sf::Color{ 140,120,165 });

    // LEFT ROOM BORDERS
    Border leftRoomT(sf::Vector2f(-1285, -410), sf::Vector2f(1265, 85), sf::Color{ 240,120,165 }),
        leftRoomB(sf::Vector2f(-1285, 1415), sf::Vector2f(1265, 85), sf::Color{ 140,120,165 });

    // RIGHT ROOM BORDERS
    Border rightRoomT(sf::Vector2f(1015, -405), sf::Vector2f(1270, 70), sf::Color{ 240,120,165 }),
        rightRoomB(sf::Vector2f(1015, 1425), sf::Vector2f(1270, 70), sf::Color{ 140,220,165 });

    // LAVA BORDERS
    Border lavaUpper(sf::Vector2f(-15, -1480), sf::Vector2f(1025, 90), sf::Color{ 240,120,165 }),
        lavaMiddle(sf::Vector2f(175, -1390), sf::Vector2f(640, 90), sf::Color{ 140,120,165 }),
        lavaBottom(sf::Vector2f(370, -1300), sf::Vector2f(250, 100), sf::Color{ 240,120,165 });

    // GLOBAL BORDERS
    Border globalLeft(sf::Vector2f(-1885, -1500), sf::Vector2f(600, 3980), sf::Color{ 130,142,75 });
    Border globalRight(sf::Vector2f(2285, -1500), sf::Vector2f(600, 3980), sf::Color{ 130,142,75 });
    Border globalTop(sf::Vector2f(-1885, -1980), sf::Vector2f(4770, 500), sf::Color{ 30,142,75 });
    Border globalBot(sf::Vector2f(-1885, 2480), sf::Vector2f(4770, 500), sf::Color{ 49,165,204 });

    // GAME START AREA
    Border topStart{ sf::Vector2f(-200, -4000), sf::Vector2f(1600, 100), sf::Color{ 130,142,75 } };
    Border rightStart{ sf::Vector2f(1300, -3900), sf::Vector2f(100, 900), sf::Color{ 30,242,75 } };
    Border leftStart{ sf::Vector2f(-200, -3900), sf::Vector2f(100, 900), sf::Color{ 30,142,175 } };
    Border bottomStart{ sf::Vector2f(-100, -3100), sf::Vector2f(1400, 100), sf::Color{ 230,142,75 } };

    // GAME END AREA
    Border endRoomTop(sf::Vector2f(-200, 4900), sf::Vector2f(1600, 100), sf::Color::White);
    Border endRoomRight(sf::Vector2f(1300, 4900), sf::Vector2f(100, 900), sf::Color::White);
    Border endRoomLeft(sf::Vector2f(-200, 4900), sf::Vector2f(100, 900), sf::Color::White);
    Border endRoomBottom(sf::Vector2f(-100, 5700), sf::Vector2f(1400, 100), sf::Color::White);

    // Pushing all the borders to a vector, which is a private member of Game
    borders.push_back(mRoomTL);
    borders.push_back(mRoomTR);
    borders.push_back(mRoomLT);
    borders.push_back(mRoomLB);
    borders.push_back(mRoomRT);
    borders.push_back(mRoomRB);
    borders.push_back(mRoomBL);
    borders.push_back(mRoomBR);
    borders.push_back(leftRoomT);
    borders.push_back(leftRoomB);
    borders.push_back(rightRoomT);
    borders.push_back(rightRoomB);
    borders.push_back(lavaUpper);
    borders.push_back(lavaMiddle);
    borders.push_back(lavaBottom);
    borders.push_back(globalLeft);
    borders.push_back(globalRight);
    borders.push_back(globalTop);
    borders.push_back(globalBot);
    borders.push_back(topStart);
    borders.push_back(rightStart);
    borders.push_back(leftStart);
    borders.push_back(bottomStart);
    borders.push_back(endRoomTop);
    borders.push_back(endRoomRight);
    borders.push_back(endRoomLeft);
    borders.push_back(endRoomBottom);
}

// Intitializing textures for most objects, used in the constructor of Game
void Game::createObjects()
{
    harvestTree.loadTexture("Textures/treeForHarvestGood.png");
    harvestIngot.loadTexture("Textures/furnacefinal.png");
    harvestMetal.loadTexture("Textures/miningspot2.png");
    harvestFuel.loadTexture("Textures/lavapump.png");
    crafter.loadTexture("Textures/crafter.png");
    axeBuried.loadTexture("Textures/axeburied.png");

    axeUI.loadTexture("Textures/axeui.png");
    pickaxeUI.loadTexture("Textures/pickaxe.png");
    canisterUI.loadTexture("Textures/fuelcapsule.png");
    fishingRodUI.loadTexture("Textures/fishingrod.png");
    fishingRodUI.setRotation(130.f);

    fishingRod.loadTexture("Textures/fishingrod.png");
    fuelCanister.loadTexture("Textures/fuelempty.png");
    compass.loadTexture("Textures/compass.png");
    ship.loadTexture("Textures/shipsand.png");
    fishHut.loadTexture("Textures/fishinghut.png");

    leftRoomDoor.loadTexture("Textures/fence.png");
    rightRoomDoor.loadTexture("Textures/fence.png");
    topRoomDoor.loadTexture("Textures/volcanodoor.png");

    gameName.loadTexture("Textures/worstvacation.png");

    // No texture, just outline for fishing area

    harvestFish.setOutlineColor({ 73,164,189 });
    harvestFish.setOutlineThickness(10.f);
}

void Game::createPlayer()
{
    // Centering the origin for easier mirroring of the character, for directional facing when moving 
    character.setOrigin(sf::Vector2f(character.getSize().x / 2, character.getSize().y / 2));
}

// Initializing strings for fixed text, used in the constructor for Game
void Game::createText()
{
    woodText.setString("Hold \"x\" to Harvest Wood");
    metalText.setString("Hold \"x\" to Harvest Ore");
    fishText.setString("Hold \"x\" to Harvest Fish");
    ingotText.setString("Hold \"x\" to Smelt Ore");
    fuelText.setString("Hold \"x\" to Pump Fuel");
    pickaxeRecipe.setString("25 Wood = Pickaxe");
    furnaceRecipe.setString("1 Fuel + 5 Ore = 1 Metal");
    std::string temp = "          ~~~ Instructions ~~~\n\nYou have crash landed on an island,\n";
    temp += "you must complete certain objectives to\nunlock new rooms and progress\n";
    temp += "through the game.\nYour first objective is to find the axe.\n";
    temp += "It was last seen onboard the ship.\nThe ship should be just South-East of spawn.\n\n";
    temp += "Press \"X\" to pick up objects.\nHold \"X\" to harvest resources.\n\n";
    temp += "Stand on the orange rectangle and\nPress \"X\" to teleport to spawn and\nbegin exploring.";
    gameStartInstructions.setString(temp);
    shipRepairs.setString("Ship Repairs");
    shipRepairs2.setString("Ship Repairs");
    endGameText.setString("You Escaped Earth!");
}

// Initializing the main background and the end room background
void Game::createBackground()
{
    worldBackgroundTexture.loadFromFile("Textures/backgroundHoleFilled.png");

    worldBackground.setTexture(worldBackgroundTexture);
    worldBackground.setPosition(-2143, -2450);
    worldBackground.setScale(3, 3);

    // ENDROOM TEXTURE

    endRoomBackgroundTexture.loadFromFile("Textures/endroom.png");

    endRoomBackground.setTexture(endRoomBackgroundTexture);
    endRoomBackground.setPosition(-100, 5000);
    endRoomBackground.setScale(2.75, 2);
}

// Draws most objects, used in the main runGame() loop
void Game::drawObjects(sf::Clock& clock)
{
    window.clear();
    window.draw(worldBackground);
    window.draw(endRoomBackground);

    if (character.getHasAxe() == true)
    {
        axeUI.setFillColor(sf::Color::White);
    }
    if (character.getHasPickaxe() == true)
    {
        pickaxeUI.setFillColor(sf::Color::White);
    }
    if (character.getHasBucket() == true)
    {
        canisterUI.setFillColor(sf::Color::White);
    }
    if (character.getHasFishingRod() == true)
    {
        fishingRodUI.setFillColor(sf::Color::White);
    }

    if (brokenShip.fuelThreshold() == true)
    {
        shipFuelQuantity.setFillColor(sf::Color::Green);
    }
    if (brokenShip.fishThreshold() == true)
    {
        shipFishQuantity.setFillColor(sf::Color::Green);
    }
    if (brokenShip.ingotThreshold() == true)
    {
        shipIngotQuantity.setFillColor(sf::Color::Green);
    }
    if (brokenShip.isRepaired() == true)
    {
        shipRepairs.setFillColor(sf::Color::Green);
    }

    window.draw(ship);
    if (character.getHasAxe() == false) {
        window.draw(axeBuried);
    }
    if (character.getHasFishingRod() == false) {
        window.draw(fishingRod);
    }
    if (character.getHasBucket() == false) {
        window.draw(fuelCanister);
    }
    window.draw(fishHut);
    window.draw(harvestFish);

    window.draw(gameStartInstructions);
    window.draw(teleportToSpawn);

    window.draw(gameName);

    window.draw(endGameText);

    window.draw(endGameTotalCompletionTime);

    window.draw(woodText);
    window.draw(metalText);
    window.draw(ingotText);
    window.draw(fishText);
    window.draw(fuelText);

    if (character.getHasAxe() == false) {
        window.draw(leftRoomDoor);
    }
    if (character.getHasPickaxe() == false) {
        window.draw(rightRoomDoor);
    }
    if (character.getHasBucket() == false) {
        window.draw(topRoomDoor);
    }
    window.draw(harvestFuel);
    window.draw(harvestTree);
    window.draw(harvestMetal);
    window.draw(harvestIngot);
    window.draw(harvestFish);

    window.draw(crafter);
    window.draw(pickaxeRecipe);

    window.draw(furnaceRecipe);

    //for (auto& wall : borders) {
    //    window.draw(wall);
    //}


    // Mimic UI just by moving all the UI objects with the player

    compass.setPosition(character.getPosition().x - 475, character.getPosition().y + 275);
    
    fishQuantity.setPosition(character.getPosition().x - 475, character.getPosition().y - 325);
    woodQuantity.setPosition(character.getPosition().x - 475, character.getPosition().y - 275);
    metalQuantity.setPosition(character.getPosition().x - 475, character.getPosition().y - 225);
    fuelQuantity.setPosition(character.getPosition().x - 475, character.getPosition().y - 175);
    ingotQuantity.setPosition(character.getPosition().x - 475, character.getPosition().y - 125);

    fishQuantity2.setPosition(character.getPosition().x - 473, character.getPosition().y - 323);
    woodQuantity2.setPosition(character.getPosition().x - 473, character.getPosition().y - 273);
    metalQuantity2.setPosition(character.getPosition().x - 473, character.getPosition().y - 223);
    fuelQuantity2.setPosition(character.getPosition().x - 473, character.getPosition().y - 173);
    ingotQuantity2.setPosition(character.getPosition().x - 473, character.getPosition().y - 123);

    shipFishQuantity.setPosition(character.getPosition().x + 275, character.getPosition().y - 275);
    shipFuelQuantity.setPosition(character.getPosition().x + 275, character.getPosition().y - 225);
    shipIngotQuantity.setPosition(character.getPosition().x + 275, character.getPosition().y - 175);

    shipFishQuantity2.setPosition(character.getPosition().x + 277, character.getPosition().y - 273);
    shipFuelQuantity2.setPosition(character.getPosition().x + 277, character.getPosition().y - 223);
    shipIngotQuantity2.setPosition(character.getPosition().x + 277, character.getPosition().y - 173);

    shipRepairs.setPosition(character.getPosition().x + 275, character.getPosition().y - 325);
    shipRepairs2.setPosition(character.getPosition().x + 277, character.getPosition().y - 323);

    axeUI.setPosition(character.getPosition().x + 180, character.getPosition().y + 335);
    fishingRodUI.setPosition(character.getPosition().x + 400, character.getPosition().y + 375);
    pickaxeUI.setPosition(character.getPosition().x + 385, character.getPosition().y + 350);
    canisterUI.setPosition(character.getPosition().x + 490, character.getPosition().y + 365);

    ongoingClock.setPosition(character.getPosition().x - 60, character.getPosition().y - 320);
    ongoingClock2.setPosition(character.getPosition().x - 58, character.getPosition().y - 318);

    // Only draw UI if player is inside the main world, using a big object that spans the main world area
    if (character.getGlobalBounds().intersects(inMainAreaChecker.getGlobalBounds()))
    {
        window.draw(compass);

        window.draw(woodQuantity2);
        window.draw(metalQuantity2);
        window.draw(ingotQuantity2);
        window.draw(fishQuantity2);
        window.draw(fuelQuantity2);

        window.draw(woodQuantity);
        window.draw(metalQuantity);
        window.draw(ingotQuantity);
        window.draw(fishQuantity);
        window.draw(fuelQuantity);

        window.draw(shipIngotQuantity2);
        window.draw(shipFishQuantity2);
        window.draw(shipFuelQuantity2);

        window.draw(shipIngotQuantity);
        window.draw(shipFishQuantity);
        window.draw(shipFuelQuantity);

        window.draw(shipRepairs2);
        window.draw(shipRepairs);

        window.draw(axeUI);
        window.draw(fishingRodUI);
        window.draw(pickaxeUI);
        window.draw(canisterUI);

        std::string temp = std::to_string(clock.getElapsedTime().asSeconds());

        temp.erase(temp.length() - 3);

        ongoingClock.setString(temp);
        ongoingClock2.setString(temp);
        window.draw(ongoingClock2);
        window.draw(ongoingClock);
    }

    window.draw(character);
    window.display();
}