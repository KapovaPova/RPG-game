#ifndef MAIN_ITEM_H
#define MAIN_ITEM_H

#include <string>

class item {
protected:
    int index = 0; // индекс предмета для инвентаря
    std::string name = ""; // название предмета
public:
    item();
    item(int index, std::string name);

    void print();
    int get_index();
    void change_name(std::string name);
    std::string get_name();

    ~item();
};

#endif //MAIN_ITEM_H