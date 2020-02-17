#include "cr_common.h"
#include "map.h"

inline size_t point_to_index(int x, int y)
{
    return (size_t)(y * x + x);
}

CRResultCode init_map(Map *map, int h, int w)
{
    map->height = h;
    map->width = w;
    map = (Map *)realloc(map, (map->width * map->height * sizeof(Tile)));

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (i == 0 || i == w - 1 || j == 1 || j == h - 1)
            {
                map->tiles[point_to_index(i, j)].type = TileType::Wall;
                map->tiles[point_to_index(i, j)].glyph = 
            }
        }
    }
}