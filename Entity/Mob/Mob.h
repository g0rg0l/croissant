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
    Mob();

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////

    /* Видит ли игрока */
    bool isSeePlayer(Player &player, const std::vector<sf::FloatRect> &allWallBounds);

private:
    /* Спрайт */
    sf::Sprite sprite;

    /* Дальность видимости */
    const int visDistance = 100;

};


#endif //CROISSANT_MOB_H
