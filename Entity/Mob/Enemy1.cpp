#include "Enemy1.h"

/////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
Enemy1::Enemy1(sf::Vector2f position, const std::string &textureHolderKey) :
    Mob(position, textureHolderKey)
{
    loadSprite();
    loadPosition();
    setPreferences();
}

/////////////////////////////////// Создание моба ///////////////////////////////////
void Enemy1::setPreferences()
{
    visibilityDistance = 100;
    hp = 50;
}
