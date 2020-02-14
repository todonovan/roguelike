#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "ncurses.h"
#include "cr_color.h"

void init_ncurses()
{
    // General init calls
    initscr();   
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, TRUE);
    keypad(stdscr, TRUE);

    cr_init_colors();
}

void end_ncurses()
{
    cr_end_color();
    endwin();
}

int main(int argc, char *argv[])
{
    init_ncurses();

    attron(COLOR_PAIR(CRColorPairCode::BLACK_ON_RED) | A_BOLD);
    printw("Welcome to Croguelike!\n");
    attroff(A_BOLD);
    printw("This one isn't bolded!\n");
    attroff(COLOR_PAIR(CRColorPairCode::BLACK_ON_RED));
    attron(COLOR_PAIR(CRColorPairCode::RED_ON_BLACK));
    printw("This one has changed the color.\n");
    attroff(COLOR_PAIR(CRColorPairCode::RED_ON_BLACK));

    getch();
    
    end_ncurses();

    return 0;
}