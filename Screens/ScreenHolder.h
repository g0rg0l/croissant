#ifndef ENEMY1_H_SCREENHOLDER_H
#define ENEMY1_H_SCREENHOLDER_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "dynamic_blur.hpp"

#include "../Resources/ResourceHolder.h"
#include "../Entity/Player/Player.h"
#include "../Entity/Mob/Mob.h"
#include "../GUI/GUI.h"

class ScreenHolder
{
public:
    explicit ScreenHolder(sf::RenderWindow* window = nullptr, sf::RenderTexture* renderTexture = nullptr,
                          sf::Clock* clock = nullptr);

public:
    /* Меню паузы */
    void openPauseMenu();

    /* Меню боя */
    void openFightMenu(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex);

private:
    /* Меню паузы */
    std::vector<sf::RectangleShape> allPauseMenuElements;
    void loadPauseMenuElements();

    /* Меню боя */
    std::vector<FIGHT_GUI::AttackButton> allFightMenuButtons;
    std::vector<FIGHT_GUI::HPBar> allHPBars;
    void loadHpBars(Player* player, Mob* mob);
    void loadFightMenuElements();

    /* тест интерфейса */
    sf::Sprite fightBackground;

private:
    /* Указатели для работы с внешним окном из цикла отображения второстепенных окон */
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

};


#endif //ENEMY1_H_SCREENHOLDER_H
