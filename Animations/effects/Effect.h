#ifndef ENEMY1_H_EFFECT_H
#define ENEMY1_H_EFFECT_H

#include "SFML/Graphics.hpp"
#include "../../Resources/ResourceHolder.h"

class Effect : public sf::Drawable
{
public:
    explicit Effect(sf::Window* window, sf::Vector2f sizes);

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    void update();
    bool isCompleted = false;

protected:
    sf::Window* window;

    sf::Sprite sprite;
    sf::Clock animationClock;
    int textureFramesCount;
    sf::Vector2f sizes;
    float currentSpriteFrame = 0;
};


#endif //ENEMY1_H_EFFECT_H
