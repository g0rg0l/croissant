#ifndef CROISSANT_MOB_H
#define CROISSANT_MOB_H

#include "SFML/Graphics.hpp"
#include <cmath>

#include "../../Resources/ResourceHolder.h"
#include "../Player/Player.h"
#include "../geometrical_functions/mobView.h"

class Mob : public  sf::Drawable
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    explicit Mob(const std::string& name, sf::Vector2f position, sf::Vector2f sizes, const std::string& textureHolderKey, sf::RenderWindow* window);

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void updateSprite();

    /////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////
    bool isSeePlayer(Player* player, const std::vector<sf::FloatRect> &allWallBounds);

public:
    std::string getName() {return name;}
    int getHp() const {return hp;}
    sf::Vector2f getSizes() {return sizes;}

public:
    void takeDamage(int damage) { hp -= damage;}

protected:
    sf::RenderWindow* window;

    /* Спрайт */
    std::string textureHolderKey;
    sf::Sprite sprite;
    sf::Vector2f sizes;
    int textureFramesCount;
    sf::Clock animationClock;
    float currentSpriteFrame = 0;

    /* Бой */
    int visibilityDistance = 0;
    int hp = 0;

    /* Информация */
    std::string name;
};


#endif //CROISSANT_MOB_H
