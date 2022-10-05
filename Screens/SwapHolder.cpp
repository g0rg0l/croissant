#include "SwapHolder.h"

void SwapHolder::loadIcons(Inventory* inventory,
                           std::vector<INVENTORY_GUI::InventoryIcon> allInventoryIcons,
                           std::vector<INVENTORY_GUI::HotBarIcon> allHotBarIcons,
                           std::vector<INVENTORY_GUI::EquipmentIcon> allEquipmentIcons)

{
    this->inventory = inventory;
    this->allInventoryIcons = std::move(allInventoryIcons);
    this->allHotBarIcons = std::move(allHotBarIcons);
    this->allEquipmentIcons = std::move(allEquipmentIcons);
}

void SwapHolder::update()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    moveItemSprite();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (!buttonWasClicked)
        {
            /* Три цикла, проверяющие, попали ли мы в какую-либо ячейку */
            int index_ = 0;
            for (int i = 8; i <= 22; ++i, index_++)
            {
                if (allInventoryIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x,mousePosition.y))
                {
                    /* Если мы берём предмет */
                    if (!itemTaken)
                    {
                        /* Если в ячейке есть предмет */
                        if (allInventoryIcons[index_].getItem())
                        {
                            fromSprite = allInventoryIcons[index_].getItemSprite();
                            itemTaken = true;
                            item = inventory->takeItem(i);
                            needToReloadVisualElements = true;
                        }
                    }
                    else // Если мы кладём предмет
                    {
                        /* Нужно проверить, можемли мы положить предмет в тек. ячейку */
                        if (inventory->canWePut(item, i))
                        {
                            /* Если в ячейке есть предмет */
                            if (allInventoryIcons[index_].getItem())
                            {
                                tempItem = inventory->takeItem(i);
                                inventory->putItem(item, i);
                                fromSprite = allInventoryIcons[index_].getItemSprite();
                                item = tempItem;
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

            index_ = 0;
            for (int i = 4; i <= 7; ++i, index_++)
            {
                if (allHotBarIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    /* Если мы берём предмет */
                    if (!itemTaken)
                    {
                        /* Если в ячейке есть предмет */
                        if (allHotBarIcons[index_].getItem())
                        {
                            fromSprite = allHotBarIcons[index_].getItemSprite();
                            itemTaken = true;
                            item = inventory->takeItem(i);
                            needToReloadVisualElements = true;
                        }
                    }
                    else // Если мы кладём предмет
                    {
                        if (inventory->canWePut(item, i))
                        {
                            /* Если в ячейке есть предмет */
                            if (allHotBarIcons[index_].getItem())
                            {
                                tempItem = inventory->takeItem(i);
                                inventory->putItem(item, i);
                                fromSprite = allHotBarIcons[index_].getItemSprite();
                                item = tempItem;
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

            index_ = 0;
            for (int i = 0; i <= 3; ++i, index_++)
            {
                if (allEquipmentIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x,mousePosition.y))
                {
                    /* Если мы берём предмет */
                    if (!itemTaken)
                    {
                        /* Если в ячейке есть предмет */
                        if (allEquipmentIcons[index_].getItem())
                        {
                            fromSprite = allEquipmentIcons[index_].getItemSprite();
                            itemTaken = true;
                            item = inventory->takeItem(i);
                            needToReloadVisualElements = true;
                        }
                    }
                    else // Если мы кладём предмет
                    {
                        if (inventory->canWePut(item, i))
                        {
                            /* Если в ячейке есть предмет */
                            if (allEquipmentIcons[index_].getItem())
                            {
                                tempItem = inventory->takeItem(i);
                                inventory->putItem(item, i);
                                fromSprite = allEquipmentIcons[index_].getItemSprite();
                                item = tempItem;
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

