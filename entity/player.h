#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "entity.h"

#include <map>
#include <vector>

class player: public entity {
protected:
    std::map<int, int> effects; // эффекты игрока; индекс эффекта : сколько осталось эффекту(секунды)
    int ability = 0; // способность игрока, индекс способности
    int level = 0; // уровень игрока
    std::vector<int> inventory; // инвентарь игрока
	int money = 0; // деньги игрока
public:
    player(int health, int x, int y, int size_x, int size_y, std::map<int, int> effects,
        int ability, int level, std::vector<int> inventory, int money);

    void print();
	void change_effects(std::map<int, int> effects);
	std::map<int, int> get_effects();
	int get_ability();
    void change_level(int level);
	int get_level();
    void change_inventory(std::vector<int> inventory);
	std::vector<int> get_inventory();
	void change_money(int money);
	int get_money();

	~player();
};

#endif //MAIN_PLAYER_H