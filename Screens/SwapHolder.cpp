#include "SwapHolder.h"

void SwapHolder::loadIcons(Inventory* inventory,
                           std::vector<INVENTORY_GUI::InventoryIcon>& allInventoryIcons,
                           std::vector<INVENTORY_GUI::HotBarIcon>& allHotBarIcons,
                           std::vector<INVENTORY_GUI::WeaponIcon>& allWeaponIcons,
                           std::vector<INVENTORY_GUI::EquipmentIcon>& allEquipmentIcons)

{
    this->inventory = inventory;

    icons.clear();
    for (auto& icon : allEquipmentIcons) icons.push_back(&icon);
    for (auto& icon : allWeaponIcons) icons.push_back(&icon);
    for (auto& icon : allHotBarIcons) icons.push_back(&icon);
    for (auto& icon : allInventoryIcons) icons.push_back(&icon);
}

void SwapHolder::update()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    moveItemSprite();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (!buttonWasClicked)
        {
            for (int i = 0; i < icons.size(); ++i)
            {
                if (icons[i]->getSprite().getGlobalBounds().contains(mousePosition.x,mousePosition.y))
                {
                    /* Если мы берём предмет */
                    if (!itemTaken)
                    {
                        /* Если в ячейке есть предмет */
                        if (icons[i]->getItem())
                        {
                            fromSprite = icons[i]->getItemSprite();
                            itemTaken = true;
                            item = inventory->takeItem(i);
                            remItemIndex = i;
                            needToReloadVisualElements = true;
                        }
                    }
                    else // Если мы кладём предмет
                    {
                        /* Нужно проверить, можем ли мы положить предмет в тек. ячейку */
                        if (inventory->correctSpecification(item, i))
                        {
                            /* Если в ячейке есть предмет */
                            if (icons[i]->getItem())
                            {
                                tempItem = inventory->takeItem(i);
                                inventory->putItem(item, i);
                                fromSprite = icons[i]->getItemSprite();
                                item = tempItem;
                                remItemIndex = i;
                                needToReloadVisualElements = true;
                            }
                            else // Если ячейка пустая
                            {
                                itemTaken = false;
                                inventory->putItem(item, i);
                                needToReloadVisualElements = true;
                            }
                        }
                    }
                }
            }

            buttonWasClicked = true;
        }
    }
    else buttonWasClicked = false;

}

void SwapHolder::breakSwap()
{
    if (itemTaken)
    {
        itemTaken = false;
        if (inventory->isIconEmpty(remItemIndex)) inventory->putItem(item, remItemIndex);
        else inventory->putItem(item, inventory->findEmpty(item));
    }
}

void SwapHolder::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (itemTaken) target.draw(fromSprite, states);
}

void SwapHolder::moveItemSprite()
{
    if (itemTaken)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition();

        fromSprite.setPosition(
                mousePosition.x - fromSprite.getGlobalBounds().width / 2,
                mousePosition.y - fromSprite.getGlobalBounds().height / 2
                );
    }
}