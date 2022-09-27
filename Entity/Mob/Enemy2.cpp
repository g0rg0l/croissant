#include "Enemy2.h"

/////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
Enemy2::Enemy2(sf::Vector2f position, const std::string &textureHolderKey, const std::string& name) :
    Mob(position, textureHolderKey, name)
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