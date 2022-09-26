#include "Enemy2.h"

/////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
Enemy2::Enemy2(sf::Vector2f position, const std::string &textureHolderKey) :
    Mob(position, textureHolderKey)
{
    loadSprite();
    loadPosition();
    setPreferences();
}

/////////////////////////////////// Создание моба ///////////////////////////////////
void Enemy2::setPreferences()
{
    visibilityDistance = 20;
    hp = 100;
}