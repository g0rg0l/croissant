#ifndef CROISSANT_ENEMY1_H
#define CROISSANT_ENEMY1_H

#include "Mob.h"

class Enemy1 : public Mob
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    Enemy1(sf::Vector2f position, const std::string &textureHolderKey);

    /////////////////////////////////// Создание моба ///////////////////////////////////
    void setPreferences() override; // Загрузка параметров персонажа
};


#endif //CROISSANT_ENEMY1_H
