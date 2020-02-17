#include "ecs_world.h"
#include "ecs_component.h"

Entity ecs_create_entity(ECSWorld *world)
{
    for (int i = 0; i < MAX_ENTITIES; i++)
    {
        if (world->is_free[i])
        {
            world->is_free[i] = false;
            world->entities[i] = 0;
            world->positions[i] = {};
            world->velocities[i] = {};
            world->renderables[i] = {};

            return i;
        }
    }

    CR_ERROR("Warning -- not enough space for entity!");
    return -1;
}

inline void ecs_kill_entity(ECSWorld *world, Entity entity)
{
    world->entities[entity] = 0;
    world->is_free[entity] = true;
}

void ecs_init_world(ECSWorld *world)
{
    world->entities = (Entity *)realloc(world->entities, MAX_ENTITIES * sizeof(Entity));
    world->is_free = (bool *)realloc(world->is_free, MAX_ENTITIES * sizeof(bool));
    world->positions = (Position *)realloc(world->positions, MAX_ENTITIES * sizeof(Position));
    world->velocities = (Velocity *)realloc(world->velocities, MAX_ENTITIES * sizeof(Velocity));
    world->renderables = (Renderable *)realloc(world->renderables, MAX_ENTITIES * sizeof(Renderable));

    for (int i = 0; i < MAX_ENTITIES; i++)
    {
        world->entities[i] = ECS_COMP_NONE;
        world->is_free[i] = true;
        world->positions[i] = {};
        world->velocities[i] = {};
        world->renderables[i] = {};
    }
}

void ecs_free_world(ECSWorld *world)
{
    free(world->entities);
    free(world->is_free);
    free(world->positions);
    free(world->velocities);
    free(world->renderables);
}