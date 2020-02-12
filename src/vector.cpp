#include "roguelike.h"

vec_2 AddVectors(vec_2 V1, vec_2 V2)
{
    vec_2 Result;
    Result.X = V1.X + V2.X;
    Result.Y = V1.Y + V2.Y;

    return Result;
}

vec_2 ScaleVector(vec_2 V, float S)
{
    vec_2 Result;
    Result.X = V.X * S;
    Result.Y = V.Y * S;

    return Result;
}