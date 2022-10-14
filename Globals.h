#ifndef CROISSANT_GLOBALS_H
#define CROISSANT_GLOBALS_H

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity/Player/Player.h"
#include "Entity/Mob/Mob.h"

#include "Entity/Mob/vampire bat/VampireBat.h"

#include "Levels/TileMap.h"
#include "Screens/ScreenHolder.h"

class Globals
{

public:
    explicit Globals(sf::RenderWindow* window);
    ~Globals();

public:
    /////////////////////////////////// Игрок ///////////////////////////////////
    Player* player;

    /////////////////////////////////// Мобы //////////////////////////////////
    std::vector<Mob*> allMobs;

    void updateAllMobs(ScreenHolder* screenHolder);

    /////////////////////////////////// Карта ///////////////////////////////////
    TileMap* map;

private:
    sf::RenderWindow* window;

};

#endif //CROISSANT_GLOBALS_H
