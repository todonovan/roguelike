#pragma once

#include "cr_common.h"

typedef enum
{
    Empty,
    Wall,
} TileType;

struct Tile
{
    TileType type;
    CRGlyph glyph;
};

struct Map
{
    Tile *tiles;
    int width;
    int height;
};

CRResultCode init_map(Map *map);