#include <stdio.h>

#include "ncurses.h"

int main(int argc, char *argv[])
{
    initscr();   
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);

    attron(COLOR_PAIR(1));
    printw("Welcome to Croguelike!\n");
    attroff(COLOR_PAIR(1));
    
    getch();


    endwin();

    return 0;
}