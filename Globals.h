#ifndef CROISSANT_GLOBALS_H
#define CROISSANT_GLOBALS_H

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity/Player/Player.h"

#include "Entity/Mob/Mob.h"
#include "Entity/Mob/Enemy1.h"
#include "Entity/Mob/Enemy2.h"

#include "Levels/TileMap.h"

#include "Screens/ScreenHolder.h"

class Globals
{

public:
    /////////////////////////////////// Игрок ///////////////////////////////////
    Player player = Player(100.f);

    /////////////////////////////////// Мобы ///////////////////////////////////
    std::vector<Mob*> allMobs = {
            new Enemy1(sf::Vector2f(50, 260), "mob1", "mob1"),
            new Enemy2(sf::Vector2f(250, 250), "mob2", "mob2"),
            new Enemy2(sf::Vector2f(250, 50), "mob2", "mob2")
    };

    void updateAllMobs(ScreenHolder& screenHolder);

    /////////////////////////////////// Карта ///////////////////////////////////
    TileMap map = TileMap(1);


private:


};

#endif //CROISSANT_GLOBALS_H
