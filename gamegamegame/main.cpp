#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };

    Border leftPaddle(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
        rightPaddle(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta),
        rightBotPaddle(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
        upperPaddle(sf::Vector2f(25, 0), sf::Vector2f(950, 25), sf::Color::Magenta),
        lowerPaddle(sf::Vector2f(25, 775), sf::Vector2f(950, 25), sf::Color::Magenta);

    Player gameBall(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
        25.0f);  // Assuming Ball inherits from sf::CircleShape

    sf::Texture texture;
    if (texture.loadFromFile("Textures/mario.png")) {
        gameBall.setTexture(&texture);
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
            gameBall.move(0, 0.05);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            gameBall.move(0, -0.05);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gameBall.move(-0.05, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gameBall.move(0.05, 0);
        }

        // Update any game logic here

        // Update the camera/view
        camera.setCenter(gameBall.getPosition().x, gameBall.getPosition().y);
        window.setView(camera);

        // Clear and draw
        window.clear();
        window.draw(leftPaddle);
        window.draw(rightPaddle);
        window.draw(rightBotPaddle);
        window.draw(upperPaddle);
        window.draw(lowerPaddle);
        window.draw(gameBall);
        window.display();
    }

    return 0;
}