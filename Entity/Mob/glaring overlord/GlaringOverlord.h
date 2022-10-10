#ifndef ENEMY1_H_GLARINGOVERLORD_H
#define ENEMY1_H_GLARINGOVERLORD_H

#include "../Mob.h"

class GlaringOverlord : public Mob
{
public:
    explicit GlaringOverlord(const std::string& name,
                          sf::Vector2f position,
                          sf::Vector2f sizes,
                          const std::string& textureHolderKey,
                          sf::RenderWindow* window);
};


#endif //ENEMY1_H_GLARINGOVERLORD_H
