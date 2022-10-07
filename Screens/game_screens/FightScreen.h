#ifndef ENEMY1_H_FIGHTSCREEN_H
#define ENEMY1_H_FIGHTSCREEN_H

#include "SFML/Graphics.hpp"
#include "../dynamic_blur.hpp"

#include "../../Entity/Player/Player.h"
#include "../../Entity/Mob/Mob.h"
#include "../../GUI/GUI.h"

class FightScreen
{

public:
    explicit FightScreen(sf::RenderWindow* window = nullptr,
                         sf::RenderTexture* renderTexture = nullptr,
                         sf::Clock* clock = nullptr)
            : window(window), background(renderTexture), clock(clock) { }

public:
    void open(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex);
    void loadVisualElements(Player* player, Mob* mob);

private:
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

private:
    std::vector<UniversalButton*> allButtons;
    std::vector<FIGHT_GUI::HPBar> allHPBars;
    std::vector<FIGHT_GUI::FighterIcon> allFightersIcons;

    sf::Sprite fightBackground;

};


#endif //ENEMY1_H_FIGHTSCREEN_H
