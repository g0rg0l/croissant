#ifndef ENEMY1_H_GUI_H
#define ENEMY1_H_GUI_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "../Resources/ResourceHolder.h"

/////////////////////////////////// Объекты, реализуемые интерфейсом GUI ///////////////////////////////////
namespace GUI {class Button;}

/////////////////////////////////// Объявление объектов в GUI ///////////////////////////////////
class GUI::Button : public sf::Drawable
{
public:
    explicit Button(const std::string& fileName, sf::Vector2f position = {0, 0});

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(sf::Vector2i mousePosition, bool clicked = false);

private:
    void setStatus(const std::string& status);

private:
    sf::Sprite sprite;

    const std::string fileName;
};

#endif //ENEMY1_H_GUI_H
