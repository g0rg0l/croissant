#include "FightHolder.h"

FightHolder &FightHolder::getInstance()
{
    static FightHolder fightHolder;

    return fightHolder;
}

void FightHolder::attackMob(Player *player, Mob *mob, sf::Window* window)
{
    /* Расчитываем урон, который будет нанесён мобу */
    int basicPlayerDamage = player->getDamage();
    int playersWeaponDamage = (player->inventory.inv[4]) ? player->inventory.inv[4]->getDamage() : 0;
    int totalDamageToMob = basicPlayerDamage + playersWeaponDamage;

    mob->takeDamage(totalDamageToMob);
    EffectsHolders::Inventory::getInstance().createEffect("basic attack", {740, 403}, window);

    isPlayerMove = false;
}

void FightHolder::attackPlayer(Player *player, Mob *mob, sf::Window* window)
{
    /* Расчитываем урон, который будет нанесён игроку */
    int basicMobDamage = mob->getDamage();
    double mobDamageMultiplier = getRandomDamageMultiplier(
            1 - mob->getRangeOfDamageMultiplier(),
            1 + mob->getRangeOfDamageMultiplier()
            );
    int totalDamageToPlayer = (int) (basicMobDamage * mobDamageMultiplier);

    player->takeDamage(totalDamageToPlayer);
    EffectsHolders::Inventory::getInstance().createEffect("basic attack", {1044, 403}, window);

    isPlayerMove = true;
}
