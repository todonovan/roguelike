#include "cr_common.h"
#include "cr_color.h"
#include "cr_glyph.h"

CRResultCode cr_init_colors()
{
    if (FALSE == has_colors())
    {
        CR_ERROR("Your terminal does not support colors.");
        return CRResultCode::ERR_FATAL;
    }

    // Tell ncurses to get colors fired up
    start_color();

    if (COLORS != 256 || COLOR_PAIRS != 65536)
    {
        CR_ERROR("Your terminal does not support enough colors. Implementing 8 color fallbacks is a to-do; your patience is appreciated.");
        return CRResultCode::ERR_FATAL;
    }

    // On my version of bash, up to 256 colors are supported
    // TODO: Check for # of supported colors & fallback to low-color mode if necessary
    // TODO: Is there a saner way to do this initialization? From config file?
    init_extended_color(CRColor::BLACK, 0, 0, 0);
    init_extended_color(CRColor::RED, 1000, 0, 0);
    init_extended_color(CRColor::ORANGE, 1000, 647, 0);
    init_extended_color(CRColor::YELLOW, 1000, 1000, 0);
    init_extended_color(CRColor::GREEN, 0, 1000, 0);
    init_extended_color(CRColor::BLUE, 0, 0, 1000);
    init_extended_color(CRColor::INDIGO, 294, 0, 510);
    init_extended_color(CRColor::VIOLET, 931, 510, 933);
    init_extended_color(CRColor::WHITE, 1000, 1000, 1000);
    init_extended_color(CRColor::LIGHTER_GRAY, 929, 929, 929);
    init_extended_color(CRColor::LIGHT_GRAY, 827, 827, 827);
    init_extended_color(CRColor::GRAY, 600, 600, 600);
    init_extended_color(CRColor::DARK_GRAY, 500, 500, 500);
    init_extended_color(CRColor::DARKER_GRAY, 400, 400, 400);
    init_extended_color(CRColor::BEIGE, 931, 510, 933);
    init_extended_color(CRColor::TAN, 931, 510, 933);
    init_extended_color(CRColor::BROWN, 0, 0, 0);
    init_extended_color(CRColor::DARK_BROWN, 0, 0, 0);
    init_extended_color(CRColor::AZURE, 0, 498, 1000);
    init_extended_color(CRColor::BLUEBERRY, 271, 439, 902);
    
    
    // Initialize color pairs as ncurses works directly with pairs.
    // TODO: Same fallback implementation as with init_extended_colors.

    //      Black background
    init_extended_pair(CRColorPair::WHITE_ON_BLACK, CRColor::WHITE, CRColor::BLACK);
    init_extended_pair(CRColorPair::RED_ON_BLACK, CRColor::RED, CRColor::BLACK);
    init_extended_pair(CRColorPair::ORANGE_ON_BLACK, CRColor::ORANGE, CRColor::BLACK);
    init_extended_pair(CRColorPair::YELLOW_ON_BLACK, CRColor::YELLOW, CRColor::BLACK);
    init_extended_pair(CRColorPair::GREEN_ON_BLACK, CRColor::GREEN, CRColor::BLACK);
    init_extended_pair(CRColorPair::BLUE_ON_BLACK, CRColor::BLUE, CRColor::BLACK);
    init_extended_pair(CRColorPair::INDIGO_ON_BLACK, CRColor::INDIGO, CRColor::BLACK);
    init_extended_pair(CRColorPair::VIOLET_ON_BLACK, CRColor::VIOLET, CRColor::BLACK);
    init_extended_pair(CRColorPair::LIGHTER_GRAY_ON_BLACK, CRColor::LIGHTER_GRAY, CRColor::BLACK);
    init_extended_pair(CRColorPair::LIGHT_GRAY_ON_BLACK, CRColor::LIGHT_GRAY, CRColor::BLACK);
    init_extended_pair(CRColorPair::GRAY_ON_BLACK, CRColor::GRAY, CRColor::BLACK);
    init_extended_pair(CRColorPair::DARK_GRAY_ON_BLACK, CRColor::DARK_GRAY, CRColor::BLACK);
    init_extended_pair(CRColorPair::DARKER_GRAY_ON_BLACK, CRColor::DARKER_GRAY, CRColor::BLACK);
    init_extended_pair(CRColorPair::BEIGE_ON_BLACK, CRColor::BEIGE, CRColor::BLACK);
    init_extended_pair(CRColorPair::TAN_ON_BLACK, CRColor::TAN, CRColor::BLACK);
    init_extended_pair(CRColorPair::BROWN_ON_BLACK, CRColor::BROWN, CRColor::BLACK);
    init_extended_pair(CRColorPair::DARK_BROWN_ON_BLACK, CRColor::DARK_BROWN, CRColor::BLACK);
    init_extended_pair(CRColorPair::AZURE_ON_BLACK, CRColor::AZURE, CRColor::BLACK);
    init_extended_pair(CRColorPair::BLUEBERRY_ON_BLACK, CRColor::BLUEBERRY, CRColor::BLACK);

    //      Blue backgrounds for, e.g., water effects
    init_extended_pair(CRColorPair::WHITE_ON_BLUEBERRY, CRColor::WHITE, CRColor::BLUEBERRY);
    init_extended_pair(CRColorPair::BLACK_ON_BLUEBERRY, CRColor::BLACK, CRColor::BLUEBERRY);
    init_extended_pair(CRColorPair::GRAY_ON_BLUEBERRY, CRColor::GRAY, CRColor::BLUEBERRY);
    init_extended_pair(CRColorPair::YELLOW_ON_BLUEBERRY, CRColor::YELLOW, CRColor::BLUEBERRY);

    init_extended_pair(CRColorPair::WHITE_ON_BLUE, CRColor::WHITE, CRColor::BLUE);
    init_extended_pair(CRColorPair::BLACK_ON_BLUE, CRColor::BLACK, CRColor::BLUE);
    init_extended_pair(CRColorPair::GRAY_ON_BLUE, CRColor::GRAY, CRColor::BLUE);
    init_extended_pair(CRColorPair::YELLOW_ON_BLUE, CRColor::YELLOW, CRColor::BLUE);

    //      Red background 
    init_extended_pair(CRColorPair::WHITE_ON_RED, CRColor::WHITE, CRColor::RED);
    init_extended_pair(CRColorPair::ORANGE_ON_RED, CRColor::ORANGE, CRColor::RED);
    init_extended_pair(CRColorPair::YELLOW_ON_RED, CRColor::YELLOW, CRColor::RED);
    init_extended_pair(CRColorPair::GREEN_ON_RED, CRColor::GREEN, CRColor::RED);
    init_extended_pair(CRColorPair::BLUE_ON_RED, CRColor::BLUE, CRColor::RED);
    init_extended_pair(CRColorPair::INDIGO_ON_RED, CRColor::INDIGO, CRColor::RED);
    init_extended_pair(CRColorPair::VIOLET_ON_RED, CRColor::VIOLET, CRColor::RED);
    init_extended_pair(CRColorPair::BLACK_ON_RED, CRColor::BLACK, CRColor::RED);

    bkgd(COLOR_PAIR(default_color_pair));
    return CRResultCode::SUCCESS;
}


