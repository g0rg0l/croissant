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
                                             {6, new Armor("boots", "basic boots", 10, 100)},
                                             {7, nullptr}};

    std::unordered_map<int, Item*> inv = {{8, nullptr},
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
                                          {22, new Armor("leggings", "basic leggings", 10, 100)}};

    std::unordered_map<int, Item*> equipment = {{0, new Armor("helmet", "basic helmet", 10, 100)},
                                                {1, new Armor("chest plate", "basic chest plate", 10, 100)},
                                                {2, new Armor("leggings", "basic leggings", 10, 100)},
                                                {3, new Armor("boots", "basic boots", 10, 100)}};

public:
    Item* takeItem(int index)
    {
        Item* temp;

        if (index <= 3)
        {
            temp = equipment[index];
            equipment[index] = nullptr;
        }
        else if (index <= 7)
        {
            temp = hotBar[index];
            hotBar[index] = nullptr;
        }
        else
        {
            temp = inv[index];
            inv[index] = nullptr;
        }

        return temp;
    }

    void putItem(Item* item, int index)
    {
        if (index <= 3)
        {
            equipment[index] = item;
        }
        else if (index <= 7)
        {
            hotBar[index] = item;
        }
        else
        {
            inv[index] = item;
        }
    }

    bool canWePut(Item* item, int index)
    {
        if (item->getSpecification() == "helmet")
        {
            return (index >= 4 && index <= 22) || index == 0;
        }
        if (item->getSpecification() == "chest plate")
        {
            return (index >= 4 && index <= 22) || index == 1;
        }
        if (item->getSpecification() == "leggings")
        {
            return (index >= 4 && index <= 22) || index == 2;
        }
        if (item->getSpecification() == "boots")
        {
            return (index >= 4 && index <= 22) || index == 3;
        }

        std::cout << "no such item specification as " << item->getSpecification() << std::endl;
        return false;
    }

    bool isEmpty(int index)
    {
        if (index >= 0 && index <= 3) return equipment[index] == nullptr;
        if (index >= 4 && index <= 7) return hotBar[index] == nullptr;
        if (index >= 8 && index <= 22) return inv[index] == nullptr;

        std::cout << "no such inventory id as " << index << std::endl;
        return false;
    }

};


#endif //ENEMY1_H_INVENTORY_H