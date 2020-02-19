#include "ecs_world.fwd.h"
#include "ecs_world.h"
#include "ecs_component.fwd.h"
#include "ecs_component.h"
#include "../cr_glyph.h"

Entity ecs_create_entity(ECSWorld *world)
{
    for (int i = 0; i < MAX_ENTITIES; i++)
    {
        if (world->is_free[i])
        {
            world->is_free[i] = false;
            world->entities[i] = COMP_NONE;
            world->positions[i] = {};
            world->velocities[i] = {};
            world->renderables[i] = {};
            world->monsters[i] = {};

            return i;
        }
    }

    CR_ERROR("Warning -- not enough space for entity!");
    return -1;
}

void kill_entity(ECSWorld *world, Entity entity)
{
    world->entities[entity] = 0;
    world->is_free[entity] = true;
}

ECSWorld * new_world()
{
    ECSWorld *world = (ECSWorld *)malloc(sizeof(ECSWorld));
    
    world->entities = (Entity *)malloc(MAX_ENTITIES * sizeof(Entity));
    world->is_free = (bool *)malloc(MAX_ENTITIES * sizeof(bool));
    world->positions = (Position *)malloc(MAX_ENTITIES * sizeof(Position));
    world->velocities = (Velocity *)malloc(MAX_ENTITIES * sizeof(Velocity));
    world->renderables = (Renderable *)malloc(MAX_ENTITIES * sizeof(Renderable));
    world->monsters = (Monster *)malloc(MAX_ENTITIES * sizeof(Monster));

    for (int i = 0; i < MAX_ENTITIES; i++)
    {
        world->entities[i] = COMP_NONE;
        world->is_free[i] = true;
        world->positions[i] = {};
        world->velocities[i] = {};
        world->renderables[i] = {};
        world->monsters[i] = {};
    }

    return world;
}

void kill_world(ECSWorld *world)
{
    free(world->entities);
    free(world->positions);
    free(world->velocities);
    free(world->renderables);
    free(world->monsters);

    free(world);
}