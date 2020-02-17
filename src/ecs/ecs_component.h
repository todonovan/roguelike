#pragma once

#include "../cr_common.h"
#include "../cr_glyph.h"


// A component is represented as a bit mask.

#define ECS_COMP_NONE 0
#define ECS_COMP_POSITION (1 << 0)
#define ECS_COMP_VELOCITY (1 << 1)
#define ECS_COMP_RENDERABLE (1 << 2)

#define ECS_HAS_POSITION(entity) ((entity) & COMP_POSITION)
#define ECS_HAS_VELOCITY(entity) ((entity) & COMP_VELOCITY)
#define ECS_HAS_RENDERABLE(entity) ((entity) & COMP_RENDERABLE)

#define ECS_ADD_COMPONENTS_BY_MASK(entity, mask) (entity |= mask)

#define ECS_MK_POSITION(entity) ((entity) |= COMP_POSITION)
#define ECS_MK_VELOCITY(entity) ((entity) |= COMP_VELOCITY)
#define ECS_MK_RENDERABLE(entity) ((entity) |= COMP_RENDERABLE)

#define ECS_CLEAR_COMPONENTS_BY_MASK(entity, mask) ((entity) &= ~(mask))

#define ECS_CLR_POSITION(entity) ((entity) &= ~(COMP_POSITION))
#define ECS_CLR_VELOCITY(entity) ((entity) &= ~(COMP_VELOCITY))
#define ECS_CLR_RENDERABLE(entity) ((entity) &= ~(COMP_RENDERABLE))

struct Position
{
    int x;
    int y;
};

struct Velocity
{
    int dx;
    int dy;
};

struct Renderable
{
    CRGlyph glyph;
};