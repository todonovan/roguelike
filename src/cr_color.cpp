#include <ncurses.h>
#include "ncurses.h"

#include "cr_color.h"

void cr_init_colors()
{
    if (FALSE == has_colors())
    {
        endwin();
        printw("Your terminal does not support colors.\n");
        exit(1);
    }

    // Tell ncurses to get colors fired up
    start_color();

    // On my version of bash, up to 256 colors are supported
    // TODO: Check for # of supported colors & fallback to low-color mode if necessary
    // TODO: Is there a saner way to do this initialization? From config file?
    init_extended_color(CRColorCode::BLACK, 1000, 1000, 1000);
    init_extended_color(CRColorCode::RED, 1000, 0, 0);
    init_extended_color(CRColorCode::ORANGE, 1000, 647, 0);
    init_extended_color(CRColorCode::YELLOW, 1000, 1000, 0);
    init_extended_color(CRColorCode::GREEN, 0, 1000, 0);
    init_extended_color(CRColorCode::BLUE, 0, 0, 1000);
    init_extended_color(CRColorCode::INDIGO, 294, 0, 510);
    init_extended_color(CRColorCode::VIOLET, 931, 510, 933);
    init_extended_color(CRColorCode::WHITE, 0, 0, 0);
    
    // Initialize color pairs as ncurses works directly with pairs.
    // TODO: Same fallback implementation as with init_extended_colors.

    //      Black background
    init_extended_pair(CRColorPairCode::WHITE_ON_BLACK, CRColorCode::BLACK, CRColorCode::WHITE);
    init_extended_pair(CRColorPairCode::RED_ON_BLACK, CRColorCode::BLACK, CRColorCode::RED);
    init_extended_pair(CRColorPairCode::ORANGE_ON_BLACK, CRColorCode::BLACK, CRColorCode::ORANGE);
    init_extended_pair(CRColorPairCode::YELLOW_ON_BLACK, CRColorCode::BLACK, CRColorCode::YELLOW);
    init_extended_pair(CRColorPairCode::GREEN_ON_BLACK, CRColorCode::BLACK, CRColorCode::GREEN);
    init_extended_pair(CRColorPairCode::BLUE_ON_BLACK, CRColorCode::BLACK, CRColorCode::BLUE);
    init_extended_pair(CRColorPairCode::INDIGO_ON_BLACK, CRColorCode::BLACK, CRColorCode::INDIGO);
    init_extended_pair(CRColorPairCode::VIOLET_ON_BLACK, CRColorCode::BLACK, CRColorCode::VIOLET);
    
    //      Red background 
    init_extended_pair(CRColorPairCode::WHITE_ON_RED, CRColorCode::RED, CRColorCode::WHITE);
    init_extended_pair(CRColorPairCode::ORANGE_ON_RED, CRColorCode::RED, CRColorCode::ORANGE);
    init_extended_pair(CRColorPairCode::YELLOW_ON_RED, CRColorCode::RED, CRColorCode::YELLOW);
    init_extended_pair(CRColorPairCode::GREEN_ON_RED, CRColorCode::RED, CRColorCode::GREEN);
    init_extended_pair(CRColorPairCode::BLUE_ON_RED, CRColorCode::RED, CRColorCode::BLUE);
    init_extended_pair(CRColorPairCode::INDIGO_ON_RED, CRColorCode::RED, CRColorCode::INDIGO);
    init_extended_pair(CRColorPairCode::VIOLET_ON_RED, CRColorCode::RED, CRColorCode::VIOLET);
    init_extended_pair(CRColorPairCode::BLACK_ON_RED, CRColorCode::RED, CRColorCode::BLACK);

}

void cr_end_color()
{
    // Restore default color settings.
    attron(COLOR_PAIR(0));
}