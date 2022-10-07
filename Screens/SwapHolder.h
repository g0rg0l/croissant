#ifndef ENEMY1_H_SWAPHOLDER_H
#define ENEMY1_H_SWAPHOLDER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <utility>

#include "../GUI/GUI.h"

class SwapHolder : public sf::Drawable
{
public:
    SwapHolder() = default;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void loadIcons(Inventory* inventory,
                   std::vector<INVENTORY_GUI::InventoryIcon>& allInventoryIcons,
                   std::vector<INVENTORY_GUI::HotBarIcon>& allHotBarIcons,
                   std::vector<INVENTORY_GUI::WeaponIcon>& allWeaponIcons,
                   std::vector<INVENTORY_GUI::EquipmentIcon>& allEquipmentIcons);

public:
    void update();
    void moveItemSprite();
    void breakSwap();

public:
    bool needToReloadVisualElements = false;

private:
    bool buttonWasClicked = false;
    int remItemIndex;
    bool itemTaken = false;

private:
    Inventory* inventory = nullptr;

    Item* item = nullptr;
    Item* tempItem = nullptr;

    sf::Sprite fromSprite;

private:
    std::vector<UniversalIcon*> icons;
};


#endif //ENEMY1_H_SWAPHOLDER_H
