#include "Screens.h"

void Screens::showMainMenu(sf::RenderWindow &window)
{
    bool menuIsOpen = true;

    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setPosition(sf::Vector2f(0, 0));
    shape.setFillColor(sf::Color::Magenta);

    while (menuIsOpen)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            menuIsOpen = false;
        }

        window.clear(sf::Color(169, 169, 169));

        window.draw(shape);

        window.display();
    }
}


