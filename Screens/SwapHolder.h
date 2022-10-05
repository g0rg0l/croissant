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
                   std::vector<INVENTORY_GUI::InventoryIcon> allInventoryIcons,
                   std::vector<INVENTORY_GUI::HotBarIcon> allHotBarIcons,
                   std::vector<INVENTORY_GUI::EquipmentIcon> allEquipmentIcons);

public:
    void update();
    void moveItemSprite();

public:
    bool needToReloadVisualElements = false;

private:
    bool buttonWasClicked = false;
    bool itemTaken = false;

private:
    Item* item = nullptr;
    Item* tempItem = nullptr;

    sf::Sprite fromSprite;

    Inventory* inventory = nullptr;

private:
    std::vector<INVENTORY_GUI::InventoryIcon> allInventoryIcons;
    std::vector<INVENTORY_GUI::HotBarIcon> allHotBarIcons;
    std::vector<INVENTORY_GUI::EquipmentIcon> allEquipmentIcons;
};


#endif //ENEMY1_H_SWAPHOLDER_H
