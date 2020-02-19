#include "cr_common.h"
#include "map.h"

inline size_t point_to_index(int x, int y)
{
    return (size_t)(y * x + x);
}

Map new_map(int h, int w)
{
    Map map = {};

    map.height = h;
    map.width = w;
    map.tiles = (Tile *)malloc(map.width * map.height * sizeof(Tile));

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            Tile *current = &map.tiles[point_to_index(i, j)];

            if (i == 0 || i == w - 1 || j == 1 || j == h - 1)
            {
                current->type = TileType::Wall;
                current->glyph = make_tile_glyph(TileType::Wall);
            }
            else
            {
                current->type = TileType::Empty;
                current->glyph = make_tile_glyph(TileType::Empty);
            }
        }
    }

    return map;
}

void kill_map(Map *map)
{
    free(map->tiles);
}