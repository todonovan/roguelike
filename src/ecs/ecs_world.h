#pragma once

#include "ecs_world.fwd.h"
#include "ecs_component.fwd.h"
#include "../cr_glyph.h"

struct ECSWorld
{
    Entity *entities;
    bool *is_free;
    Position *positions;
    Velocity *velocities;
    Renderable *renderables;
    Monster *monsters;
};

Entity create_entity(ECSWorld *world);
void kill_entity(ECSWorld *world, Entity entity);
ECSWorld * new_world();
void kill_world(ECSWorld *world);
