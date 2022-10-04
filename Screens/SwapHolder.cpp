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
    if (isSwapping)
    {
        fromSprite.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (!isSwapping)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition();

            int index_ = 0;

            for (int i = 8; i <= 22; ++i, index_++)
            {
                if (allInventoryIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    if (allInventoryIcons[index_].getItem())
                    {
                        fromIndex = i;
                        fromSprite = allInventoryIcons[index_].getItemSprite();
                        isSwapping = true;
                    }
                }
            }
            index_ = 0;
            for (int i = 4; i <= 7; ++i, index_++)
            {
                if (allHotBarIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    if (allHotBarIcons[index_].getItem())
                    {
                        fromIndex = i;
                        fromSprite = allHotBarIcons[index_].getItemSprite();
                        isSwapping = true;
                    }
                }
            }
            index_ = 0;
            for (int i = 0; i <= 3; ++i, index_++)
            {
                if (allEquipmentIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    if (allEquipmentIcons[index_].getItem())
                    {
                        fromIndex = i;
                        fromSprite = allEquipmentIcons[index_].getItemSprite();
                        isSwapping = true;
                    }
                }
            }
        }
    }
    else if (isSwapping)
    {
        switchOf();
        needToReloadVisualElements = true;
        isSwapping = false;
    }
}

void SwapHolder::switchOf()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition();

    int index_ = 0;
    for (int i = 8; i <= 22; ++i, index_++)
    {
        if (allInventoryIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            toIndex = i;
            inventory->swap(fromIndex, toIndex);
        }
    }
    index_ = 0;
    for (int i = 4; i <= 7; ++i, index_++)
    {
        if (allHotBarIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            toIndex = i;
            inventory->swap(fromIndex, toIndex);
        }
    }
    index_ = 0;
    for (int i = 0; i <= 3; ++i, index_++)
    {
        if (allEquipmentIcons[index_].getSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        {
            toIndex = i;
            inventory->swap(fromIndex, toIndex);
        }
    }
}

void SwapHolder::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (isSwapping)
    {
        target.draw(fromSprite, states);
    }
}

