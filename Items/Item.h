#ifndef ENEMY1_H_ITEM_H
#define ENEMY1_H_ITEM_H

#include <iostream>

class Item
{

public:
    Item(const std::string& name, int durability) : name(name), durability(durability) {  }
    virtual ~Item() = default;

public:
    void worsen() {durability--;}

public:
    std::string getName() const {return name;}

protected:
    std::string name;
    int durability;
};


class Weapon : public Item
{
public:
    Weapon(const std::string& name, int damage, int durability) : Item(name, durability), damage(damage) {  }
    ~Weapon() override = default;

private:
    int damage;
};


class Armor : public Item
{
public:
    Armor(const std::string& name, int protection, int durability) : Item(name, durability), protection(protection) {  }
    ~Armor() override = default;

private:
    int protection;
};


#endif //ENEMY1_H_ITEM_H
