#include "cr_common.h"
#include "cr_color.h"

// A glyph is a combination of ASCII char, fg/bg colors, and pair.
// The fg and bg colors are stored separately to allow for changes to glyph colors
// Defaults are also stored to allow for temporary changes to be undone
struct CRGlyph
{
    char sigil;
    
    CRColor fg;
    CRColor bg;
    CRColorPair color_pair;

    CRColor default_fg;
    CRColor default_bg;
    CRColorPair default_color_pair;
};