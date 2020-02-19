#pragma once

struct Vec2
{
    float X;
    float Y;
};

Vec2 add_vectors(Vec2 v1, Vec2 v2);
Vec2 scale_vector(Vec2 v, float s);

struct GameRect
{
    Vec2 top_left;
    Vec2 bot_right;
};
