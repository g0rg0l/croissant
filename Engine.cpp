#include "Engine.h"

/////////////////////////////////// Window ///////////////////////////////////
Engine::Engine() // Конструктор, инициализирующий экран с параметрами и камеру
{
    srand(time(nullptr));

    window.create(videoMode,
                  "croissant",
                  sf::Style::Fullscreen
                  );

    view.setSize((float) videoMode.width / viewScale, (float) videoMode.height / viewScale);

    renderTexture.create(videoMode.width,videoMode.height);

    screenHolder = new ScreenHolder(&window, &renderTexture, &clock);
    globals = new Globals(&window);
}

Engine::~Engine()
{
    delete screenHolder;
    delete globals;
    EffectsHolders::Map::getInstance().clear();
}

/////////////////////////////////// Main loop ///////////////////////////////////
void Engine::runEngine() // Метод, запускающий игру
{
    globals->map->loadMap(1, &window);

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        globals->player->move(deltaTime, globals->map->wallBounds, &view);
        globals->updateAllMobs(screenHolder);

        EffectsHolders::Map::getInstance().update();
        checkEvents();
        draw();
    }
}

/////////////////////////////////// Action'ы ///////////////////////////////////
void Engine::checkEvents() // Метод, проверяющий все события с экраном в игре
{
    sf::Event event = {};

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) screenHolder->pauseScreen->open();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) screenHolder->inventoryScreen->open(globals->player);
        }
    }
}

/////////////////////////////////// Отрисовка ///////////////////////////////////
void Engine::draw() // Метод, вызывающий отрисовку всех объектов в игре
{
    /* Отрисовка объектов на рендер-текстуру */
    renderTexture.setView(view);
    renderTexture.clear(sf::Color(38, 31, 51));

    renderTexture.draw(*globals->map);
    for (auto &mob : globals->allMobs) renderTexture.draw(*mob);
    renderTexture.draw(*globals->player);
    renderTexture.draw(EffectsHolders::Map::getInstance());

    renderTexture.display();

    /* Отрисовка рендер-текстуры на окне */
    renderSprite.setTexture(renderTexture.getTexture());
    window.clear();
    window.draw(renderSprite);
    window.display();
}
