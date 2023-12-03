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
    sf::Texture worldBackgroundTexture;
    worldBackgroundTexture.loadFromFile("Textures/PA9_BG_refit.png");
    //worldBackgroundTexture.loadFromFile("Textures/tilecounter.png");

    sf::Sprite worldBackground;
    worldBackground.setTexture(worldBackgroundTexture);
    worldBackground.setPosition(-1853, -1950);
    worldBackground.setScale(3, 3);

    sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };
    
    std::vector<sf::RectangleShape> walls;

    // MIDDLE ROOM BORDERS
    Border mRoomTL(sf::Vector2f(50, 0), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }), mRoomTR(sf::Vector2f(575, 0), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }),
        mRoomLT(sf::Vector2f(0, 0), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }), mRoomLB(sf::Vector2f(0, 575), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }),
        mRoomRT(sf::Vector2f(950, 0), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }), mRoomRB(sf::Vector2f(950, 575), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }),
        mRoomBL(sf::Vector2f(50, 950), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }), mRoomBR(sf::Vector2f(575, 950), sf::Vector2f(375, 50), sf::Color{ 140,120,165 });

    // LEFT ROOM BORDERS
    Border leftRoomT(sf::Vector2f(-1250, -400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), leftRoomRT(sf::Vector2f(0, -400), sf::Vector2f(50, 400), sf::Color{ 140,120,165 }),
        leftRoomB(sf::Vector2f(-1250, 1400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), leftRoomRB(sf::Vector2f(0, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });

    // RIGHT ROOM BORDERS
    Border rightRoomT(sf::Vector2f(1000, -400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), rightRoomLT(sf::Vector2f(950, -400), sf::Vector2f(50, 400), sf::Color{ 140,120,165 }),
        rightRoomB(sf::Vector2f(1000, 1400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), rightRoomLB(sf::Vector2f(950, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });

    // GLOBAL BORDERS
    Border globalLeft(sf::Vector2f(-1850, -1500), sf::Vector2f(600, 4000), sf::Color{ 30,142,75 });
    Border globalRight(sf::Vector2f(2250, -1500), sf::Vector2f(600, 4000), sf::Color{ 30,142,75 });
    Border globalTop(sf::Vector2f(-1850, -2000), sf::Vector2f(4700, 500), sf::Color{ 30,142,75 });
    Border globalBot(sf::Vector2f(-1850, 2500), sf::Vector2f(4700, 500), sf::Color{ 49,165,204 });
    


    walls.push_back(mRoomTL);
    walls.push_back(mRoomTR);
    walls.push_back(mRoomLT);
    walls.push_back(mRoomLB);
    walls.push_back(mRoomRT);
    walls.push_back(mRoomRB);
    walls.push_back(mRoomBL);
    walls.push_back(mRoomBR);
    walls.push_back(leftRoomT);
    walls.push_back(leftRoomRT);
    walls.push_back(leftRoomB);
    walls.push_back(leftRoomRB);
    walls.push_back(rightRoomT);
    walls.push_back(rightRoomLT);
    walls.push_back(rightRoomB);
    walls.push_back(rightRoomLB);
    walls.push_back(globalLeft);
    walls.push_back(globalRight);
    walls.push_back(globalTop);
    walls.push_back(globalBot);

    Player character(sf::Vector2f(window.getSize().x / 10, window.getSize().y / 10),
        25.0f);  // Assuming Ball inherits from sf::CircleShape

    float dt;
    sf::Clock dt_clock;

    sf::FloatRect nextPos;

    const float movementSpeed = 200.f;
    sf::Vector2f velocity;
    sf::Texture texture;
    if (texture.loadFromFile("Textures/mario.png")) {
        character.setTexture(&texture);
    }
    else {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    sf::Font font;
    sf::Text text;

    if (font.loadFromFile("Fonts/arial.ttf"))
    {
        text.setFont(font);
    }
    else
    {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    //text.setString("Press \"x\" to Harvest Wood");
    text.setString("Press \"x\" to Harvest Wood");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition({-225,200});

    character.setOutlineColor(sf::Color::Magenta);
    character.setOutlineThickness(2.f);

    window.setFramerateLimit(120);

    //const double HARVEST_DELAY = 1.0;
    //double _lastHarvestTime = 0.0;

    Border test(sf::Vector2f(-300, 300), sf::Vector2f(75, 75), sf::Color::Red);

    while (window.isOpen()) {

        dt = dt_clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::Resized)
        {
            //std::cout << "new width: " << event.size.width << std::endl;
            //std::cout << "new height: " << event.size.height << std::endl;
            camera.setSize(sf::Vector2f(event.size.width, event.size.height));
            window.setView(camera);
        }

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

        text.setString(std::to_string(character.getWoodQuantity()));

        // Update any game logic here
        character.move(velocity);

        // Update the camera/view
        camera.setCenter(character.getPosition().x + 25, character.getPosition().y + 50);
        window.setView(camera);

        // Clear and draw
        //window.clear(sf::Color{ 75,76,76 });
        window.clear();

        sf::Event eventHarvest;

        window.draw(worldBackground);

        for (auto& i : walls)
        {
            window.draw(i);
        }
        if (character.getGlobalBounds().intersects(test.getGlobalBounds())) {
            window.draw(text);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                character.incrementWoodQuantity();
            }
        }

        window.draw(test);
        window.draw(character);
        window.display();
    }

    return 0;
}