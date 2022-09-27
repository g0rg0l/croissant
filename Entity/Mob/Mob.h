#ifndef CROISSANT_MOB_H
#define CROISSANT_MOB_H

#include "SFML/Graphics.hpp"
#include <cmath>

#include "../../Resources/ResourceHolder.h"
#include "../Player/Player.h"
#include "../geometrical_functions/mobView.h"

class Mob : public  sf::Drawable
{
public:
    /////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
    explicit Mob(sf::Vector2f position, const std::string &textureHolderKey, const std::string& name);

    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////
    bool isSeePlayer(Player &player, const std::vector<sf::FloatRect> &allWallBounds);

    /////////////////////////////////// Бой ///////////////////////////////////
    int getHp() const {return hp;}

    void takeDamage(int damage) { hp -= damage;}

    /////////////////////////////////// Информация ///////////////////////////////////
    std::string getName() {return name;}

protected:
    /////////////////////////////////// Создание моба ///////////////////////////////////
    void loadSprite(); // Наложение текстуры на спрайт
    void loadPosition(); // Выставление положения на карте
    virtual void setPreferences() = 0; // Загрузка параметров персонажа

protected:
    /* Спрайт */
    std::string textureHolderKey; // Ключ доступа к текстуре
    sf::Sprite sprite; // Спрайт

    /* Положение на карте */
    sf::Vector2f position;

    /* Дальность видимости */
    int visibilityDistance = 0;

    /* Бой */
    int hp = 0;

    /* Информация */
    std::string name;
};


#endif //CROISSANT_MOB_H
