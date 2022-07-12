#include "Engine.h"

/////////////////////////////////// Window ///////////////////////////////////
Engine::Engine() // Конструктор, инициализирующий экран с параметрами и камеру
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

        globals.player.move(deltaTime, globals.map.wallBounds, &view);

        if (globals.mob.isSeePlayer(globals.player, globals.map.wallBounds))
        {
            std::cout << "I see you" << std::endl;
        }

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
    /* Камера */
    window.setView(view);

    /* Очистка карты */
    window.clear(sf::Color(169, 169, 169));

    /* Карта */
    window.draw(globals.map);

    /* тестовый моб */
    window.draw(globals.mob);

    /* Игрок */
    window.draw(globals.player);

    /* Отображение экрана */
    window.display();
}
