#ifndef ENEMY1_H_INVENTORYSCREEN_H
#define ENEMY1_H_INVENTORYSCREEN_H

#include "SFML/Graphics.hpp"
#include "../dynamic_blur.hpp"

#include "../../Resources/ResourceHolder.h"
#include "../../Entity/Player/Player.h"
#include "../../GUI/GUI.h"
#include "../SwapHolder.h"

class InventoryScreen
{
public:
    explicit InventoryScreen(sf::RenderWindow* window = nullptr,
            sf::RenderTexture* renderTexture = nullptr,
            sf::Clock* clock = nullptr)
    : window(window), background(renderTexture), clock(clock) { }

public:
    void open(Player* player);
    void loadVisualElements(Player* player);

private:
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

private:
    sf::Sprite inventoryBackground;
    std::vector<INVENTORY_GUI::EquipmentIcon> allEquipmentIcons;
    std::vector<INVENTORY_GUI::PlayerIcon> allPlayerIcons;
    std::vector<FIGHT_GUI::HPBar> allPlayerBars;
    std::vector<INVENTORY_GUI::HotBarIcon> allHotBarIcons;
    std::vector<INVENTORY_GUI::InventoryIcon> allInventoryIcons;

private:
    SwapHolder swapHolder;
};


#endif //ENEMY1_H_INVENTORYSCREEN_H
