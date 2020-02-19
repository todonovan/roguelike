#include "ecs_component.fwd.h"

#include "ecs_component.h"
#include "ecs_world.h"
#include "../cr_glyph.h"

// Returns false if this entity either isn't allocated or doesn't have position
bool get_position_safe(ECSWorld *world, Entity entity, Position **result)
{
    if (world->is_free[entity] || !(HAS_POSITION(entity)))
    {
        return false;
    }

    *result = &world->positions[entity];
    return true;
}

// No safety here, in cases where we know for sure the entity has position
Position * get_position(ECSWorld *world, Entity entity)
{
    return &world->positions[entity];
}

// Returns false if this entity either isn't allocated or doesn't have velocity
bool get_velocity_safe(ECSWorld *world, Entity entity, Velocity **result)
{
    if (world->is_free[entity] || !(HAS_VELOCITY(entity)))
    {
        return false;
    }

    *result = &world->velocities[entity];
    return true;
}

// No safety here, in cases where we know for sure the entity has velocity
Velocity * get_velocity(ECSWorld *world, Entity entity)
{
    return &world->velocities[entity];
}

// Returns false if this entity either isn't allocated or doesn't have renderable
bool get_renderable_safe(ECSWorld *world, Entity entity, Renderable **result)
{
    if (world->is_free[entity] || !(HAS_RENDERABLE(entity)))
    {
        return false;
    }

    *result = &world->renderables[entity];
    return true;
}

// No safety here, in cases where we know for sure the entity has position
Renderable * get_renderable(ECSWorld *world, Entity entity)
{
    return &world->renderables[entity];
}

bool get_monster_safe(ECSWorld *world, Entity entity, Monster **result)
{
    if (world->is_free[entity] || !(HAS_MONSTER(entity)))
    {
        return false;
    }

    *result = &world->monsters[entity];
}

Monster * get_monster(ECSWorld *world, Entity entity)
{
    return &world->monsters[entity];
}