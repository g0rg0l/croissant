#ifndef ENEMY1_H_GUI_H
#define ENEMY1_H_GUI_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "unordered_map"

#include "../Entity/Player/Player.h"
#include "../Items/Item.h"
#include "../Entity/Mob/Mob.h"
#include "../Resources/ResourceHolder.h"

class UniversalIcon
{
public:
    UniversalIcon(sf::RenderWindow* window, Item* item)
        : window(window), item(item) { }

public:
    sf::Sprite getSprite() const {return backgroundSprite;}
    Item* getItem() const {return item;}
    sf::Sprite getItemSprite() const {return itemSprite;}

protected:
    sf::Sprite backgroundSprite;
    sf::Sprite itemSprite;

protected:
    Item* item;

protected:
    sf::RenderWindow* window;
};


class UniversalButton : public sf::Drawable
{
public:
    UniversalButton(sf::RenderWindow* window, Item* item)
        : window(window), item(item) { }


    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        if (isHovered) target.draw(backgroundSpriteHovered, states);
        else target.draw(backgroundSpriteNormal, states);

        if (item) target.draw(itemSprite, states);
    }

protected:
    bool isHovered = false;
    bool isLocked = false;

    void updateHovering()
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition();

        isHovered = isHovered ? backgroundSpriteHovered.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y)
                              : backgroundSpriteNormal.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y);
    }
    void updateClick()
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if (isHovered && !isLocked)
            {
                func();

                isLocked = true;
            }
        }
        else isLocked = false;
    }

protected:
    virtual void func() = 0;

public:
    void update()
    {
        updateHovering();
        updateClick();
    }

public:
    sf::Sprite backgroundSpriteNormal;
    sf::Sprite backgroundSpriteHovered;
    sf::Sprite itemSprite;

protected:
    sf::RenderWindow* window;
    Item* item;
};

/////////////////////////////////// Объекты, реализуемые интерфейсом FIGHT_GUI ///////////////////////////////////
namespace FIGHT_GUI {class WeaponButton; class HotBarButton; class HPBar; class FighterIcon;}
namespace INVENTORY_GUI {class EquipmentIcon; class PlayerIcon; class HotBarIcon; class InventoryIcon; class WeaponIcon;}

class FIGHT_GUI::WeaponButton : public UniversalButton
{
public:
    WeaponButton(sf::RenderWindow* window, Player* player, Mob* mob, Item* item, sf::Vector2f position = {0, 0});

private:
    void func() override
    {
        mob->takeDamage(10);
    }

private:
    Player* player;
    Mob* mob;
};


class FIGHT_GUI::HotBarButton : public UniversalButton
{
public:
    HotBarButton(sf::RenderWindow* window, Player* player, Mob* mob, Item* item, sf::Vector2f position = {0, 0});

private:
    void func() override
    {
        std::cout << "Used item from hotBar." << std::endl;
    }

private:
    Player* player;
    Mob* mob;
};


///////////////////////////////////// Объявление объектов в FIGHT_GUI ///////////////////////////////////
//class FIGHT_GUI::WeaponButton : public sf::Drawable
//{
//public:
//    WeaponButton(sf::RenderWindow* window, Player* player, Mob* mob, Item* item, sf::Vector2f position);
//    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//    void hoverUpdate(sf::Vector2i mousePosition);
//
//public:
//    void func();
//
//public:
//    bool isHovered = false;
//    bool isLocked = false;
//
//    void unlock() {isLocked = false;}
//    void lock() {isLocked = true;}
//
//private:
//    sf::Sprite backgroundSpriteNormal;
//    sf::Sprite backgroundSpriteHovered;
//    sf::Sprite itemSprite;
//
//private:
//    sf::RenderWindow* window;
//    Player* player;
//    Mob* mob;
//
//private:
//    Item* item;
//};


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


class FIGHT_GUI::FighterIcon : public sf::Drawable
{
public:
    FighterIcon(sf::RenderWindow* window, Player* player, sf::Vector2f position = {0, 0});
    FighterIcon(sf::RenderWindow* window, Mob* mob, sf::Vector2f position = {0, 0});

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


/////////////////////////////////// Объявление объектов в INVENTORY_GUI ///////////////////////////////////
class INVENTORY_GUI::EquipmentIcon : public sf::Drawable, public UniversalIcon
{
public:
    EquipmentIcon(sf::RenderWindow* window, Item* item,  sf::Vector2f position = {0, 0});
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


class INVENTORY_GUI::PlayerIcon : public sf::Drawable
{
public:
    PlayerIcon(sf::RenderWindow* window, Player* player,  sf::Vector2f position = {0, 0});

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite frameSprite;
    sf::Sprite playerIconSprite;

private:
    Player* player;

private:
    sf::RenderWindow* window;
};


class INVENTORY_GUI::HotBarIcon : public sf::Drawable, public UniversalIcon
{
public:
    HotBarIcon(sf::RenderWindow* window, Item* item, sf::Vector2f position = {0, 0});
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


class INVENTORY_GUI::InventoryIcon : public sf::Drawable, public UniversalIcon
{
public:
    InventoryIcon(sf::RenderWindow* window, Item* item, sf::Vector2f position = {0, 0});
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class INVENTORY_GUI::WeaponIcon : public sf::Drawable, public UniversalIcon
{
public:
    WeaponIcon(sf::RenderWindow* window, Item* item, sf::Vector2f position = {0, 0});
public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //ENEMY1_H_GUI_H
