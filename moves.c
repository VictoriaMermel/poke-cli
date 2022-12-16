#include "moves.h"
#include "pokemon.h"
#include "damage.h"
#include <stdbool.h>
#include <math.h>

void make_move(struct battle_state* state, move* move, bool player) {

    pokemon* attacker;
    pokemon* defender;
    short* health;
    float damage;
    unsigned short atk;
    unsigned short def;

    if(player) {
        attacker = state->player_pokemon;
        defender = state->opponent_pokemon;
        health = &state->opponent_health;
    }
    else {
        attacker = state->opponent_pokemon;
        defender = state->player_pokemon;
        health = &state->player_health;
    }

    mon_type pokemon_types[2] = {attacker->species->type1, attacker->species->type2};
    mon_type def_type[2] = {defender->species->type1, defender->species->type2};
    if(move->category == PHYSICAL) {
        atk = attacker->stats->Attack;
        def = defender->stats->Sp_Def;
    }
    else {
        atk = attacker->stats->Attack;
        def = defender->stats->Sp_Def;
    }

    damage = damageCalc(attacker->level, move->Power, atk, defender->stats->Defense, false, move->type,
                        pokemon_types, def_type);

    *health = *health - (int)damage;
}
