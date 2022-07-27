#include "Engine.h"

/////////////////////////////////// Window ///////////////////////////////////
Engine::Engine() // Конструктор, инициализирующий экран с параметрами и камеру
{
    window.create(videoMode,
                  "croissant",
                  sf::Style::Fullscreen
                  );

    view.setSize((float) videoMode.width / viewScale, (float) videoMode.height / viewScale);
}

/////////////////////////////////// Main loop ///////////////////////////////////
void Engine::runEngine() // Метод, запускающий игру
{
    screens.showMainMenu(window);

    globals.map.buildMap();

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        if (!fightScreen.isFighting)
        {
            globals.player.move(deltaTime, globals.map.wallBounds, &view);
            globals.updateAllMobs(fightScreen);
        }
        fightScreen.updateFight(globals.allMobs);
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

    /* Мобы */
    for (auto &mob : globals.allMobs)
    {
        window.draw(mob);
    }

    /* Игрок */
    window.draw(globals.player);

    /* Бой */
    window.draw(fightScreen);

    /* Отображение экрана */
    window.display();
}
