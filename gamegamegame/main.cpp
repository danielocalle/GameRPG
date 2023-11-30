#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };

    /*Border leftPaddle(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
        rightPaddle(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta),
        rightBotPaddle(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
        upperPaddle(sf::Vector2f(0, 0), sf::Vector2f(2000, 500), sf::Color::Magenta),
        lowerPaddle(sf::Vector2f(0, 2000), sf::Vector2f(2000, 500), sf::Color::Magenta);*/

    Border mRoomTL(sf::Vector2f(50, 0), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }), mRoomTR(sf::Vector2f(575, 0), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }),
        mRoomLT(sf::Vector2f(0, 0), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }), mRoomLB(sf::Vector2f(0, 575), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }),
        mRoomRT(sf::Vector2f(950, 0), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }), mRoomRB(sf::Vector2f(950, 575), sf::Vector2f(50, 425), sf::Color{ 140,120,165 }),
        mRoomBL(sf::Vector2f(50, 950), sf::Vector2f(375, 50), sf::Color{ 140,120,165 }), mRoomBR(sf::Vector2f(575, 950), sf::Vector2f(375, 50), sf::Color{ 140,120,165 });

    Border leftRoomT(sf::Vector2f(-1250, -400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), leftRoomRT(sf::Vector2f(0, -400), sf::Vector2f(50, 400), sf::Color{ 140,120,165 }),
        leftRoomB(sf::Vector2f(-1250, 1400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), leftRoomRB(sf::Vector2f(0, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });

    Border rightRoomT(sf::Vector2f(1000, -400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), rightRoomLT(sf::Vector2f(950, -400), sf::Vector2f(50, 400), sf::Color{ 140,120,165 }),
        rightRoomB(sf::Vector2f(1000, 1400), sf::Vector2f(1250, 50), sf::Color{ 140,120,165 }), rightRoomLB(sf::Vector2f(950, 1000), sf::Vector2f(50, 450), sf::Color{ 140,120,165 });

    //GLOBAL LARGE BORDERS
    Border globalLeft(sf::Vector2f(-1850, -1500), sf::Vector2f(600, 4000), sf::Color{ 30,142,75 });
    Border globalRight(sf::Vector2f(2250, -1500), sf::Vector2f(600, 4000), sf::Color{ 30,142,75 });
    Border globalTop(sf::Vector2f(-1850, -2000), sf::Vector2f(4700, 500), sf::Color{ 30,142,75 });
    Border globalBot(sf::Vector2f(-1850, 2500), sf::Vector2f(4700, 500), sf::Color{ 49,165,204 });

    Player character(sf::Vector2f(window.getSize().x / 10, window.getSize().y / 10),
        25.0f);  // Assuming Ball inherits from sf::CircleShape

    sf::Texture texture;
    if (texture.loadFromFile("Textures/mario.png")) {
        character.setTexture(&texture);
    }
    else {
        std::cerr << "Failed to load texture!" << std::endl;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle user input or game logic to move the object
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            character.move(0, 0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            character.move(0, -0.1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            character.move(-0.1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            character.move(0.1, 0);
        }

        // Update any game logic here

        // Update the camera/view
        camera.setCenter(character.getPosition().x + 25, character.getPosition().y + 50);
        window.setView(camera);

        // Clear and draw
        window.clear(sf::Color{ 75,76,76 });
        window.draw(mRoomTL);
        window.draw(mRoomTR);
        window.draw(mRoomLT);
        window.draw(mRoomLB);
        window.draw(mRoomRT);
        window.draw(mRoomRB);
        window.draw(mRoomBL);
        window.draw(mRoomBR);
        window.draw(leftRoomT);
        window.draw(leftRoomRT);
        window.draw(leftRoomB);
        window.draw(leftRoomRB);
        window.draw(rightRoomT);
        window.draw(rightRoomLT);
        window.draw(rightRoomB);
        window.draw(rightRoomLB);
        window.draw(globalRight);
        window.draw(globalTop);
        window.draw(globalBot);
        window.draw(globalLeft);
        window.draw(character);
        window.display();
    }

    return 0;
}