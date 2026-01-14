#ifndef MAIN_POTION_H
#define MAIN_POTION_H

#include "item.h"

class potion : public item {
protected:
    int duration = 1; // длительность эффекта
public:
    potion();
    potion(int index, std::string name, int duration);

    void print();
    void change_duration(int duration);
    int get_duration();

    ~potion();
};


#endif //MAIN_POTION_H