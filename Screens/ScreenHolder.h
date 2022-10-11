#ifndef ENEMY1_H_SCREENHOLDER_H
#define ENEMY1_H_SCREENHOLDER_H

#include "game_screens/fight screen/FightScreen.h"
#include "game_screens/pause screen/PauseScreen.h"
#include "game_screens/inventory screen/InventoryScreen.h"

class ScreenHolder
{

public:
    explicit ScreenHolder(sf::RenderWindow* window, sf::RenderTexture* renderTexture, sf::Clock* clock);

    ~ScreenHolder();

public:
    FightScreen* fightScreen; // Экран боя
    PauseScreen* pauseScreen; // Экран паузы
    InventoryScreen* inventoryScreen; // Экран инвентаря
};

#endif //ENEMY1_H_SCREENHOLDER_H
