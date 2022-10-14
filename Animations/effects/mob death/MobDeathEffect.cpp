#include "MobDeathEffect.h"

MobDeathEffect::MobDeathEffect(sf::Vector2f position, sf::Window *window)
        : Effect(window, {32, 32})
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Animations/effects/mob death/mob death.png", "mob death effect texture");
    sf::Texture *texture = textureHolder.getResource("mob death effect texture");
    sprite.setTexture(*texture);
    textureFramesCount = (int) (sprite.getGlobalBounds().width / sizes.x);
    sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));

    sprite.setScale(sf::Vector2f(
            0.5 * (float) window->getSize().x / 1920,
            0.5 * (float) window->getSize().y / 1080));

    sprite.setPosition(position);
}