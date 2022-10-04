#include "Globals.h"

void Globals::updateAllMobs(ScreenHolder& screenHolder)
{
    int i = 0;
    for(auto &mob : allMobs)
    {
        if (mob->isSeePlayer(player, map.wallBounds))
        {
            screenHolder.fightScreen.open(&player, mob, allMobs, i);

            break; // Как только нашли первого моба, с которым начинается бой, остальных не проверяем.
        }
        i++;
    }
}
