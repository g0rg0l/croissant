#include "Globals.h"

Globals::Globals(sf::RenderWindow* window)
    : window(window)
{
    player = new Player(100);
    map = new TileMap;

    allMobs = {
        new VampireBat({200, 200}, window),
        new VampireBat({50, 300}, window)
    };
}

Globals::~Globals()
{
    delete player;
    delete map;

    for (auto& mob : allMobs)
    {
        delete mob;
    }
}

void Globals::updateAllMobs(ScreenHolder* screenHolder)
{
    int i = 0;
    for(auto &mob : allMobs)
    {
        mob->updateSprite();

        if (mob->isSeePlayer(player, map->wallBounds))
        {
            screenHolder->fightScreen->open(player, mob, allMobs, i);

            break; // Как только нашли первого моба, с которым начинается бой, остальных не проверяем.
        }
        i++;
    }
}
