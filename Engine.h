#ifndef CROISSANT_ENGINE_H
#define CROISSANT_ENGINE_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "Globals.h"
#include "Screens/ScreenHolder.h"
#include "GUI/GUI.h"

class Engine
{

public:
    Engine();
    ~Engine();

    /////////////////////////////////// Main loop ///////////////////////////////////
    void runEngine(); // Метод, запускающий игру

    /////////////////////////////////// Action'ы ///////////////////////////////////
    void checkEvents(); // Метод, проверяющий все события с экраном в игре

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(); // Метод, вызывающий отрисовку всех объектов в игре

private:
    sf::RenderTexture renderTexture;
    sf::Sprite renderSprite;

private:
    /////////////////////////////////// Параметры окна ///////////////////////////////////
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode(); // Режим экрана, с которго был запущен код
    sf::RenderWindow window; // Отображаемое окно

    /////////////////////////////////// Параметры Камеры ///////////////////////////////////
    sf::View view; // Камера
    float viewScale = 5.f; // Коэффициент приближения всех объектов в игре (1920x1080 <=> 384x216)

    /////////////////////////////////// Время ///////////////////////////////////
    sf::Clock clock; // Время в игре

private:
    /////////////////////////////////// Объекты на экране ///////////////////////////////////
    Globals* globals; // Объект, через который будет происходить взаимодействие со всеми объектами на карте

    /////////////////////////////////// Экраны ///////////////////////////////////
    ScreenHolder* screenHolder;
};


#endif //CROISSANT_ENGINE_H
