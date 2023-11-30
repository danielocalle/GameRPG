//// This example will use SFML libraries to implement
//// the game of Pong
//
//// History: 11/13 - Started from the SFML tutorial code that draws
////                 a circle in the window.
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <windows.h>
//#include "Paddle.h"
//#include "Ball.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");
//	sf::CircleShape shape(100.f);
//	
//	sf::View camera{ {0,0}, static_cast<sf::Vector2f>(window.getSize()) };
//
//	Paddle leftPaddle(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
//		rightPaddle(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta), 
//		rightBotPaddle(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
//		upperPaddle(sf::Vector2f(25, 0), sf::Vector2f(950, 25), sf::Color::Magenta),
//		lowerPaddle(sf::Vector2f(25, 775), sf::Vector2f(950, 25), sf::Color::Magenta);
//
//	Ball gameBall(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
//		leftPaddle.getSize().y / 20, sf::Color::Blue);
//
//	// Set the Mario texture for the game ball
//
//	int directionX = 1;
//	int directionY = 1;
//
//	//shape.setFillColor(sf::Color::Green);
//
//	sf::RectangleShape shapeRect(sf::Vector2f(100.0f, 100.0f));
//	sf::Texture texture;
//
//	if (texture.loadFromFile("C:/CPTS 122 - WSU Fall 2023/Pong/Pong/Pong/Textures/mario.png"))
//	{
//		shapeRect.setTexture(&texture);
//	}
//
//	gameBall.setTexture(&texture);
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//		{
//			//p1Paddle.move(0, 0.05);
//			gameBall.move(0, 0.05);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//		{
//			//p1Paddle.move(0, -0.05);
//			gameBall.move(0, -0.05);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			//p2Paddle.move(0, 0.05);
//			gameBall.move(-0.05, 0);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			//p2Paddle.move(0, -0.05);
//			gameBall.move(0.05, 0);
//		}
//
//
//
//		/*gameBall.move(0.02 * directionX, 0.02 * directionY);*/
//
//		if (rightPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(-0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (rightBotPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(-0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (leftPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (upperPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(0, 0.1);
//		}
//		if (lowerPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(0, -0.1);
//		}
//
//		//sf::View::setCenter(gameBall.getPosition().x, gameBall.getPosition().y);
//
//		camera.setCenter(gameBall.getPosition().x, gameBall.getPosition().y);
//
//		window.setView(camera);
//
//		//view.setCenter(gameBall.getPosition().x, gameBall.getPosition().y);
//
//		//window.setView(camera);
//
//		window.clear();
//		window.draw(leftPaddle);
//		window.draw(rightPaddle);
//		window.draw(rightBotPaddle);
//		window.draw(upperPaddle);
//		window.draw(lowerPaddle);
//		window.draw(gameBall);
//		//window.draw(shape);
//		window.display();
//	}
//
//
//	return 0;
//}

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };

    Paddle leftPaddle(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
        rightPaddle(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta),
        rightBotPaddle(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
        upperPaddle(sf::Vector2f(25, 0), sf::Vector2f(950, 25), sf::Color::Magenta),
        lowerPaddle(sf::Vector2f(25, 775), sf::Vector2f(950, 25), sf::Color::Magenta),
        squareWall(sf::Vector2f(550, 350), sf::Vector2f(100, 100), sf::Color::Cyan);

    Ball gameBall(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
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

        // Collision with walls

        //if ()

        if (rightPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            	gameBall.move(-0.05, 0);
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (rightBotPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            	gameBall.move(-0.05, 0);
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (leftPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            	gameBall.move(0.05, 0);
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (upperPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            	gameBall.move(0, 0.05);
            }
            if (lowerPaddle.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            	gameBall.move(0, -0.05);
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
        window.draw(squareWall);
        window.draw(gameBall);
        window.display();
    }

    return 0;
}
