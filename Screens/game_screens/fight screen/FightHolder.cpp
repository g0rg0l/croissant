#include "FightHolder.h"

FightHolder &FightHolder::getInstance()
{
    static FightHolder fightHolder;

    return fightHolder;
}

void FightHolder::attackMob(Player *player, Mob *mob, sf::Window* window)
{
    mob->takeDamage(10);
    EffectsHolders::Inventory::getInstance().createEffect("basic attack", {740, 403}, window);

    isPlayerMove = false;
}

void FightHolder::attackPlayer(Player *player, Mob *mob, sf::Window* window)
{
    int basicDamage = mob->getDamage();

    player->takeDamage(basicDamage);
    EffectsHolders::Inventory::getInstance().createEffect("basic attack", {1044, 403}, window);

    isPlayerMove = true;
}
