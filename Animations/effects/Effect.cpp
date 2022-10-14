#include "Effect.h"

Effect::Effect(sf::Window* window, sf::Vector2f sizes)
    : window(window), sizes(sizes)
{

}

void Effect::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

void Effect::update()
{
    float dt = 20 * animationClock.restart().asSeconds();

    if ((int) currentSpriteFrame < (int) (currentSpriteFrame + dt))
    {
        sprite.setTextureRect(sf::IntRect(((int) currentSpriteFrame) * sizes.x, 0, sizes.x, sizes.y));
    }
    currentSpriteFrame += dt;

    if ((int ) currentSpriteFrame > textureFramesCount - 1) isCompleted = true;
}
