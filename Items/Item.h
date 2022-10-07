#ifndef ENEMY1_H_ITEM_H
#define ENEMY1_H_ITEM_H

#include <iostream>
#include <vector>

class Item
{

public:
    Item(const std::string& name, int durability, const std::string& specification)
        : name(name), durability(durability), specification(specification) {  }
    virtual ~Item() = default;

public:
    void worsen() {durability--;}

public:
    std::string getName() const {return name;}
    std::string getSpecification() const {return specification;}

protected:
    std::string specification;
    std::string name;
    int durability;
};


class Weapon : public Item
{
public:
    Weapon(const std::string& name, int damage, int durability)
        : Item(name, durability, "weapon"), damage(damage) {  }

    ~Weapon() override = default;

private:
    int damage;
};


class Armor : public Item
{
public:
    Armor(const std::string& specification, const std::string& name, int protection, int durability)
        : Item(name, durability, specification), protection(protection) {  }

    ~Armor() override = default;

private:
    int protection;
};


#endif //ENEMY1_H_ITEM_H
