#include "ScreenHolder.h"

ScreenHolder::ScreenHolder(sf::RenderWindow *window, sf::RenderTexture *renderTexture, sf::Clock *clock)
{
    fightScreen = FightScreen(window, renderTexture, clock);
    pauseScreen = PauseScreen(window, renderTexture, clock);
    inventoryScreen = InventoryScreen(window, renderTexture, clock);
}
