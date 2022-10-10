#ifndef ENEMY1_H_CRIMSONIMP_H
#define ENEMY1_H_CRIMSONIMP_H

#include "../Mob.h"

class CrimsonImp : public Mob
{
public:
    explicit CrimsonImp(const std::string& name,
                          sf::Vector2f position,
                          sf::Vector2f sizes,
                          const std::string& textureHolderKey,
                          sf::RenderWindow* window);

};


#endif //ENEMY1_H_CRIMSONIMP_H
