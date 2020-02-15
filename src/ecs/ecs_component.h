#pragma once

#include "../cr_common.h"
#include "../cr_glyph.h"


// A component is represented as a bit mask.

#define COMP_NONE 0
#define COMP_POSITION (1 << 0)
#define COMP_VELOCITY (1 << 1)
#define COMP_RENDERABLE (1 << 2)

#define HAS_POSITION(entity) ((entity) & COMP_POSITION)
#define HAS_VELOCITY(entity) ((entity) & COMP_VELOCITY)
#define HAS_RENDERABLE(entity) ((entity) & COMP_RENDERABLE)

#define ADD_COMPONENTS_BY_MASK(entity, mask) (entity |= mask)

#define MK_POSITION(entity) ((entity) |= COMP_POSITION)
#define MK_VELOCITY(entity) ((entity) |= COMP_VELOCITY)
#define MK_RENDERABLE(entity) ((entity) |= COMP_RENDERABLE)

#define CLEAR_COMPONENTS_BY_MASK(entity, mask) ((entity) &= ~(mask))

#define CLR_POSITION(entity) ((entity) &= ~(COMP_POSITION))
#define CLR_VELOCITY(entity) ((entity) &= ~(COMP_VELOCITY))
#define CLR_RENDERABLE(entity) ((entity) &= ~(COMP_RENDERABLE))

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