#include "PauseScreen.h"

void PauseScreen::open()
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    while (true)
    {
        clock->restart().asSeconds();
        sf::Event event = {};

        while (window->pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return;
        }

        window->clear();
        window->draw(backgroundSprite);
        window->display();
    }
}

void PauseScreen::loadVisualElements()
{

}
