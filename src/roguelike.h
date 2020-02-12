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

struct GamePermanentMemory
{
    memory_segment PermMemSegment;
    game_state *GameState;
    loaded_resource_memory *Resources;
    memory_segment ResourceMemorySegment;
    memory_segment SceneMemorySegment;        
    memory_segment LaserMemorySegment;
    memory_segment AsteroidMemorySegment;
};

#define PERM_STORAGE_STRUCT_SIZE ((5 * (sizeof(memory_segment))) + (sizeof(game_state)) + (sizeof(loaded_resource_memory)))

#define PushArrayToMemorySegment(Segment, Count, type) (type *)AssignToMemorySegment_(Segment, (Count)*sizeof(type))
#define PushToMemorySegment(Segment, type) (type *)AssignToMemorySegment_(Segment, sizeof(type))
void * AssignToMemorySegment_(memory_segment *Segment, uint32_t Size);