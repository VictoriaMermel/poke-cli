/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "moves.h"
#include "pokemon.h"
#include "damage.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void make_generic_move(struct battle_state* state, struct move_data* move, bool player) {

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

void tackle(struct battle_state* state, bool player) {
    struct move_data tackle = { NORMAL,PHYSICAL,53,40,100,true,true,false,false,true,0 };
    make_generic_move(state, &tackle, player);
}

move* getMoves(void) {
    move* all_moves = malloc(sizeof(move)*200);
    move tackle_str = { "tackle", &tackle };
    all_moves[TACKLE] = tackle_str;

    return all_moves;
}
