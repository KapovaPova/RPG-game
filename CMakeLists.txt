cmake_minimum_required(VERSION 4.1)
project(main)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp
        entity/entity.cpp
        entity/entity.h
        entity/player.cpp
        entity/player.h
        item/item.cpp
        item/item.h
        item/potion.cpp
        item/potion.h
        item/tool.cpp
        item/tool.h
        screen/getch.h
        screen/output.h
        screen/output.cpp
        move.h
        move.cpp
)