#ifndef CROISSANT_ENGINE_H
#define CROISSANT_ENGINE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Globals.h"

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
    const unsigned int windowWidth = 1920;
    const unsigned int windowHeight = 1080;

    sf::RenderWindow window; // Отображаемое окно
    sf::View view; // Камера
    sf::Clock clock; // Время в игре

    Globals globals; // Объект, через который будет происходить взаимодействие со всеми объектами на карте
};


#endif //CROISSANT_ENGINE_H
