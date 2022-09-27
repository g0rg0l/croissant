#ifndef ENEMY1_H_GUI_H
#define ENEMY1_H_GUI_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

#include "../Entity/Player/Player.h"
#include "../Entity/Mob/Mob.h"
#include "../Resources/ResourceHolder.h"

/////////////////////////////////// Объекты, реализуемые интерфейсом FIGHT_GUI ///////////////////////////////////
namespace FIGHT_GUI {class AttackButton; class HPBar; class FightersIconFrame;}

/////////////////////////////////// Объявление объектов в FIGHT_GUI ///////////////////////////////////
class FIGHT_GUI::AttackButton : public sf::Drawable
{
public:
    AttackButton(sf::RenderWindow* window, Player* player, Mob* mob, const std::string& iconFileName, sf::Vector2f position);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void hoverUpdate(sf::Vector2i mousePosition);

public:
    void func();

public:
    bool isHovered = false;
    bool isLocked = false;

    void unlock() {isLocked = false;}
    void lock() {isLocked = true;}

private:
    sf::Sprite frameSprite_normal;
    sf::Sprite frameSprite_hovered;
    sf::Sprite iconSprite;

private:
    sf::RenderWindow* window;
    Player* player;
    Mob* mob;
};


class FIGHT_GUI::HPBar : public sf::Drawable
{
public:
    HPBar(sf::RenderWindow* window, const std::string& HPFileName, int maxHP, sf::Vector2f position = {0, 0});

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


class FIGHT_GUI::FightersIconFrame : public sf::Drawable
{
public:
    FightersIconFrame(sf::RenderWindow* window, Player* player, sf::Vector2f position = {0, 0});
    FightersIconFrame(sf::RenderWindow* window, Mob* mob, sf::Vector2f position = {0, 0});

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite frameSprite;
    sf::Sprite iconSprite;

private:
    sf::RenderWindow* window;
    Mob* mob;
    Player* player;
};

#endif //ENEMY1_H_GUI_H
