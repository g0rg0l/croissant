#include "Animator.h"

Animator &Animator::getInstance()
{
    static Animator animator;

    return animator;
}

void Animator::manifest(sf::RenderWindow *window, sf::Clock* clock, sf::RenderTexture *background, sf::RenderTexture *textureToManifest)
{
    float alpha = 0;

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background->getTexture());

    sf::Sprite spriteToManifest;
    spriteToManifest.setTexture(textureToManifest->getTexture());

    while (alpha <= 255)
    {
        float dt = clock->restart().asSeconds();
        spriteToManifest.setColor(sf::Color(255, 255, 255, (int) alpha));

        window->clear();

        window->draw(backgroundSprite);
        window->draw(spriteToManifest);

        window->display();

        alpha += 2000 * dt;
    }
}

void Animator::unManifest(sf::RenderWindow *window, sf::Clock* clock, sf::RenderTexture *background, sf::RenderTexture *textureToUnManifest)
{
    float alpha = 255;

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background->getTexture());

    sf::Sprite spriteToUnManifest;
    spriteToUnManifest.setTexture(textureToUnManifest->getTexture());

    while (alpha >= 0)
    {
        float dt = clock->restart().asSeconds();
        spriteToUnManifest.setColor(sf::Color(255, 255, 255, (int) alpha));

        window->clear();

        window->draw(backgroundSprite);
        window->draw(spriteToUnManifest);

        window->display();

        alpha -= 2000 * dt;
    }
}
