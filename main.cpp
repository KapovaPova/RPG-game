#include <iostream>
#include <vector>
#include "screen/getch.h"
#include "screen/output.h"
#include "entity/player.h"
#include "move.h"
#include "Pathfinder.h"

//параметры при запуске игры
const int player_health = 10;
const int player_x = 10;
const int player_y = 10;
const int player_size_x = 3;
const int player_size_y = 2;
const std::map<int, int> player_effects{};
const int ability = 0;
const int level = 0;
const std::vector<int> inventory{};
const int money = 0;

const int mob_health = 20;
const int mob_size_x = 1; //НЕ ИЗМЕНЯТЬ
const int mob_size_y = 1; //НЕ ИЗМЕНЯТЬ

const char char_player = 'p';
const char char_mob = 'm';
const char char_empty = ' ';
const std::vector<std::vector<char>> map = {
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#',' ',' ',' ','#','#','#','#','#','#','#',' ','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#',' ','#','#','#','#','#','#',' ',' ','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
};

int main() {
    srand(time(nullptr));

    //создаем игрока
    player player(player_health, player_x, player_y, player_size_x, player_size_y,
        player_effects, ability, level, inventory, money);

    //создаем мобов
    std::vector<entity> mobs;
    for (int i = 0; i < rand() % 5 + 1; i++) {
        int x = 0;
        int y = 0;
        do {
            x = rand() % (map.at(0).size() - 2) + 1;
            y = rand() % (map.size() - 2) + 1;
        } while (map.at(y).at(x) != char_empty);
        mobs.emplace_back(mob_health, x, y, mob_size_x, mob_size_y);
    }

    //находим ближайший путь до игрока
    std::vector<std::vector<Node>> path;
    for (entity& mob : mobs) {
        std::vector<Node> cur_path = FindPath(map, char_empty, Node(mob.get_position().first, mob.get_position().second),
    Node(player.get_position().first, player.get_position().second));
        cur_path.erase(cur_path.begin());
        path.push_back(cur_path);
    }

    //основной цикл
    print(map, char_player, char_mob, player, mobs);
    char input = getch();
    entity last_player_pos;
    last_player_pos.move(player.get_position().first, player.get_position().second);
    while (input != 27) {
        //управление
        move(map, char_empty, player, input);

        if (player.get_position().first != last_player_pos.get_position().first ||
            player.get_position().second != last_player_pos.get_position().second) {

            last_player_pos.move(player.get_position().first, player.get_position().second);
            path.clear();
            for (entity& mob : mobs) {
                std::vector<Node> cur_path = FindPath(map, char_empty, Node(mob.get_position().first, mob.get_position().second),
            Node(player.get_position().first, player.get_position().second));
                cur_path.erase(cur_path.begin());
                path.push_back(cur_path);
            }
        }


        //управление мобов
        for (int i = 0; i < mobs.size(); i++) {
            entity& mob = mobs.at(i);
            if (!path.at(i).empty()) {
                mob.move(path.at(i).at(0).x, path.at(i).at(0).y);
                path.at(i).erase(path.at(i).begin());
            }
        }

        //вывод и повторение
        print(map, char_player, char_mob, player, mobs);
        input = getch();
    }

    return 0;
}
