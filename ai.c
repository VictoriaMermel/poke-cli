/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "ai.h"
#include "pokemon.h"
#include "moves.h"
#include "damage.h"
#include <stdio.h>

void ai_faint(struct battle_state* state) {
    state->opponent_pokemon1 = state->opponent_pokemon2;
    state->opponent_pokemon2 = state->opponent_pokemon3;
    state->opponent_pokemon3 = state->opponent_pokemon4;
    state->opponent_pokemon4 = state->opponent_pokemon5;
    state->opponent_pokemon5 = state->opponent_pokemon6;
    state->opponent_pokemon6 = 0;

    printf("Opponent sent out %s\n", state->opponent_pokemon1->pokemon->nickname);

    state->opponent_pokemon1->atk_stage = 0;
    state->opponent_pokemon1->def_stage = 0;
    state->opponent_pokemon1->spa_stage = 0;
    state->opponent_pokemon1->spe_stage = 0;
    state->opponent_pokemon1->spd_stage = 0;
}

int move_selection(pokemon* pokemon, int skill) {
    int i = 4; // number_of_moves;
    if(pokemon->move4 == 0) i--;
    if(pokemon->move3 == 0) i--;
    if(pokemon->move2 == 0) i--;

    return random_num(1, i);
}
