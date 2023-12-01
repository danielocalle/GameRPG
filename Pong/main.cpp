//// This example will use SFML libraries to implement
//// the game of Pong
//
//// History: 11/13 - Started from the SFML tutorial code that draws
////                 a circle in the window.
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <windows.h>
//#include "Border.h"
//#include "Ball.h"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");
//	sf::CircleShape shape(100.f);
//	
//	sf::View camera{ {0,0}, static_cast<sf::Vector2f>(window.getSize()) };
//
//	Border leftBorder(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
//		rightBorder(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta), 
//		rightBotBorder(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
//		upperBorder(sf::Vector2f(25, 0), sf::Vector2f(950, 25), sf::Color::Magenta),
//		lowerBorder(sf::Vector2f(25, 775), sf::Vector2f(950, 25), sf::Color::Magenta);
//
//	Ball gameBall(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
//		leftBorder.getSize().y / 20, sf::Color::Blue);
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
//			//p1Border.move(0, 0.05);
//			gameBall.move(0, 0.05);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//		{
//			//p1Border.move(0, -0.05);
//			gameBall.move(0, -0.05);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			//p2Border.move(0, 0.05);
//			gameBall.move(-0.05, 0);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			//p2Border.move(0, -0.05);
//			gameBall.move(0.05, 0);
//		}
//
//
//
//		/*gameBall.move(0.02 * directionX, 0.02 * directionY);*/
//
//		if (rightBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(-0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (rightBotBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(-0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (leftBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(0.1, 0);
//			//directionX *= -1;
//			//directionY *= -1;
//		}
//		if (upperBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
//		{
//			gameBall.move(0, 0.1);
//		}
//		if (lowerBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
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
//		window.draw(leftBorder);
//		window.draw(rightBorder);
//		window.draw(rightBotBorder);
//		window.draw(upperBorder);
//		window.draw(lowerBorder);
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
#include "Border.h"
#include "Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "GameTest");

    sf::View camera{ {0, 0}, static_cast<sf::Vector2f>(window.getSize()) };

    Border leftBorder(sf::Vector2f(0, 0), sf::Vector2f(25, 800), sf::Color::Magenta),
        rightBorder(sf::Vector2f(975, 0), sf::Vector2f(25, 350), sf::Color::Magenta),
        rightBotBorder(sf::Vector2f(975, 450), sf::Vector2f(25, 350), sf::Color::Magenta),
        upperBorder(sf::Vector2f(25, 0), sf::Vector2f(950, 25), sf::Color::Magenta),
        lowerBorder(sf::Vector2f(25, 775), sf::Vector2f(950, 25), sf::Color::Magenta),
        squareWall(sf::Vector2f(550, 350), sf::Vector2f(100, 100), sf::Color::Cyan);

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
            gameBall.setYspeed(0.05);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            gameBall.setYspeed(-0.05);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gameBall.setXspeed(-0.05);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            
            
            gameBall.setXspeed(0.05);
        }

        // Collision with walls

        //if ()

        if (rightBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
            //sf::Vector2f(gameBall.getPosition());

            	gameBall.setSpeed(-1 * gameBall.getXspeed(), -1 * gameBall.getYspeed());
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (rightBotBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
                gameBall.setSpeed(-1 * gameBall.getXspeed(), gameBall.getYspeed());
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (leftBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
                gameBall.setSpeed(-1 * gameBall.getXspeed(), -1 * gameBall.getYspeed());
            	//directionX *= -1;
            	//directionY *= -1;
            }
            if (upperBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
                gameBall.setSpeed(-1 * gameBall.getXspeed(), -1 * gameBall.getYspeed());
            }
            if (lowerBorder.getGlobalBounds().intersects(gameBall.getGlobalBounds()))
            {
                gameBall.setSpeed(0, 0);
            }

        // Update any game logic here

        // Update the camera/view
        camera.setCenter(gameBall.getPosition().x, gameBall.getPosition().y);
        window.setView(camera);

        // Clear and draw
        window.clear();
        window.draw(leftBorder);
        window.draw(rightBorder);
        window.draw(rightBotBorder);
        window.draw(upperBorder);
        window.draw(lowerBorder);
        window.draw(squareWall);
        window.draw(gameBall);
        window.display();
    }

    return 0;
}
