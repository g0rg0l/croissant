#include "ScreenHolder.h"

ScreenHolder::ScreenHolder(sf::RenderWindow *window, sf::RenderTexture *renderTexture, sf::Clock *clock)
{
    fightScreen = new FightScreen(window, renderTexture, clock);
    pauseScreen = new PauseScreen(window, renderTexture, clock);
    inventoryScreen = new InventoryScreen(window, renderTexture, clock);
}

ScreenHolder::~ScreenHolder()
{
    delete fightScreen;
    delete pauseScreen;
    delete inventoryScreen;
}
