#include "potion.h"

#include <iostream>

potion::potion() {}
potion::potion(int index, std::string name, int duration) : item(index, name){
    if (duration <= 0) {
        std::cout << "duration can't be <= 0" << std::endl;
    }
    this->duration  = duration;
}

void potion::print() {
    std::cout << "index: " << index << ", name: " << name << ", duration: " << duration << std::endl;
}
void potion::change_duration(int duration) {
    if (duration <= 0) {
        std::cout << "duration can't be <= 0" << std::endl;
    }
    this->duration  = duration;
}
int potion::get_duration() {
    return duration;
}

potion::~potion(){}