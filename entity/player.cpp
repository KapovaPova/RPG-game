#include "player.h"

#include <iostream>

player::player(int health, int x, int y, int size_x, int size_y, std::map<int, int> effects,
        int ability, int level, std::vector<int> inventory, int money) : entity(health, x, y, size_x, size_y) {
    if (ability < 0) {
        std::cout << "ability can't be < 0" << std::endl;
        return;
    }
    if (level < 0) {
        std::cout << "level can't be < 0" << std::endl;
        return;
    }
    if (money < 0) {
        std::cout << "money can't be < 0" << std::endl;
        return;
    }
    this->effects = effects;
    this->ability = ability;
    this->level = level;
    this->inventory = inventory;
    this->money = money;
}

void player::print() {
    std::cout << "health: " << health << ", x: " << x << ", y: " << y << ", size_x: " << size_x << ", size_y: " << size_y << std::endl;
    std::cout << "effects: " << std::endl;
    for (std::pair<const int, int> effect : effects) {
        std::cout << "    " << effect.first << " : " << effect.second << " seconds" << std::endl;
    }
    std::cout << "ability: " << ability << ", level: " << level << ", inventory: " << std::endl;
    for (int item : inventory) {
        std::cout << "    " << item << std::endl;
    }
    std::cout << "money: " << money << std::endl;
}
void player::change_effects(std::map<int, int> effects) {
    this->effects = effects;
}
std::map<int, int> player::get_effects() {
    return effects;
}
int player::get_ability() {
    return ability;
}
void player::change_level(int level) {
    if (level < 0) {
        std::cout << "level can't be < 0" << std::endl;
        return;
    }
    this->level = level;
}
int player::get_level() {
    return level;
}
void player::change_inventory(std::vector<int> inventory) {
    this->inventory = inventory;
}
std::vector<int> player::get_inventory() {
    return inventory;
}
void player::change_money(int money) {
    if (money < 0) {
        std::cout << "money can't be < 0" << std::endl;
        return;
    }
    this->money = money;
}
int player::get_money() {
    return money;
}

player::~player() {}
