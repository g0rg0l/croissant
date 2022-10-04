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
    sf::Sprite getSprite();

    /////////////////////////////////// Бой ///////////////////////////////////
    int getHp() const {return hp;}
    int getMaxHp() const {return maxHp;}

    void takeDamage(int damage) { hp -= damage;}

private:
    /* Отрисовка */
    sf::Sprite sprite;

    /* Перемещение */
    sf::Vector2f velocity;
    float speed;

private: // Бой
    int hp = 100;
    int maxHp = 100;

public:
    Inventory inventory;

};


#endif //CROISSANT_PLAYER_H
