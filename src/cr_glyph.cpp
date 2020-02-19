#include "cr_common.h"
#include "cr_glyph.h"
#include "cr_color.h"
#include "ecs/ecs_component.h"

CRGlyph make_tile_glyph(TileType tile)
{
    CRGlyph result = {};
    switch (tile)
    {
        case TileType::Empty:
        {
            result.sigil = '.';

            result.default_bg = default_bg;
            result.default_fg = default_fg;
            result.default_color_pair = default_color_pair;

            result.bg = result.default_bg;
            result.fg = result.default_fg;
            result.color_pair = result.default_color_pair;
        }; break;
        case TileType::Wall:
        {
            result.sigil = '#';

            result.default_bg = default_bg;
            result.default_fg = default_fg;
            result.default_color_pair = default_color_pair;

            result.bg = result.default_bg;
            result.fg = result.default_fg;
            result.color_pair = result.default_color_pair;
        }; break;
    }

    return result;
}

CRGlyph make_monster_glyph(MonsterType type)
{
    CRGlyph result = {};
    switch (type)
    {
        case MonsterType::Player:
        {
            result.sigil = '@';
            
            result.default_bg = default_bg;
            result.default_fg = CRColor::BLUEBERRY;
            result.default_color_pair = cr_color_pair_from_colors(CRColor::BLUEBERRY, default_bg);
            
            result.bg = result.default_bg;
            result.fg = result.default_fg;
            result.color_pair = result.default_color_pair;
        }; break;
    }

    return result;
}