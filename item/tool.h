#ifndef MAIN_TOOL_H
#define MAIN_TOOL_H

#include "item.h"

#include <map>

class tool : public item {
protected:
    int damage = 0; // урон, наносимый этим инструментом
    int durability = 0; // прочность инструмента
    int price = 0; // цена в магазине
    int efficiency = 1; // во сколько будет ускоряться добыча блока
    std::map<int, int> enchantments; // зачарования; индекс зачарования : уровень зачарования
public:
    tool();
    tool(int index, std::string name, int damage, int durability, int price, int efficiency, std::map<int, int> enchantments);

    void print();
    void change_damage(int damage);
    int get_damage();
    void change_durability(int durability);
    int get_durability();
    void change_price(int price);
    int get_price();
    void change_efficiency(int efficiency);
    int get_efficiency();
    void change_enchantments(std::map<int, int> enchantments);
    std::map<int, int> get_enchantments();

    ~tool();
};

#endif //MAIN_TOOL_H