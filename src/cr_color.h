#pragma once

#include "cr_common.h"
#include "cr_glyph.fwd.h"


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
    LIGHTER_GRAY,
    LIGHT_GRAY,
    GRAY,
    DARK_GRAY,
    DARKER_GRAY,
    BEIGE,
    TAN,
    BROWN,
    DARK_BROWN,
    AZURE,
    BLUEBERRY,
} CRColor;

// Ncurses colors work in color pairs; you define both a fg color and a bg color.
// I used to think only 256 color pairs were supported, but actually it's 65536... 
// Should these pairs, or colors generally, be customizable by the user? If so, how?? 
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
    LIGHTER_GRAY_ON_BLACK,
    LIGHT_GRAY_ON_BLACK,
    GRAY_ON_BLACK,
    DARK_GRAY_ON_BLACK,
    DARKER_GRAY_ON_BLACK,
    BEIGE_ON_BLACK,
    TAN_ON_BLACK,
    BROWN_ON_BLACK,
    DARK_BROWN_ON_BLACK,
    AZURE_ON_BLACK,
    BLUEBERRY_ON_BLACK,

    WHITE_ON_BLUEBERRY,
    BLACK_ON_BLUEBERRY,
    GRAY_ON_BLUEBERRY,
    YELLOW_ON_BLUEBERRY,
    
    WHITE_ON_BLUE,
    BLACK_ON_BLUE,
    GRAY_ON_BLUE,
    YELLOW_ON_BLUE,

    WHITE_ON_GRAY,

    WHITE_ON_RED,
    ORANGE_ON_RED,
    YELLOW_ON_RED,
    GREEN_ON_RED,
    BLUE_ON_RED,
    INDIGO_ON_RED,
    VIOLET_ON_RED,
    BLACK_ON_RED,
} CRColorPair;

const CRColor default_fg = CRColor::LIGHTER_GRAY;
const CRColor default_bg = CRColor::BLACK;
const CRColorPair default_color_pair = CRColorPair::LIGHTER_GRAY_ON_BLACK;

CRResultCode cr_init_colors();
void cr_end_color();
CRColorPair cr_color_pair_from_colors(CRColor fg, CRColor bg);