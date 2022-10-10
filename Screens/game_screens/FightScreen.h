#ifndef ENEMY1_H_FIGHTSCREEN_H
#define ENEMY1_H_FIGHTSCREEN_H

#include "SFML/Graphics.hpp"
#include "../dynamic_blur.hpp"

#include "../../Entity/Player/Player.h"
#include "../../Entity/Mob/Mob.h"
#include "../../GUI/GUI.h"
#include "../../Animations/Animator.h"

class FightScreen
{

public:
    explicit FightScreen(sf::RenderWindow* window, sf::RenderTexture* renderTexture, sf::Clock* clock)
            : window(window), background(renderTexture), clock(clock)
    {
        textureForAnimator.create(window->getSize().x, window->getSize().y);
    }

public:
    void open(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex);
    void loadVisualElements(Player* player, Mob* mob);
    void manifest();
    void unManifest();

private:
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

    sf::Sprite backgroundSprite;
    sf::RenderTexture textureForAnimator;

private:
    std::vector<UniversalButton*> allButtons;
    std::vector<FIGHT_GUI::HPBar> allHPBars;
    std::vector<FIGHT_GUI::FighterIcon> allFightersIcons;
    sf::Sprite fightBackground;

};


#endif //ENEMY1_H_FIGHTSCREEN_H
