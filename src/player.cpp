#include "player.h"
#include "cr_glyph.h"
#include "ecs/ecs_world.h"
#include "ecs/ecs_component.fwd.h"
#include "ecs/ecs_component.h"

Entity create_player(ECSWorld *world)
{
    Entity player = create_entity(world);
    player |= COMP_POSITION | COMP_VELOCITY | COMP_RENDERABLE;

    Position *player_pos = get_position(world, player);
    player_pos->x = 10.0;
    player_pos->y = 10.0;

    Velocity *player_velocity = get_velocity(world, player);
    player_velocity->dx = 1.0;
    player_velocity->dy = 1.0;

    Renderable *player_renderable = get_renderable(world, player);
    player_renderable->glyph = make_monster_glyph(MonsterType::Player);

    Monster *monster = get_monster(world, player);
    monster->type = MonsterType::Player;
    monster->name = "Player";

    return player;
}

void kill_player(ECSWorld *world, Entity player)
{
    kill_entity(world, player);
}