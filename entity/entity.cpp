#include "entity.h"

#include <iostream>

entity::entity() {}
entity::entity(int health, int x, int y, int size_x, int size_y) {
    if (health <= 0) {
        std::cout << "health can't be <= 0" << std::endl;
        return;
    }
    if (x < 0 || y < 0) {
        std::cout << "x and y can't be < 0" << std::endl;
        return;
    }
    if (size_x <= 0 || size_y <= 0) {
        std::cout << "size_x and size_y can't be <= 0" << std::endl;
        return;
    }
    this->health = health;
    this->x = x;
    this->y = y;
    this->size_x = size_x;
    this->size_y = size_y;
}

void entity::print() {
    std::cout << "health: " << health << ", x: " << x << ", y: " << y << ", size_x: " << size_x << ", size_y: " << size_y << std::endl;
}
void entity::change_health(int health) {
    if (health <= 0) {
        std::cout << "health can't be <= 0" << std::endl;
        return;
    }
    this->health = health;
}
int entity::get_health() {
    return health;
}
void entity::move(int x, int y) {
    if (x < 0 || y < 0) {
        std::cout << "x and y can't be < 0" << std::endl;
        return;
    }
    this->x = x;
    this->y = y;
}
std::pair<int, int> entity::get_position() {
    return std::make_pair(x, y);
}
void entity::change_size(int size_x, int size_y) {
    if (size_x <= 0 || size_y <= 0) {
        std::cout << "size_x and size_y can't be <= 0" << std::endl;
        return;
    }
    this->size_x = size_x;
    this->size_y = size_y;
}
std::pair<int, int> entity::get_size() {
    return std::make_pair(size_x, size_y);
}

entity::~entity(){}
