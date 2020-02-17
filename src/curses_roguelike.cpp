// CRoguelike (name temporary): An in-progress roguelike engine in C and ncurses
// Copyright (C) 2020 Terrence O'Donovan, Jr.
// This copyright notice shall apply to all files contained within this
// repository, source code or otherwise, created by me.


// I don't know why you'd want to use this project at all, but well, here you go:

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This program is free software: you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *                                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "cr_common.h"
#include "cr_color.h"
#include "map.h"
#include "ecs/ecs.h"

typedef enum
{
    MOVEMENT,
    INVENTORY,
    LOOK,
} GameMode;

struct GameState
{
    GameMode mode;
    Entity player;
    ECSWorld world;
    Map map;
};

void init_ncurses()
{
    // General init calls
    initscr();   
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, TRUE);
    keypad(stdscr, TRUE);

    if (cr_init_colors() != CRResultCode::SUCCESS)
    {
        endwin();
        exit(1);
    }
}

void end_ncurses()
{
    cr_end_color();
    endwin();
}

void init_game_state(GameState *state)
{

}

int main(int argc, char *argv[])
{
    init_ncurses();
    GameState *game_state = (GameState *)malloc(sizeof(GameState));
    init_game_state(game_state);
    
    getch();
    end_ncurses();

    return 0;
}