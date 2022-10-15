#ifndef CROISSANT_PLAYER_H
#define CROISSANT_PLAYER_H

#include "SFML/Graphics.hpp"

#include "../../Resources/ResourceHolder.h"
#include "Inventory/Inventory.h"

class Player : public sf::Transformable, public  sf::Drawable
{

public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    explicit Player(float SPEED);

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /////////////////////////////////// Перемещение ///////////////////////////////////
    void move(float dt, const std::vector<sf::FloatRect>& wallBounds, sf::View *view);
    void resetMoveOptions();
    void checkWallCollision(const std::vector<sf::FloatRect>& wallBounds);
    void checkMove(float dt);

    /////////////////////////////////// Геттеры ///////////////////////////////////
    sf::Sprite getSprite() const {return sprite;}

    /////////////////////////////////// Бой ///////////////////////////////////
    int getHp() const {return hp;}
    int getMaxHp() const {return maxHp;}
    int getProtection() const {return protection;}
    int getDamage() const {return damage;}

    void takeDamage(int dmg) { hp = (hp - dmg >= 0) ? hp - dmg : 0; }

private:
    /* Отрисовка */
    sf::Sprite sprite;

    /* Перемещение */
    sf::Vector2f velocity;
    float speed;

private:
    int damage = 5;

    int hp = 100;
    int maxHp = 100;

    int protection = 0;

public:
    Inventory inventory;

};


#endif //CROISSANT_PLAYER_H
