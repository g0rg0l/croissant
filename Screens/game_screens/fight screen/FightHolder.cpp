#include "FightHolder.h"

FightHolder &FightHolder::getInstance()
{
    static FightHolder fightHolder;

    return fightHolder;
}

void FightHolder::attackMob(Player *player, Mob *mob)
{
    mob->takeDamage(10);

    isPlayerMove = false;
}

void FightHolder::attackPlayer(Player *player, Mob *mob)
{
    player->takeDamage(10);

    isPlayerMove = true;
}
