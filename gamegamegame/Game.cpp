#include "Game.h"



void Game::runGame()
{
    window.setFramerateLimit(120);

    float dt = 0.0;
    sf::Clock dt_clock;

    sf::FloatRect nextPos;

    const float movementSpeed = 450.f;
    sf::Vector2f velocity;

    while (window.isOpen()) {

        dt = dt_clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        velocity.y = 0.f;
        velocity.x = 0.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            //character.move(0, 0.1);
            velocity.y += -movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            //character.move(0, -0.1);
            velocity.y += movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //character.move(-0.1, 0);
            velocity.x += -movementSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //character.move(0.1, 0);
            velocity.x += movementSpeed * dt;
        }

        if (velocity.x < 0) {
            character.setScale(1, 1);
        }
        if (velocity.x > 0) {
            character.setScale(-1, 1);
        }

        for (auto& wall : borders)
        {
            wall.enableCollision(character, velocity);
        }

        leftRoomDoor.enableCollision(character, velocity);
        rightRoomDoor.enableCollision(character, velocity);
        topRoomDoor.enableCollision(character, velocity);

        character.move(velocity);

        camera.setCenter(character.getPosition().x + 25, character.getPosition().y + 50);
        window.setView(camera);

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
            topRoomDoor.move(10000, 10000);
        }

        woodQuantity.setString("Wood Quantity: " + std::to_string(character.getWoodQuantity()));
        metalQuantity.setString("Ore Quantity: " + std::to_string(character.getMetalQuantity()));
        ingotQuantity.setString("Metal Quantity: " + std::to_string(character.getIngotQuantity()));
        fishQuantity.setString("Fish Quantity: " + std::to_string(character.getFishQuantity()));
        //fuelQuantity.setString("Fuel Quantity: " + std::to_string(character.getFuelQuantity()));

        interactWithObjects();
        drawObjects();
    }
}

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
}

void Game::createBorders()
{
    // MIDDLE ROOM BORDERS
    Border mRoomTL(sf::Vector2f(60, -20), sf::Vector2f(375, 75), sf::Color{ 240,120,165 }), mRoomTR(sf::Vector2f(560, -20), sf::Vector2f(380, 75), sf::Color{ 240,120,165 }),
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
}

void Game::createObjects()
{
    harvestTree.loadTexture("Textures/treeForHarvestGood.png");

    harvestIngot.loadTexture("Textures/furnacefinal.png");

    harvestMetal.loadTexture("Textures/miningspot2.png");

    axeBuried.loadTexture("Textures/axeburied.png");

    axeUI.loadTexture("Textures/axeui.png");

    fishingRod.loadTexture("Textures/fishingrod.png");

    fuelCanister.loadTexture("Textures/fuelempty.png");

    compass.loadTexture("Textures/compass.png");

    ship.loadTexture("Textures/shipsand.png");

    fishHut.loadTexture("Textures/fishinghut.png");

    leftRoomDoor.loadTexture("Textures/fence.png");
    rightRoomDoor.loadTexture("Textures/fence.png");

    // No texture, just outline for fishing area

    harvestFish.setOutlineColor({ 73,164,189 });
    harvestFish.setOutlineThickness(10.f);
}

void Game::createPlayer()
{
    // Centering the origin for easier mirroring of the character, for directional facing when moving 
    character.setOrigin(sf::Vector2f(character.getSize().x / 2, character.getSize().y / 2));
}

void Game::createText()
{
    woodText.setString("Hold \"x\" to Harvest Wood");
    metalText.setString("Hold \"x\" to Harvest Ore");
    fishText.setString("Hold \"x\" to Harvest Fish");
    ingotText.setString("Hold \"x\" to Smelt Ore");
}

void Game::createBackground()
{
    worldBackgroundTexture.loadFromFile("Textures/PA9_BG_refit2.png");

    worldBackground.setTexture(worldBackgroundTexture);
    worldBackground.setPosition(-2143, -2450);
    worldBackground.setScale(3, 3);
}

void Game::drawObjects()
{
    window.clear();
    window.draw(worldBackground);

    if (character.getHasAxe() == true)
    {
        axeUI.setFillColor(sf::Color::White);
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

    window.draw(woodText);
    window.draw(metalText);
    window.draw(ingotText);
    window.draw(woodQuantity);
    window.draw(metalQuantity);
    window.draw(ingotQuantity);
    window.draw(fishText);
    window.draw(fishQuantity);

    if (character.getHasAxe() == false) {
        window.draw(leftRoomDoor);
    }
    if (character.getHasPickaxe() == false) {
        window.draw(rightRoomDoor);
    }
    if (character.getHasBucket() == false) {
        window.draw(topRoomDoor);
    }
    window.draw(harvestTree);
    window.draw(harvestMetal);
    window.draw(harvestIngot);

    compass.setPosition(character.getPosition().x - 475, character.getPosition().y + 275);
    window.draw(compass);
    axeUI.setPosition(character.getPosition().x + 300, character.getPosition().y + 350);
    window.draw(axeUI);
    window.draw(character);
    window.display();
}
