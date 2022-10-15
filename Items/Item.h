#ifndef ENEMY1_H_ITEM_H
#define ENEMY1_H_ITEM_H

#include <iostream>
#include <vector>
#include <utility>

class Item
{

public:
    Item(std::string  name, std::string  specification, int damage, int protection);
    virtual ~Item() = default;


public:
    std::string getName() const {return name;}
    std::string getSpecification() const {return specification;}
    int getDamage() const {return damage;}
    int getProtection() const {return protection;}

protected:
    std::string specification;
    std::string name;
    int damage;
    int protection;
};


class Weapon : public Item
{
public:
    Weapon(const std::string& name, int damage);
    ~Weapon() override = default;

};


class Armor : public Item
{
public:
    Armor(const std::string& specification, const std::string& name, int protection);
    ~Armor() override = default;

};


#endif //ENEMY1_H_ITEM_H
