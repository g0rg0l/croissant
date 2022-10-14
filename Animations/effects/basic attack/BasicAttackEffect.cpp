#include "BasicAttackEffect.h"

BasicAttackEffect::BasicAttackEffect(sf::Vector2f position, sf::Window *window)
    : Effect(window, {32, 32})
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Animations/effects/basic attack/basic attack.png", "basic attack effect texture");
    sf::Texture *texture = textureHolder.getResource("basic attack effect texture");
    sprite.setTexture(*texture);
    textureFramesCount = (int) (sprite.getGlobalBounds().width / sizes.x);
    sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));

    sprite.setScale(sf::Vector2f(
            2.75 * (float) window->getSize().x / 1920,
            2.75 * (float) window->getSize().y / 1080));

    sprite.setPosition(
            position.x * (float) window->getSize().x / 1920,
            position.y * (float) window->getSize().y / 1080);
}
