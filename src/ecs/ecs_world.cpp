#include "ecs_world.h"
#include "ecs_component.h"

Entity create_entity(ECSWorld *world)
{
    for (Entity i = 0; i < MAX_ENTITIES; i++)
    {
        if (world->entities[i] == 0) return i;
    }

    CR_ERROR("Warning -- not enough space for entity!");
    return -1;
}

void init_world(ECSWorld *world)
{
    for (int i = 0; i < MAX_ENTITIES; i++)
    {
        world->entities[i] = COMP_NONE;
        world->positions[i] = {};
        world->velocities[i] = {};
        world->renderables[i] = {};
    }
}