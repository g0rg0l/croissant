#ifndef CROISSANT_PLAYER_H
#define CROISSANT_PLAYER_H

#include "SFML/Graphics.hpp"

#include "../../Resources/ResourceHolder.h"

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

    void takeDamage(int damage) { hp -= damage;}

private:
    /* Спрайт */
    sf::Sprite sprite;

    /* Скорость */
    sf::Vector2f velocity; // Вектор перемещения
    float speed; // Скорость перемещения

    /* Бой */
    int hp = 100;

};


#endif //CROISSANT_PLAYER_H
