#include "EffectsHolder.h"

using namespace EffectsHolders;

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& effect : pool)
    {
        if (!effect->isCompleted) target.draw(*effect, states);
    }
}

void Inventory::createEffect(const std::string &effectName, sf::Vector2f position, sf::Window* window)
{
    if (effectName == "basic attack")
    {
        Effect* effect = new BasicAttackEffect(position, window);
        pool.push_back(effect);
    }
}

void Inventory::update()
{
    for (auto& effect : pool)
    {
        effect->update();
    }
}

Inventory &Inventory::getInstance() {
    static Inventory inventory;

    return inventory;
}

void Inventory::clear()
{
    for (auto& effect : pool)
    {
        delete effect;
    }
    pool.clear();
}




void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto& effect : pool)
    {
        if (!effect->isCompleted) target.draw(*effect, states);
    }
}

void Map::createEffect(const std::string &effectName, sf::Vector2f position, sf::Window* window)
{
    if (effectName == "mob death")
    {
        Effect* effect = new MobDeathEffect(position, window);
        pool.push_back(effect);
    }
}

void Map::update()
{
    for (auto& effect : pool)
    {
        effect->update();
    }
}

Map &Map::getInstance() {
    static Map map;

    return map;
}

void Map::clear()
{
    for (auto& effect : pool)
    {
        delete effect;
    }
    pool.clear();
}



