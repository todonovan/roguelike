#pragma once

#include "../cr_common.h"
#include "ecs_component.h"

typedef unsigned long long ulonger;
#define Entity ulonger

#define MAX_ENTITIES 2000

struct ECSWorld
{
    Entity *entities;
    bool *is_free;
    Position *positions;
    Velocity *velocities;
    Renderable *renderables;
};

Entity ecs_create_entity(ECSWorld *world);
void ecs_kill_entity(ECSWorld *world, Entity entity);
void ecs_init_world(ECSWorld *world);
void ecs_free_world(ECSWorld *world);