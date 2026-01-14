#ifndef MAIN_ENTITY_H
#define MAIN_ENTITY_H

#include <iostream>

class entity {
protected:
    int health = 1; // здоровье
    int x = 0; // координата x
    int y = 0; // координата y
    int size_x = 1; // размер объекта по горизонтали
    int size_y = 1; // размер объекта по вертикали
public:
    entity();
    entity(int health, int x, int y, int size_x, int size_y);

    void print();
    void change_health(int health);
    int get_health();
    void move(int x, int y);
    std::pair<int, int> get_position();
    void change_size(int size_x, int size_y);
    std::pair<int, int> get_size();

    ~entity();
};

#endif //MAIN_ENTITY_H