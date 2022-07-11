#ifndef CROISSANT_GLOBALS_H
#define CROISSANT_GLOBALS_H

#include "SFML/Graphics.hpp"

#include "Entity/Player/Player.h" // Игрок
#include "Levels/TileMap.h" // Карта

class Globals
{

public:
    /////////////////////////////////// Игрок ///////////////////////////////////
    Player player = Player("player.png", 100.f);


    /////////////////////////////////// Карта ///////////////////////////////////
    TileMap map = TileMap(1);


private:


};


#endif //CROISSANT_GLOBALS_H
