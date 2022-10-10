#ifndef ENEMY1_H_INVENTORYSCREEN_H
#define ENEMY1_H_INVENTORYSCREEN_H

#include "SFML/Graphics.hpp"
#include "../dynamic_blur.hpp"

#include "../../Resources/ResourceHolder.h"
#include "../../Animations/Animator.h"
#include "../../Entity/Player/Player.h"
#include "../../GUI/GUI.h"
#include "../SwapHolder.h"

class InventoryScreen
{
public:
    explicit InventoryScreen(sf::RenderWindow* window, sf::RenderTexture* renderTexture, sf::Clock* clock)
        : window(window), background(renderTexture), clock(clock)
    {
        swapHolder = new SwapHolder;

        textureForAnimator.create(window->getSize().x, window->getSize().y);
    }

    ~InventoryScreen()
    {
        delete swapHolder;
    }

public:
    void open(Player* player);
    void loadVisualElements(Player* player);
    void manifest();
    void unManifest();

private:
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

    sf::Sprite backgroundSprite;
    sf::RenderTexture textureForAnimator;

private:
    sf::Sprite inventoryBackground;
    std::vector<INVENTORY_GUI::EquipmentIcon> allEquipmentIcons;
    std::vector<INVENTORY_GUI::PlayerIcon> allPlayerIcons;
    std::vector<FIGHT_GUI::HPBar> allPlayerBars;
    std::vector<INVENTORY_GUI::HotBarIcon> allHotBarIcons;
    std::vector<INVENTORY_GUI::InventoryIcon> allInventoryIcons;
    std::vector<INVENTORY_GUI::WeaponIcon> allWeaponIcons;

private:
    SwapHolder* swapHolder;
};


#endif //ENEMY1_H_INVENTORYSCREEN_H
