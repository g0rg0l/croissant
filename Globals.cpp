#include "Globals.h"

void Globals::updateAllMobs(FightScreen &fightScreen)
{
    int i = 0;
    for(auto &mob : allMobs)
    {
        if (mob.isSeePlayer(player, map.wallBounds))
        {
            fightScreen.enableFight(player, mob, i);

            break; // Как только нашли первого моба, с которым начинается бой, остальных не проверяем.
        }
        i++;
    }
}
