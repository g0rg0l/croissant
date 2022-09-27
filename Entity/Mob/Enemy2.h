#ifndef CROISSANT_ENEMY2_H
#define CROISSANT_ENEMY2_H

#include "Mob.h"

class Enemy2 : public Mob
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    Enemy2(sf::Vector2f position, const std::string &textureHolderKey, const std::string& name);

    /////////////////////////////////// Создание моба ///////////////////////////////////
    void setPreferences() override; // Загрузка параметров персонажа
};


#endif //CROISSANT_ENEMY2_H
