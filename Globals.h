#ifndef CROISSANT_GLOBALS_H
#define CROISSANT_GLOBALS_H

#include "SFML/Graphics.hpp"
#include <iostream>

#include "Entity/Player/Player.h"
#include "Entity/Mob/Mob.h"
#include "Entity/Mob/nefarious bat/NefariousBat.h"
#include "Entity/Mob/crimson imp/CrimsonImp.h"
#include "Entity/Mob/spiked ravager/SpikedRavager.h"
#include "Entity/Mob/glaring overlord/GlaringOverlord.h"
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
