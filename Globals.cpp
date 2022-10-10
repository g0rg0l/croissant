#include "Globals.h"

Globals::Globals(sf::RenderWindow* window)
    : window(window)
{
    player = new Player(100);
    map = new TileMap;

    allMobs = {
        new NefariousBat("nefarious bat", {200, 200}, {16, 16}, "nefarious bat", window),
        new CrimsonImp("crimson imp", {200, 184}, {16, 16}, "crimson imp", window),
        new SpikedRavager("spiked ravager", {200, 168}, {16, 16}, "spiked ravager", window),
        new GlaringOverlord("glaring overlord", {32, 156}, {32, 32}, "glaring overlord", window)
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
