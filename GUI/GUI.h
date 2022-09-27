#ifndef ENEMY1_H_GUI_H
#define ENEMY1_H_GUI_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "../Resources/ResourceHolder.h"

/////////////////////////////////// Объекты, реализуемые интерфейсом FIGHT_GUI ///////////////////////////////////
namespace FIGHT_GUI {class AttackButton; class HPBar;}

/////////////////////////////////// Объявление объектов в FIGHT_GUI ///////////////////////////////////
class FIGHT_GUI::AttackButton : public sf::Drawable
{
public:
    explicit AttackButton(sf::RenderWindow* window, const std::string& fileName, sf::Vector2f position = {0, 0});

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(sf::Vector2i mousePosition, bool clicked);

private:
    bool wasClicked = false;
    void setStatus(const std::string& status);

private:
    sf::Sprite sprite;
    const std::string fileName;

private:
    sf::RenderWindow* window;
};

class FIGHT_GUI::HPBar : public sf::Drawable
{
public:
    HPBar(sf::RenderWindow* window, const std::string& fileName, int maxHP, sf::Vector2f position = {0, 0});

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(int hp);

private:
    int maxHP;
    sf::Sprite frameSprite;
    sf::Sprite HPSprite;

private:
    sf::RenderWindow* window;
};
#endif //ENEMY1_H_GUI_H
