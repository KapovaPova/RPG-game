#include "output.h"
#include <iostream>
#include <algorithm>

void print(std::vector<std::vector<char>> map, char char_player, char char_mob, player player, std::vector<entity> mobs) {

    std::cout << "\033[2J\033[1;1H" << std::flush;

    int size_x = map.at(0).size();
    int size_y = map.size();

    int player_x = player.get_position().first;
    int player_y = player.get_position().second;
    int player_size_x = player.get_size().first;
    int player_size_y = player.get_size().second;

    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            if (j < player_x + player_size_x && j >= player_x && i < player_y + player_size_y && i >= player_y) {
                std::cout << char_player << char_player;
            } else if (std::find_if(mobs.begin(), mobs.end(), [i, j](entity& mob) {
                return (mob.get_position().first == j) && (mob.get_position().second == i);
            }) != mobs.end()) {
                std::cout << char_mob << char_mob;
            } else {
                std::cout << map.at(i).at(j) << map.at(i).at(j);
            }
        }
        std::cout << std::endl;
    }
}