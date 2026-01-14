#include "tool.h"

#include <iostream>

tool::tool() {}
tool::tool(int index, std::string name, int damage, int durability, int price, int efficiency, std::map<int, int> enchantments)
    : item(index, name) {
    if (damage < 0) {
        std::cout << "damage can't be < 0" << std::endl;
        return;
    }
    if (durability < 0) {
        std::cout << "durability can't be < 0" << std::endl;
        return;
    }
    if (price < 0) {
        std::cout << "price can't be < 0" << std::endl;
        return;
    }
    if (efficiency <= 0) {
        std::cout << "efficiency can't be <= 0" << std::endl;
        return;
    }
    this->damage = damage;
    this->durability = durability;
    this->price = price;
    this->efficiency = efficiency;
    this->enchantments = enchantments;
}

void tool::print() {
    std::cout << "index: " << index << ", name: " << name << ", damage: " << damage << ", durability: " << durability << ", price: " << price << ", efficiency: " << efficiency << std::endl;
    for (std::pair<const int, int> enchantment : enchantments) {
        std::cout << "    " << enchantment.first << " : " << enchantment.second << " level" << std::endl;
    }
}
void tool::change_damage(int damage) {
    if (damage < 0) {
        std::cout << "damage can't be < 0" << std::endl;
        return;
    }
    this->damage = damage;
}
int tool::get_damage() {
    return damage;
}
void tool::change_durability(int durability) {
    if (durability < 0) {
        std::cout << "durability can't be < 0" << std::endl;
        return;
    }
    this->durability = durability;
}
int tool::get_durability() {
    return durability;
}
void tool::change_price(int price) {
    if (price < 0) {
        std::cout << "price can't be < 0" << std::endl;
        return;
    }
    this->price = price;
}
int tool::get_price() {
    return price;
}
void tool::change_efficiency(int efficiency) {
    if (efficiency <= 0) {
        std::cout << "efficiency can't be <= 0" << std::endl;
        return;
    }
    this->efficiency = efficiency;
}
int tool::get_efficiency() {
    return efficiency;
}
void tool::change_enchantments(std::map<int, int> enchantments) {
    this->enchantments = enchantments;
}
std::map<int, int> tool::get_enchantments() {
    return enchantments;
}

tool::~tool() {}
