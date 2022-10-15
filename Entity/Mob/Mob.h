#ifndef CROISSANT_MOB_H
#define CROISSANT_MOB_H

#include "SFML/Graphics.hpp"
#include <cmath>

#include "../../Resources/ResourceHolder.h"
#include "../Player/Player.h"
#include "../mathematica/mathematica.h"

class Mob : public  sf::Drawable
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    explicit Mob(std::string name, sf::Vector2f sizes, sf::RenderWindow* window);

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void updateSprite();

    /////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////
    bool isSeePlayer(Player* player, const std::vector<sf::FloatRect> &allWallBounds);

public:
    std::string getName() const {return name;}
    int getDamage() const {return damage;}
    double getRangeOfDamageMultiplier() const {return rangeOfDamageMultiplier;}
    int getHp() const {return hp;}
    sf::Vector2f getSizes() const {return sizes;}
    sf::Vector2f getPosition() const {return {sprite.getGlobalBounds().left, sprite.getGlobalBounds().top};}

public:
    void takeDamage(int dmg) {hp = (hp - dmg >= 0) ? hp - dmg : 0;}

protected:
    sf::RenderWindow* window;

    /* Спрайт */
    sf::Sprite sprite;
    sf::Vector2f sizes;
    int textureFramesCount;
    sf::Clock animationClock;
    float currentSpriteFrame = 0;

    /* Бой */
    int visibilityDistance;

    int hp;
    int damage;
    double rangeOfDamageMultiplier;

    /* Информация */
    std::string name;
};


#endif //CROISSANT_MOB_H
