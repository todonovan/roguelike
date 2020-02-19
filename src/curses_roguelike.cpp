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
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "cr_glyph.fwd.h"
#include "map.fwd.h"
#include "ecs/ecs_world.fwd.h"
#include "ecs/ecs_component.fwd.h"

#include "cr_common.h"
#include "cr_color.h"
#include "cr_glyph.h"
#include "map.h"
#include "player.h"

#include "ecs/ecs_world.h"
#include "ecs/ecs_component.h"


#define MAP_W 80
#define MAP_H 50

typedef enum
{
    MOVEMENT,
    INVENTORY,
    LOOK,
    START_MENU
} GameMode;

struct GameState
{
    GameMode mode;
    Entity player;
    ECSWorld *world;
    Map map;
};


void init_ncurses()
{
    setenv("LINES", "40", 1);
    setenv("COLUMNS", "40", 1);

    winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    // General init calls
    initscr();   
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, TRUE);
    keypad(stdscr, TRUE);

    printw("Lines is %s, Cols is %s\n", getenv("LINES"), getenv("COLUMNS"));
/*     if (ERR == resizeterm(40, 50))
    {

        CR_ERROR("Resizing didn't work\n");
        getch();
    }; */

    if (cr_init_colors() != CRResultCode::SUCCESS)
    {
        endwin();
        exit(1);
    }

    // Set default color for terminal; the last param says 'use extended colors'
    color_set(COLOR_PAIR(default_color_pair), (void *)&default_color_pair);
}

void end_game(GameState *state)
{
    kill_map(&state->map);
    kill_world(state->world);
}

void end_ncurses()
{
    cr_end_color();
    endwin();
}

void init_game_state(GameState *state)
{
    state->world = new_world();
    state->map = new_map(MAP_H, MAP_W);
    state->mode = GameMode::START_MENU;
    state->player = create_player(state->world);
}

int main(int argc, char *argv[])
{
    init_ncurses();
    GameState game_state = {};
    init_game_state(&game_state);

    


    Renderable *player_renderable = get_renderable(game_state->world, game_state->player);
    attron(COLOR_PAIR(player_renderable->glyph.color_pair));
    mvaddch(2, 7, player_renderable->glyph.sigil);
    attroff(COLOR_PAIR(player_renderable->glyph.color_pair));
    
    getch();
    end_ncurses();
    end_game(game_state);

    return 0;
}