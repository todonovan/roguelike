#!/bin/bash

echo "Compiling..."

g++ -std=c++17 ./curses_roguelike.cpp ./cr_color.cpp ./vector.cpp ./map.cpp -o ./ecs/ecs_world.cpp -o ../build/roguelike -lncursesw