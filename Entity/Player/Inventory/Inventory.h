#ifndef ENEMY1_H_INVENTORY_H
#define ENEMY1_H_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "unordered_map"

#include "../../../Items/Item.h"

class Inventory
{
public:
    Inventory() = default;

public:
    std::unordered_map<int, Item*> inv = {
            /* Экипировка */
            {0, new Armor("helmet", "basic helmet", 10, 100)},
            {1, new Armor("chest plate", "basic chest plate", 10, 100)},
            {2, new Armor("leggings", "basic leggings", 10, 100)},
            {3, new Armor("boots", "basic boots", 10, 100)},

            /* Оружейная ячейка */
            {4, nullptr},

            /* Хот бар */
            {5, nullptr},
            {6, new Armor("boots", "basic boots", 10, 100)},
            {7, new Armor("helmet", "simple helmet", 15, 200)},

            /* Ячейки */
            {8, new Weapon("basic sword", 10, 100)},
            {9, nullptr},
            {10, nullptr},
            {11, nullptr},
            {12, new Armor("helmet", "basic helmet", 10, 100)},
            {13, nullptr},
            {14, nullptr},
            {15, nullptr},
            {16, nullptr},
            {17, nullptr},
            {18, nullptr},
            {19, nullptr},
            {20, nullptr},
            {21, nullptr},
            {22, new Armor("leggings", "basic leggings", 10, 100)}
    };

public:
    Item* takeItem(int index);
    void putItem(Item* item, int index);
    bool correctSpecification(Item* item, int index);
    bool isIconEmpty(int index);
    int findEmpty(Item* item);
};


#endif //ENEMY1_H_INVENTORY_H