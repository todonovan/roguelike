#pragma once

#include "cr_common.h"
#include "ecs/ecs_world.fwd.h"

Entity create_player(ECSWorld *world);
void kill_player(ECSWorld *world, Entity player);