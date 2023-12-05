#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Borders.h"
#include "Game.h"

int main()
{
    Game app;

    app.runGame();

#if 0

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

    fishQuantity.setCharacterSize(30);
    fishQuantity.setFillColor(sf::Color::Black);
    fishQuantity.setStyle(sf::Text::Bold);
    fishQuantity.setPosition({ -825,2040 });

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

#endif

#if 0
        woodQuantity.setString("Wood Quantity: " + std::to_string(character.getWoodQuantity()));

        metalQuantity.setString("Ore Quantity: " + std::to_string(character.getMetalQuantity()));

        ingotQuantity.setString("Metal Quantity: " + std::to_string(character.getIngotQuantity()));

        fuelQuantity.setString("Fuel Quantity: " + std::to_string(character.getFuelQuantity()));

        fishQuantity.setString("Fish Quantity: " + std::to_string(character.getFishQuantity()));
#endif

#if 0

        if (character.getHasAxe() == true)
        {
            walls[10].move(10000, 10000);
            leftRoomDoor.move(10000, 10000);
            axeUI.setFillColor(sf::Color::White);
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

#endif

#if 0

        window.draw(leftRoomDoor);
        window.draw(rightRoomDoor);
        window.draw(topRoomDoor);

#endif

    



    return 0;
}