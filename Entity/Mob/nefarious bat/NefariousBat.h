#ifndef ENEMY1_H_NEFARIOUSBAT_H
#define ENEMY1_H_NEFARIOUSBAT_H

#include "../Mob.h"

class NefariousBat : public Mob
{
public:
    explicit NefariousBat(const std::string& name,
                          sf::Vector2f position,
                          sf::Vector2f sizes,
                          const std::string& textureHolderKey,
                          sf::RenderWindow* window);
};


#endif //ENEMY1_H_NEFARIOUSBAT_H
