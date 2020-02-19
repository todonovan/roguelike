#pragma once

#include "cr_common.h"
#include "cr_glyph.h"
#include "map.fwd.h"

struct Tile
{
    TileType type;
    CRGlyph glyph;
    bool BlocksMovement;
    bool IsOccupied;
};

struct Map
{
    Tile *tiles;
    int width;
    int height;
};

Map new_map(int h, int w);
void kill_map(Map *map);