#ifndef ENEMY1_H_INVENTORY_H
#define ENEMY1_H_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "unordered_map"

#include "../../../Items/Item.h"

class Inventory : public sf::Drawable
{

public:
    Inventory() = default;

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    std::unordered_map<int, Item*> hotBar = {{4, nullptr},
                                             {5, nullptr},
                                             {6, new Armor("basic boots", 10, 100)},
                                             {7, nullptr}};

    std::unordered_map<int, Item*> inv = {{8, nullptr},
                                          {9, nullptr},
                                          {10, nullptr},
                                          {11, nullptr},
                                          {12, new Armor("basic helmet", 10, 100)},
                                          {13, nullptr},
                                          {14, nullptr},
                                          {15, nullptr},
                                          {16, nullptr},
                                          {17, nullptr},
                                          {18, nullptr},
                                          {19, nullptr},
                                          {20, nullptr},
                                          {21, nullptr},
                                          {22, new Armor("basic leggings", 10, 100)}};

    std::unordered_map<int, Item*> equipment = {{0, new Armor("basic helmet", 10, 100)},
                                                {1, new Armor("basic chest plate", 10, 100)},
                                                {2, new Armor("basic leggings", 10, 100)},
                                                {3, new Armor("basic boots", 10, 100)}};

public:
    void swap(int fromIndex, int toIndex)
    {
        if (fromIndex <= 3)
        {
            if (toIndex <= 3) std::swap(equipment[fromIndex], equipment[toIndex]);
            else if (toIndex <= 7) std::swap(equipment[fromIndex], hotBar[toIndex]);
            else std::swap(equipment[fromIndex], inv[toIndex]);
        }
        else if (fromIndex <= 7)
        {
            if (toIndex <= 3) std::swap(hotBar[fromIndex], equipment[toIndex]);
            else if (toIndex <= 7) std::swap(hotBar[fromIndex], hotBar[toIndex]);
            else std::swap(hotBar[fromIndex], inv[toIndex]);
        }
        else
        {
            if (toIndex <= 3) std::swap(inv[fromIndex], equipment[toIndex]);
            else if (toIndex <= 7) std::swap(inv[fromIndex], hotBar[toIndex]);
            else std::swap(inv[fromIndex], inv[toIndex]);
        }
    }

};


#endif //ENEMY1_H_INVENTORY_H