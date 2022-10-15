#include "Item.h"


Item::Item(std::string name, std::string specification, int damage, int protection)
    : name(std::move(name)), specification(std::move(specification)),
      damage(damage), protection(protection)
{

}

Weapon::Weapon(const std::string &name, int damage)
    : Item(name, "weapon", damage, 0)
{

}

Armor::Armor(const std::string &specification, const std::string &name, int protection)
    : Item(name, specification, 0, protection)
{

}
