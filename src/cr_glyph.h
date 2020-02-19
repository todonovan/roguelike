#pragma once

#include "ecs/ecs_component.fwd.h"
#include "cr_common.h"
#include "cr_color.h"
#include "map.fwd.h"

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

CRGlyph make_tile_glyph(TileType tile);
CRGlyph make_monster_glyph(MonsterType type);
void set_glyph_color_pair(CRGlyph *glyph);
void restore_color_defaults(CRGlyph *glyph);

// **TO DO** -- load these automatically from file 