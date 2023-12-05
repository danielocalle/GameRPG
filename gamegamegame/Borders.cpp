#include "Borders.h"

void Border::enableCollision(Player player, sf::Vector2f& velocity) const
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect wallBounds = getGlobalBounds();

    sf::FloatRect nextPos = playerBounds;
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
            std::cout << "Bottom collision works!" << std::endl;
        }
        // TOP COLLISION
        if (playerBounds.top > wallBounds.top
            && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
        {
            velocity.y = 0.f;
            std::cout << "Top collision works!" << std::endl;
        }
        // RIGHT COLLISION
        if (playerBounds.left < wallBounds.left
            && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            velocity.x = 0.f;
            std::cout << "Right collision works!" << std::endl;
        }
        // LEFT COLLISION
        if (playerBounds.left > wallBounds.left
            && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            velocity.x = 0.f;
            std::cout << "Left collision works!" << std::endl;
        }
    }
}

void Door::enableCollision(Player player, sf::Vector2f& velocity) const
{
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect wallBounds = getGlobalBounds();

    sf::FloatRect nextPos = playerBounds;
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
        }
        // TOP COLLISION
        if (playerBounds.top > wallBounds.top
            && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
        {
            velocity.y = 0.f;
        }
        // RIGHT COLLISION
        if (playerBounds.left < wallBounds.left
            && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            velocity.x = 0.f;
        }
        // LEFT COLLISION
        if (playerBounds.left > wallBounds.left
            && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            velocity.x = 0.f;
        }
    }
}
