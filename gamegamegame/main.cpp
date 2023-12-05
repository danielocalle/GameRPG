#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"
#include "Game.h"

int main()
{
    //Game wrapper;
    //wrapper.runGame();
    //wrapper.initWorld();
    //wrapper.render();

#if 1

    sf::Texture worldBackgroundTexture;
    worldBackgroundTexture.loadFromFile("Textures/PA9_BG_refit2.png");
    //worldBackgroundTexture.loadFromFile("Textures/tilecounter.png");

    sf::Sprite worldBackground;
    worldBackground.setTexture(worldBackgroundTexture);
    worldBackground.setPosition(-2143, -2450);
    worldBackground.setScale(3, 3);

#endif

    sf::RenderWindow window(sf::VideoMode(1100, 800), "RPG GAME");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };
    //sf::View HUD{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };
    
#if 1

    std::vector<sf::RectangleShape> walls;

    // MIDDLE ROOM BORDERS
    Border mRoomTL(sf::Vector2f(60, -20), sf::Vector2f(375, 75), sf::Color{ 240,120,165 }), mRoomTR(sf::Vector2f(560, -20), sf::Vector2f(380, 75), sf::Color{ 240,120,165 }),
        mRoomLT(sf::Vector2f(-20, -410), sf::Vector2f(80, 830), sf::Color{ 140,120,165 }), mRoomLB(sf::Vector2f(-20, 575), sf::Vector2f(80, 925), sf::Color{ 240,120,165 }),
        mRoomRT(sf::Vector2f(940, -405), sf::Vector2f(75, 835), sf::Color{ 140,120,165 }), mRoomRB(sf::Vector2f(940, 565), sf::Vector2f(75, 930), sf::Color{ 240,120,165 }),
        mRoomBL(sf::Vector2f(60, 935), sf::Vector2f(375, 85), sf::Color{ 140,120,165 }), mRoomBR(sf::Vector2f(565, 935), sf::Vector2f(375, 85), sf::Color{ 140,120,165 });

    // LEFT ROOM BORDERS
    Border leftRoomT(sf::Vector2f(-1285, -410), sf::Vector2f(1265, 85), sf::Color{ 240,120,165 }),
        leftRoomB(sf::Vector2f(-1285, 1415), sf::Vector2f(1265, 85), sf::Color{ 140,120,165 });

    // No longer needed, made longer borders following from the mRoom, might be better with performance as well
    //leftRoomRT(sf::Vector2f(0, -400), sf::Vector2f(50, 400), sf::Color{ 240,120,165 });
    //leftRoomRB(sf::Vector2f(0, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });
    
    // RIGHT ROOM BORDERS
    Border rightRoomT(sf::Vector2f(1015, -405), sf::Vector2f(1270, 70), sf::Color{ 240,120,165 }), 
        rightRoomB(sf::Vector2f(1015, 1425), sf::Vector2f(1270, 70), sf::Color{ 140,220,165 });

    // No longer needed, made longer borders following from the mRoom, might be better with performance as well, less objects good
    //rightRoomLB(sf::Vector2f(950, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });
    //rightRoomLT(sf::Vector2f(950, -400), sf::Vector2f(50, 400), sf::Color{ 240,120,165 }),

    // LAVA BORDERS
    Border lavaUpper(sf::Vector2f(-15, -1480), sf::Vector2f(1025, 90), sf::Color{ 240,120,165 }), 
        lavaMiddle(sf::Vector2f(175, -1390), sf::Vector2f(640, 90), sf::Color{ 140,120,165 }),
        lavaBottom(sf::Vector2f(370, -1300), sf::Vector2f(250, 100), sf::Color{ 240,120,165 });

    // GLOBAL BORDERS
    Border globalLeft(sf::Vector2f(-1885, -1500), sf::Vector2f(600, 3980), sf::Color{ 130,142,75 });
    Border globalRight(sf::Vector2f(2285, -1500), sf::Vector2f(600, 3980), sf::Color{ 130,142,75 });
    Border globalTop(sf::Vector2f(-1885, -1980), sf::Vector2f(4770, 500), sf::Color{ 30,142,75 });
    Border globalBot(sf::Vector2f(-1885, 2480), sf::Vector2f(4770, 500), sf::Color{ 49,165,204 });

    walls.push_back(mRoomTL);
    walls.push_back(mRoomTR);
    walls.push_back(mRoomLT);
    walls.push_back(mRoomLB);
    walls.push_back(mRoomRT);
    walls.push_back(mRoomRB);
    walls.push_back(mRoomBL);
    walls.push_back(mRoomBR);
    walls.push_back(leftRoomT);
    walls.push_back(leftRoomB);

    Border leftRoomDoor(sf::Vector2f(-20, 435), sf::Vector2f(80, 125), sf::Color::White);
    Border rightRoomDoor(sf::Vector2f(940, 445), sf::Vector2f(75, 105), sf::Color::White);
    Border topRoomDoor(sf::Vector2f(445, -35), sf::Vector2f(100, 90), sf::Color::White);

    sf::Texture fenceTexture;
    if (fenceTexture.loadFromFile("Textures/fence.png"))
    {
        leftRoomDoor.setTexture(&fenceTexture);
        rightRoomDoor.setTexture(&fenceTexture);
    }
    else
    {
        std::cerr << "Failed to load fence texture!" << std::endl;
    }

    /*walls.push_back(leftRoomDoor);
    walls.push_back(rightRoomDoor);
    walls.push_back(topRoomDoor);*/

    //walls.push_back(leftRoomRT);
    //walls.push_back(leftRoomRB);
    //walls.push_back(rightRoomLT);
    //walls.push_back(rightRoomLB);

    walls.push_back(rightRoomT);
    walls.push_back(rightRoomB);

    walls.push_back(lavaUpper);
    walls.push_back(lavaMiddle);
    walls.push_back(lavaBottom);

    walls.push_back(globalLeft);
    walls.push_back(globalRight);
    walls.push_back(globalTop);
    walls.push_back(globalBot);

