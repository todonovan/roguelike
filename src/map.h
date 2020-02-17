#pragma once

#include "cr_common.h"
#include "cr_glyph.h"

typedef enum
{
    Empty,
    Wall,
} TileType;

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

CRResultCode init_map(Map *map);