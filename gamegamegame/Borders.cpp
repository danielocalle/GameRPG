#include "Borders.h"

// makes border objects solid, so player cannot pass through them
// checks if the next frame will make the player and the border intersect (occupy the same space) and if so, sets player's 
// relecant velocity to zero, so they cannot move in that direction.
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

// same thing as border collision
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