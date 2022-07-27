#ifndef CROISSANT_ENGINE_H
#define CROISSANT_ENGINE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Globals.h"
#include "Screens/Screens.h"
#include "Screens/FightScreen.h"

class Engine
{

public:
    Engine();

    /////////////////////////////////// Main loop ///////////////////////////////////
    void runEngine(); // Метод, запускающий игру

    /////////////////////////////////// Action'ы ///////////////////////////////////
    void checkEvents(); // Метод, проверяющий все события с экраном в игре

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(); // Метод, вызывающий отрисовку всех объектов в игре

private:
    /////////////////////////////////// Параметры окна ///////////////////////////////////
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window; // Отображаемое окно

    sf::View view; // Камера
    float viewScale = 5.f;

    sf::Clock clock; // Время в игре

    Globals globals; // Объект, через который будет происходить взаимодействие со всеми объектами на карте
    Screens screens; // Объект, хранящий все экраны в игре и работающий с ними
    FightScreen fightScreen = FightScreen(videoMode.width, videoMode.height, viewScale);
};


#endif //CROISSANT_ENGINE_H
