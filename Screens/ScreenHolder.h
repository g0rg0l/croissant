#ifndef ENEMY1_H_SCREENHOLDER_H
#define ENEMY1_H_SCREENHOLDER_H

#include "game_screens/FightScreen.h"
#include "game_screens/PauseScreen.h"
#include "game_screens/InventoryScreen.h"

class ScreenHolder
{

public:
    explicit ScreenHolder(sf::RenderWindow* window = nullptr, sf::RenderTexture* renderTexture = nullptr, sf::Clock* clock = nullptr);

public:
    FightScreen fightScreen; // Экран боя
    PauseScreen pauseScreen; // Экран паузы
    InventoryScreen inventoryScreen; // Экран инвентаря
};

#endif //ENEMY1_H_SCREENHOLDER_H
