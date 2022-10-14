#ifndef ENEMY1_H_EFFECTSHOLDER_H
#define ENEMY1_H_EFFECTSHOLDER_H

#include <vector>
#include <string>
#include "SFML/Graphics.hpp"

#include "effects/Effect.h"
#include "effects/basic attack/BasicAttackEffect.h"
#include "effects/mob death/MobDeathEffect.h"

namespace EffectsHolders {class Inventory; class Map;}


class EffectsHolders::Inventory : public sf::Drawable
{
private:
    Inventory() = default;

public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    static Inventory& getInstance();

public:
    void createEffect(const std::string &effectName, sf::Vector2f position, sf::Window* window);
    void update();
    void clear();

public:
    std::vector<Effect*> pool;
};

class EffectsHolders::Map : public sf::Drawable
{
private:
    Map() = default;

public:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    static Map& getInstance();

public:
    void createEffect(const std::string &effectName, sf::Vector2f position, sf::Window* window);
    void update();
    void clear();

public:
    std::vector<Effect*> pool;
};



#endif //ENEMY1_H_EFFECTSHOLDER_H