#endif


    Player character(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2), 
        sf::Vector2f(70,80));

    // Centering the origin for easier mirroring of the character, for directional facing when moving 
    character.setOrigin(sf::Vector2f(character.getSize().x / 2, character.getSize().y / 2));

    float dt;
    sf::Clock dt_clock;

    sf::FloatRect nextPos;

    const float movementSpeed = 450.f;
    sf::Vector2f velocity;

    // PLAYER TEXTURE
    sf::Texture texture;
    if (texture.loadFromFile("Textures/ncrguy.png")) {
        character.setTexture(&texture);
    }
    else {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    // TREE TEXTURE
    Border harvestTree(sf::Vector2f(-1050, 75), sf::Vector2f(700, 700), sf::Color::White);

    sf::Texture treeTexture;
    if (treeTexture.loadFromFile("Textures/treeForHarvestGood.png")) {
        harvestTree.setTexture(&treeTexture);
    }
    else {
        std::cerr << "Failed to load tree texture!" << std::endl;
    }

    // FURNACE TEXTURE
    Border harvestIngot(sf::Vector2f(1355, -400), sf::Vector2f(600, 400), sf::Color::White);

    sf::Texture ingotTexture; // more code below needed
    if (ingotTexture.loadFromFile("Textures/furnacefinal.png")) {
        harvestIngot.setTexture(&ingotTexture);
    }
    else {
        std::cerr << "Failed to load furnace texture!" << std::endl;
    }

    
    // METAL(MINES AREA SHIT) TEXTURE
    Border harvestMetal(sf::Vector2f(1355, 675), sf::Vector2f(780,700), sf::Color::White);
    sf::Texture metalTexture; // more code below needed
    if (metalTexture.loadFromFile("Textures/miningspot2.png")) {
        harvestMetal.setTexture(&metalTexture);
    }
    else {
        std::cerr << "Failed to load metalzone texture!" << std::endl;
    }

    // DOOR TEXTURE


    // COMPASS TEXTURE
    Border compass(sf::Vector2f(0, 0), sf::Vector2f(150, 150), sf::Color::White);
    
    sf::Texture compassTexture;
    if (compassTexture.loadFromFile("Textures/compass.png")) {
        compass.setTexture(&compassTexture);
    }
    else {
        std::cerr << "Failed to load compass texture!" << std::endl;
    }

    // SHIP TEXTURE
    Border ship(sf::Vector2f(1300, 1600), sf::Vector2f(600, 300), sf::Color::White);

    sf::Texture shipTexture;
    if (shipTexture.loadFromFile("Textures/shipsand.png")) {
        ship.setTexture(&shipTexture);
    }
    else {
        std::cerr << "Failed to load ship texture!" << std::endl;
    }

    Border fishHut(sf::Vector2f(-700, 1450), sf::Vector2f(300, 400), sf::Color::White);

    sf::Texture fishHutTexture;
    if (fishHutTexture.loadFromFile("Textures/fishinghut.png")) {
        fishHut.setTexture(&fishHutTexture);
    }
    else {
        std::cerr << "Failed to load fish hut texture!" << std::endl;
    }

    Border harvestFish(sf::Vector2f(-850, 2110), sf::Vector2f(600, 365), sf::Color::Transparent);

    harvestFish.setOutlineColor({ 73,164,189 });
    harvestFish.setOutlineThickness(10.f);


    sf::Font font;
    sf::Text woodText;
    sf::Text woodQuantity;
    sf::Text metalText;
    sf::Text metalQuantity;
    sf::Text fishText;
    sf::Text fishQuantity;
    sf::Text ingotText;
    sf::Text ingotQuantity;
    sf::Text fuelText;
    sf::Text fuelQuantity;


    if (font.loadFromFile("Fonts/dotumche-pixel.ttf"))
    {
        woodText.setFont(font);
        woodQuantity.setFont(font);
        metalText.setFont(font);
        metalQuantity.setFont(font);
        ingotText.setFont(font);
        ingotQuantity.setFont(font);
        fishText.setFont(font);
        fishQuantity.setFont(font);
    }
    else
    {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    woodQuantity.setCharacterSize(30);
    woodQuantity.setFillColor(sf::Color::White);
    woodQuantity.setStyle(sf::Text::Bold);
    woodQuantity.setPosition({-950,750});

    metalQuantity.setCharacterSize(30);
    metalQuantity.setFillColor(sf::Color::White);
    metalQuantity.setStyle(sf::Text::Bold);
    metalQuantity.setPosition({ 1450,350 });

    ingotQuantity.setCharacterSize(30);
    ingotQuantity.setFillColor(sf::Color::White);
    ingotQuantity.setStyle(sf::Text::Bold);
    ingotQuantity.setPosition({ 1450,250 });

    woodText.setString("Hold \"x\" to Harvest Wood");
    woodText.setCharacterSize(30);
    woodText.setFillColor(sf::Color::White);
    woodText.setStyle(sf::Text::Bold);
    woodText.setPosition({-950,700});

    metalText.setString("Hold \"x\" to Harvest Ore");
    metalText.setCharacterSize(30);
    metalText.setFillColor(sf::Color::White);
    metalText.setStyle(sf::Text::Bold);
    metalText.setPosition({ 1450,600 });

    ingotText.setString("Hold \"x\" to Smelt Ore");
    ingotText.setCharacterSize(30);
    ingotText.setFillColor(sf::Color::White);
    ingotText.setStyle(sf::Text::Bold);
    ingotText.setPosition({ 1420,0 });

    fishText.setString("Hold \"x\" to Harvest Fish");
    fishText.setCharacterSize(30);
    fishText.setFillColor(sf::Color::Black);
    fishText.setStyle(sf::Text::Bold);
    fishText.setPosition({ -825,1990 });

    //character.setOutlineColor(sf::Color::Magenta);
    //character.setOutlineThickness(2.f);

    window.setFramerateLimit(120);

    //const double HARVEST_DELAY = 1.0;
    //double _lastHarvestTime = 0.0;

    while (window.isOpen()) {

        dt = dt_clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Code that lets the window be resized and then increases the view in game, but it is buggy and we dont want to be able to see so much

        //if (event.type == sf::Event::Resized)
        //{
        //    //std::cout << "new width: " << event.size.width << std::endl;
        //    //std::cout << "new height: " << event.size.height << std::endl;
        //    camera.setSize(sf::Vector2f(event.size.width, event.size.height));
        //    window.setView(camera);
        //}

        velocity.y = 0.f;
        velocity.x = 0.f;

        // Handle user input or game logic to move the object
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

        for (auto& wall : walls)
        {
            sf::FloatRect playerBounds = character.getGlobalBounds();
            sf::FloatRect wallBounds = wall.getGlobalBounds();

            nextPos = playerBounds;
            nextPos.left += velocity.x;
            nextPos.top += velocity.y;

            if (wallBounds.intersects(nextPos))
            {
                // BOTTOM COLLISION
                if (playerBounds.top < wallBounds.top
                    && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                    && playerBounds.left < wallBounds.left + wallBounds.width
                    && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    velocity.y = 0.f;
                    //character.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                }
                // TOP COLLISION
                if (playerBounds.top > wallBounds.top
                    && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                    && playerBounds.left < wallBounds.left + wallBounds.width
                    && playerBounds.left + playerBounds.width > wallBounds.left)
                {
                    velocity.y = 0.f;
                    //character.setPosition(playerBounds.left, wallBounds.top - wallBounds.height);
                }
                // RIGHT COLLISION
                if (playerBounds.left < wallBounds.left
                    && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                    && playerBounds.top < wallBounds.top + wallBounds.height
                    && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    velocity.x = 0.f;
                    //character.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
                }
                // LEFT COLLISION
                if (playerBounds.left > wallBounds.left
                    && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                    && playerBounds.top < wallBounds.top + wallBounds.height
                    && playerBounds.top + playerBounds.height > wallBounds.top)
                {
                    velocity.x = 0.f;
                    //character.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
                }
            }
        }

        woodQuantity.setString("Wood Quantity: " + std::to_string(character.getWoodQuantity()));

        metalQuantity.setString("Ore Quantity: " + std::to_string(character.getMetalQuantity()));

        ingotQuantity.setString("Metal Quantity: " + std::to_string(character.getIngotQuantity()));

        fuelQuantity.setString("Fuel Quantity: " + std::to_string(character.getFuelQuantity()));

        // Update any game logic here
        character.move(velocity);


        // Update the camera/view
        camera.setCenter(character.getPosition().x + 25, character.getPosition().y + 50);
        window.setView(camera);

        // Clear and draw
        //window.clear(sf::Color{ 75,76,76 });
        window.clear();

        window.draw(worldBackground);

        //draws borders to screen (not needed in final version, map shows "borders")
        //for (auto& i : walls)
        //{
        //    window.draw(i);
        //}

        if (character.getGlobalBounds().intersects(harvestTree.getGlobalBounds())) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                character.incrementWoodQuantity();
            }
        }
        if (character.getGlobalBounds().intersects(harvestMetal.getGlobalBounds())) {
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


        if (character.getHasAxe() == true)
        {
            walls[10].move(10000, 10000);
            leftRoomDoor.move(10000, 10000);
        }

        if (character.getHasPickaxe() == true)
        {
            walls[11].move(10000, 10000);
            rightRoomDoor.move(10000, 10000);
        }

        if (character.getHasBucket() == true)
        {
            walls[12].move(10000, 10000);
            topRoomDoor.move(10000, 10000);
        }

        //window.draw(lavaUpper);
        //window.draw(lavaMiddle);
        //window.draw(lavaBottom);

        window.draw(leftRoomDoor);
        window.draw(rightRoomDoor);
        window.draw(topRoomDoor);

        window.draw(ship);
        window.draw(fishHut);
        window.draw(harvestFish);
        window.draw(woodText);
        window.draw(metalText);
        window.draw(ingotText);
        window.draw(woodQuantity);
        window.draw(metalQuantity);
        window.draw(ingotQuantity);
        window.draw(harvestTree);
        window.draw(harvestMetal);
        window.draw(harvestIngot);
        compass.setPosition(character.getPosition().x - 475, character.getPosition().y + 275);
        window.draw(compass);
        window.draw(character);
        window.display();
    }

    return 0;
}