void cr_end_color()
{
    // Restore default color settings.
    // This only works if you don't evict ncurses' default color values!
    attrset(COLOR_PAIR(0));
    bkgd(COLOR_PAIR(0));
}

// This function is ugly, but I'm going with the first thing that comes to mind for now
CRColorPair cr_color_pair_from_colors(CRColor fg, CRColor bg)
{
    switch (bg)
    {
        case CRColor::BLACK:
        {
            switch (fg)
            {
                case CRColor::WHITE:
                    return CRColorPair::WHITE_ON_BLACK;
                case CRColor::LIGHTER_GRAY:
                    return CRColorPair::LIGHTER_GRAY_ON_BLACK;
                case CRColor::LIGHT_GRAY:
                    return CRColorPair::LIGHT_GRAY_ON_BLACK;
                case CRColor::GRAY:
                    return CRColorPair::GRAY_ON_BLACK;
                case CRColor::DARK_GRAY:
                    return CRColorPair::DARK_GRAY_ON_BLACK;
                case CRColor::DARKER_GRAY:
                    return CRColorPair::DARKER_GRAY_ON_BLACK;
                case CRColor::RED:
                    return CRColorPair::RED_ON_BLACK;
                case CRColor::ORANGE:
                    return CRColorPair::ORANGE_ON_BLACK;
                case CRColor::YELLOW:
                    return CRColorPair::YELLOW_ON_BLACK;
                case CRColor::GREEN:
                    return CRColorPair::GREEN_ON_BLACK;
                case CRColor::BLUEBERRY:
                    return CRColorPair::BLUEBERRY_ON_BLACK;
                case CRColor::BLUE:
                    return CRColorPair::BLUE_ON_BLACK;
                case CRColor::AZURE:
                    return CRColorPair::AZURE_ON_BLACK;
                case CRColor::INDIGO:
                    return CRColorPair::INDIGO_ON_BLACK;
                case CRColor::VIOLET:
                    return CRColorPair::VIOLET_ON_BLACK;
                case CRColor::BEIGE:
                    return CRColorPair::BEIGE_ON_BLACK;
                case CRColor::TAN:
                    return CRColorPair::TAN_ON_BLACK;
                case CRColor::BROWN:
                    return CRColorPair::BROWN_ON_BLACK;
                case CRColor::DARK_BROWN:
                    return CRColorPair::DARK_BROWN_ON_BLACK;
                default:
                    CR_ERROR("No color pair found with bg = black");
                    return (CRColorPair)0;
            }
        }
        case CRColor::BLUEBERRY:
        {
            switch (fg)
            {
                case CRColor::WHITE:
                    return CRColorPair::WHITE_ON_BLUEBERRY;
                case CRColor::BLACK:
                    return CRColorPair::BLACK_ON_BLUEBERRY;
                case CRColor::GRAY:
                    return CRColorPair::GRAY_ON_BLUEBERRY;
                case CRColor::YELLOW:
                    return CRColorPair::YELLOW_ON_BLUEBERRY;
                default:
                    CR_ERROR("No color pair found with bg = blueberry");
                    return (CRColorPair)0;
            }
        }
        case CRColor::BLUE:
        {
            switch (fg)
            {
                case CRColor::WHITE:
                    return CRColorPair::WHITE_ON_BLUE;
                case CRColor::BLACK:
                    return CRColorPair::BLACK_ON_BLUE;
                case CRColor::GRAY:
                    return CRColorPair::GRAY_ON_BLUE;
                case CRColor::YELLOW:
                    return CRColorPair::YELLOW_ON_BLUE;
                default:
                    CR_ERROR("No color pair found with bg = blue");
                    return (CRColorPair)0;
            }
        }
    }
}