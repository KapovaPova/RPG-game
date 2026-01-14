#include "move.h"

void move(std::vector<std::vector<char>> map, char char_empty, entity& entity, char input) {
    switch (input) {
        case 'w':
            for (int i = 0; i < entity.get_size().first; i++) {
                if (map.at(entity.get_position().second - 1).at(entity.get_position().first + i) != char_empty) {
                    return;
                }
            }
            entity.move(entity.get_position().first, entity.get_position().second - 1);
            break;
        case 'a':
            for (int i = 0; i < entity.get_size().second; i++) {
                if (map.at(entity.get_position().second + i).at(entity.get_position().first - 1) != char_empty) {
                    return;
                }
            }
            entity.move(entity.get_position().first - 1, entity.get_position().second);
            break;
        case 's':
            for (int i = 0; i < entity.get_size().first; i++) {
                if (map.at(entity.get_position().second + entity.get_size().second).at(entity.get_position().first + i) != char_empty) {
                    return;
                }
            }
            entity.move(entity.get_position().first, entity.get_position().second + 1);
            break;
        case 'd':
            for (int i = 0; i < entity.get_size().second; i++) {
                if (map.at(entity.get_position().second + i).at(entity.get_position().first + entity.get_size().first) != char_empty) {
                    return;
                }
            }
            entity.move(entity.get_position().first + 1, entity.get_position().second);
            break;
        default:
            break;
    }
}