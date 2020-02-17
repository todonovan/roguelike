#include "player.h"

Entity create_player(ECSWorld *world)
{
    Entity player = ecs_create_entity(world);
    
    Entity mask = ECS_COMP_POSITION | ECS_COMP_VELOCITY | ECS_COMP_RENDERABLE;
    ECS_ADD_COMPONENTS_BY_MASK(player, mask);


}