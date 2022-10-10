#ifndef ENEMY1_H_SPIKEDRAVAGER_H
#define ENEMY1_H_SPIKEDRAVAGER_H

#include "../Mob.h"

class SpikedRavager : public Mob
{
public:
    explicit SpikedRavager(const std::string& name,
                        sf::Vector2f position,
                        sf::Vector2f sizes,
                        const std::string& textureHolderKey,
                        sf::RenderWindow* window);
};


#endif //ENEMY1_H_SPIKEDRAVAGER_H
