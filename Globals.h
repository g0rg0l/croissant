#ifndef CROISSANT_GLOBALS_H
#define CROISSANT_GLOBALS_H

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity/Player/Player.h"
#include "Entity/Mob/Mob.h"
#include "Levels/TileMap.h"
#include "Screens/FightScreen.h"

class Globals
{

public:
    /////////////////////////////////// Игрок ///////////////////////////////////
    Player player = Player(100.f);

    /////////////////////////////////// Мобы ///////////////////////////////////
    std::vector<Mob> allMobs = {Mob()};

    void updateAllMobs(FightScreen &fightScreen);

    /////////////////////////////////// Карта ///////////////////////////////////
    TileMap map = TileMap(1);


private:


};

#endif //CROISSANT_GLOBALS_H
