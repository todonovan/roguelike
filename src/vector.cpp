#include "roguelike.h"

struct vec_2
{
    int x;
    int y;
};

vec_2 add_vectors(vec_2 v1, vec_2 v2)
{
    vec_2 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;

    return result;
}

vec_2 scale_vector(vec_2 v, float s)
{
    vec_2 result;
    result.x = v.x * s;
    result.y = v.y * s;

    return result;
}