#ifndef CROISSANT_FIGHTSCREEN_H
#define CROISSANT_FIGHTSCREEN_H

#include "SFML/Graphics.hpp"

#include "../Entity/Mob/Mob.h"
#include "../Entity/Player/Player.h"
#include "../Resources/ResourceHolder.h"

class FightScreen : public sf::Drawable
{

public:
    FightScreen(unsigned int windowWidth, unsigned int windowHeight, float viewScale);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void enableFight(Player &PLAYER, Mob &MOB, int newId);
    void updateFight(std::vector<Mob> &allMobs);
    void disableFight();

    bool isFighting = false;

private:
    /* Параметры экрана и окна файтинга */
    unsigned int mainWindowWidth;
    unsigned int mainWindowHeight;
    float mainViewScale;

    /* Вектор всех спрайтов, составляющих окно файтинга */
    std::vector<sf::Sprite> screenElements;
    void loadFightScreenElements();

    /* Корректная проверка нажатий на клавиатуру */
    bool keyWasPressed = false;

    Player *player = nullptr;
    Mob *mob = nullptr;
    int mobIndex;
};


#endif //CROISSANT_FIGHTSCREEN_H
