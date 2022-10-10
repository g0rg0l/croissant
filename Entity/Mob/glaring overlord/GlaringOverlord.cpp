#include "GlaringOverlord.h"

GlaringOverlord::GlaringOverlord(const std::string &name,
                           sf::Vector2f position,
                           sf::Vector2f sizes,
                           const std::string &textureHolderKey,
                           sf::RenderWindow *window)
        : Mob(name, position, sizes, textureHolderKey, window)
{
    visibilityDistance = 50;
    hp = 200;
}
