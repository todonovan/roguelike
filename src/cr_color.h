#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <ncurses.h>

#include "ncurses.h"

// ncurses6 supports up to 256 colors; we obviously won't use that many (probably)
// The enum starts at 16 to avoid overwriting the system defaults.
typedef enum
{
    BLACK = 16,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET,
    WHITE,
} CRColorCode;

// ncurses colors work in color pairs; you define both a fg color and a bg color
// ncurses6 with ext colors supports up to 256 color pairs
// ncurses expect bg first, then fg; here, they're named in reverse order because it sounds better
typedef enum
{
    WHITE_ON_BLACK = 16,
    RED_ON_BLACK,
    ORANGE_ON_BLACK,
    YELLOW_ON_BLACK,
    GREEN_ON_BLACK,
    BLUE_ON_BLACK,
    INDIGO_ON_BLACK,
    VIOLET_ON_BLACK,
    WHITE_ON_RED,
    ORANGE_ON_RED,
    YELLOW_ON_RED,
    GREEN_ON_RED,
    BLUE_ON_RED,
    INDIGO_ON_RED,
    VIOLET_ON_RED,
    BLACK_ON_RED,
} CRColorPairCode;

// In ncurses, values are represented by a short from 0 -> 1000
struct CRColorTriple
{
    CRColorCode code;
    int16_t red;
    int16_t blue;
    int16_t green;
};

void cr_init_colors();
void cr_end_color();