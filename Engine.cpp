#include "Engine.h"

/////////////////////////////////// Window ///////////////////////////////////
Engine::Engine() // Конструктор, инициализирующий экран с параметрами
{
    window.create(sf::VideoMode({windowWidth, windowHeight}),
                  "croissant",
                  sf::Style::Fullscreen
                  );

    view.setSize(sf::Vector2f(windowWidth / 5, windowHeight / 5));
}

/////////////////////////////////// Main loop ///////////////////////////////////
void Engine::runEngine() // Метод, запускающий игру
{
    globals.map.buildMap();

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        globals.player.move(deltaTime, globals.map.getWallBounds(), &view);

        checkEvents();
        draw();
    }
}

/////////////////////////////////// Action'ы ///////////////////////////////////
void Engine::checkEvents() // Метод, проверяющий все события с экраном в игре
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
    }
}

/////////////////////////////////// Отрисовка ///////////////////////////////////
void Engine::draw() // Метод, вызывающий отрисовку всех объектов в игре
{
    window.setView(view);

    window.clear(sf::Color(169, 169, 169));

    /* Карта */
    window.draw(globals.map);

    /* Игрок */
    window.draw(globals.player);

    window.display();
}
