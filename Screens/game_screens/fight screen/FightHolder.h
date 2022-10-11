#ifndef ENEMY1_H_FIGHTHOLDER_H
#define ENEMY1_H_FIGHTHOLDER_H

#include "../../../Entity/Mob/Mob.h"
#include "../../../Entity/Player/Player.h"

class FightHolder
{
private:
    FightHolder() = default;
    ~FightHolder() = default;

public:
    static FightHolder& getInstance();

public:
     bool isPlayerMove = true;

public:
    void attackMob(Player* player, Mob* mob);
    void attackPlayer(Player* player, Mob* mob);
};


#endif //ENEMY1_H_FIGHTHOLDER_H
