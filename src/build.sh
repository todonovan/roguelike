#!/bin/bash

echo "Compiling..."

rm ../build/*

g++ -std=c++17 ./curses_roguelike.cpp -o ../build/roguelike -lncurses