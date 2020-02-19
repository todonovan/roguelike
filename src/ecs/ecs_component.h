#pragma once

#include "ecs_component.fwd.h"
#include "ecs_world.fwd.h"
#include "../cr_glyph.h"

#include "../cr_common.h"
#include "../cr_color.h"


// A component is represented as a bit mask.

#define COMP_NONE 0
#define COMP_POSITION (1 << 0)
#define COMP_VELOCITY (1 << 1)
#define COMP_RENDERABLE (1 << 2)
#define COMP_MONSTER (1 << 3)

#define HAS_POSITION(entity) ((entity) & COMP_POSITION)
#define HAS_VELOCITY(entity) ((entity) & COMP_VELOCITY)
#define HAS_RENDERABLE(entity) ((entity) & COMP_RENDERABLE)
#define HAS_MONSTER(entity) ((entity) & COMP_MONSTER)

struct Position
{
    double x;
    double y;
};

struct Velocity
{
    double dx;
    double dy;
};

struct Renderable
{
    CRGlyph glyph;
};

struct Monster
{
    MonsterType type;
    const char *name;    
};

Position * get_position(ECSWorld *world, Entity entity);
Velocity * get_velocity(ECSWorld *world, Entity entity);
Renderable * get_renderable(ECSWorld *world, Entity entity);
Monster * get_monster(ECSWorld *world, Entity entity);