#pragma once

#include "../cr_common.h"
#include "ecs_component.h"

typedef unsigned long long ulonger;
#define Entity ulonger

#define MAX_ENTITIES 2000

struct ECSWorld
{
    Entity entities[MAX_ENTITIES];
    Position positions[MAX_ENTITIES];
    Velocity velocities[MAX_ENTITIES];
    Renderable renderables[MAX_ENTITIES];
};

Entity create_entity(ECSWorld *world);
void init_world(ECSWorld *world);