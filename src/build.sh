#!/bin/bash

echo "Compiling..."

g++ -std=c++17 ./curses_roguelike.cpp ./cr_color.cpp -o ../build/roguelike -lncursesw