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


void make_generic_move(struct battle_state* state, struct move* move, bool player) {

    pokemon* attacker;
    pokemon* defender;
    short* health;
    float damage;
    unsigned short atk;
    unsigned short def;

    if(player) {
        attacker = state->player_pokemon1->pokemon;
        defender = state->opponent_pokemon1->pokemon;
        health = &state->opponent_pokemon1->health;
    }
    else {
        attacker = state->opponent_pokemon1->pokemon;
        defender = state->player_pokemon1->pokemon;
        health = &state->player_pokemon1->health;
    }

    mon_type pokemon_types[2] = {attacker->species->type1, attacker->species->type2};
    mon_type def_type[2] = {defender->species->type1, defender->species->type2};
    if(move->category == PHYSICAL) {
        atk = attacker->stats->Attack;
        def = defender->stats->Defense;
    }
    else {
        atk = attacker->stats->Sp_Atk;
        def = defender->stats->Sp_Def;
    }

    damage = damageCalc(attacker->level, move->Power, atk, defender->stats->Defense, false, move->type,
                        pokemon_types, def_type);

    *health = *health - (int)damage;
}

void damage_dealing(struct battle_state* state, move* tackle, bool player) {
    make_generic_move(state, tackle, player);
}

struct move tackle = { "Tackle", &damage_dealing, NORMAL,PHYSICAL,53,40,100,true,true,false,false,true,0 };
struct move pound = { "Pound", &damage_dealing, NORMAL,PHYSICAL,35,40,100,true,true,false,false,true,0 };

move* getMoves(void) {
    move* all_moves = malloc(sizeof(move)*201);
    all_moves[TACKLE] = tackle;
    all_moves[POUND] = pound;

    return all_moves;
}
