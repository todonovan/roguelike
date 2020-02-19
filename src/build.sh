#!/bin/bash

echo "Compiling..."

g++ -std=c++17              \
    ./cr_color.cpp          \
    ./cr_glyph.cpp          \
    ./map.cpp               \
    ./player.cpp            \
    ./ecs/ecs_world.cpp     \
    ./ecs/ecs_component.cpp \
    ./curses_roguelike.cpp  \
-o ../build/roguelike -lncursesw

echo "Done!"
