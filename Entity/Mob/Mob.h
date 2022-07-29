#ifndef CROISSANT_MOB_H
#define CROISSANT_MOB_H

#include "SFML/Graphics.hpp"
#include <cmath>

#include "../../Resources/ResourceHolder.h"
#include "../Player/Player.h"
#include "../geometrical_functions/mobView.h"

class Mob : public sf::Transformable, public  sf::Drawable
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    Mob(sf::Vector2f coordinates);

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////

    /* Видит ли игрока */
    bool isSeePlayer(Player &player, const std::vector<sf::FloatRect> &allWallBounds);

    /////////////////////////////////// Бой ///////////////////////////////////
    int getHp() {return hp;}

    void getDamage(int damage) {hp -= damage;}

private:
    /* Спрайт */
    sf::Sprite sprite;

    /* Дальность видимости */
    int visDistance = 100;

    /* Бой */
    int hp = 100;

};


#endif //CROISSANT_MOB_H
