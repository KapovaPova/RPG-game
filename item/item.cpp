#include "item.h"

#include <iostream>

item::item() {}
item::item(int index, std::string name) {
    if (index < 0) {
        std::cout << "index can't be < 0" << std::endl;
        return;
    }
    this->index = index;
    this->name = name;
}

void item::print() {
    std::cout << "index: " << index << ", name: " << name << std::endl;
}
int item::get_index() {
    return index;
}
void item::change_name(std::string name) {
    this->name = name;
}
std::string item::get_name() {
    return name;
}

item::~item(){}