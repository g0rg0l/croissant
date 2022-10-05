#include "Inventory.h"



Item *Inventory::takeItem(int index)
{
    Item* temp;

    temp = inv[index];
    inv[index] = nullptr;

    return temp;
}

void Inventory::putItem(Item *item, int index) {inv[index] = item;}

bool Inventory::correctSpecification(Item* item, int index)
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

bool Inventory::isIconEmpty(int index) {return inv[index] == nullptr;}

int Inventory::findEmpty(Item *item)
{
    for (int i = 0; inv.size(); ++i)
    {
        if (!inv[i] && correctSpecification(item, i))
        {
            return i;
        }
    }

    return -1;
}
