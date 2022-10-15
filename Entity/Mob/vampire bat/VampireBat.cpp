#include "VampireBat.h"

VampireBat::VampireBat(sf::Vector2f position, sf::RenderWindow *window)
        : Mob("vampire bat", {16, 16}, window)
{
    /* Детали отрисовки */
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Entity/Mob/vampire bat/src/vampire bat.png", "vampire bat texture");
    sf::Texture *texture = textureHolder.getResource("vampire bat texture");
    sprite.setTexture(*texture);
    textureFramesCount = (int) (sprite.getGlobalBounds().width / sizes.x);
    sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));

    sprite.setScale(sf::Vector2f(
            (float) window->getSize().x / 1920,
            (float) window->getSize().y / 1080));

    sprite.setPosition(
            position.x * (float) window->getSize().x / 1920,
            position.y * (float) window->getSize().y / 1080);

    /* Выставление характеристик */
    visibilityDistance = 50;
    hp = 30;
    damage = 5;
    rangeOfDamageMultiplier = 0.2;
}