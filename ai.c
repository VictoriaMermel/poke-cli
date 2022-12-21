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
#include "moves.c"
#include "damage.h"

void ai_faint(struct battle_state* state) {
    state->opponent_pokemon1 = state->opponent_pokemon2;
    state->opponent_pokemon2 = state->opponent_pokemon3;
    state->opponent_pokemon3 = state->opponent_pokemon4;
    state->opponent_pokemon4 = state->opponent_pokemon5;
    state->opponent_pokemon5 = state->opponent_pokemon6;
    state->opponent_pokemon6 = 0;
}

int move_selection(pokemon* pokemon, int skill) {
    int i = 4; // number_of_moves;
    if(pokemon->move4 == NULL) i--;
    if(pokemon->move3 == NULL) i--;
    if(pokemon->move2 == NULL) i--;

    return random_num(1, i);
}
