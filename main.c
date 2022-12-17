/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "pokemon.h"
#include "dex.h"
#include "damage.h"
#include "types.h"
#include "moves.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


struct battle_state initialize(pokemon* player, pokemon* opponent) {

    struct battle_state state;
    state.player_pokemon = player;
    state.opponent_pokemon = opponent;

    state.player_stages = 0;
    state.opponent_stages = 0;
    state.player_health = player->stats->HP;
    state.opponent_health = opponent->stats->HP;

    return state;
}

int make_chosen_move(int selection, pokemon * pokemon, struct battle_state* state, bool player) {

    void *movevoid;
    switch(selection) {
        case 1 :
            movevoid = pokemon->move1->func;
            break;
        case 2 :
            movevoid = pokemon->move2->func;
            break;
        case 3 :
            movevoid = pokemon->move3->func;
            break;
        case 4 :
            movevoid = pokemon->move4->func;
            break;
        default:
            return 1;
    }
    void (*movefunc)(struct battle_state*, bool) = (void (*)(struct battle_state*, bool))movevoid;
    (movefunc)(state, player);
    return 0;
}

int main(int argc , char ** argv) {

    printf("\n");
    #ifndef SILENCE_DISCLAIMER
    printf("Welcome\n\n");
    printf("This program is free software: you can redistribute it and/or modify\n\
it under the terms of the GNU General Public License as published by\n\
the Free Software Foundation, either version 3 of the License, or\n\
(at your option) any later version.\n\n\
\
This program is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\n"
);
    #endif

//    char command[255];

    species** all_pokemon = getDex();
    move* all_moves = getMoves();
    void (*tackle)(struct battle_state*,bool) = (void (*)(struct battle_state*,bool))all_moves[TACKLE].func;

    struct stats bulba_stats = { 105, 48, 48, 63, 63, 45 };
    struct stats turters_stats = { 104, 47, 63, 49, 62, 43 };

    pokemon bulba = {
    .species = all_pokemon[0],
    .nickname = "Bulba",
    .level = 50,
    .stats = &bulba_stats,
    .move1 = &all_moves[TACKLE],
};

    pokemon turters = {
    .species = all_pokemon[8],
    .nickname = "Turters",
    .level = 50,
    .stats = &turters_stats,
    .move1 = &all_moves[TACKLE],
};

    struct battle_state state = initialize(&bulba, &turters);

    printf("bulba: %d\n", state.player_health);
    printf("%s\n\n", bulba.move1->name);
    printf("turters: %d\n", state.opponent_health);
    printf("%s\n", turters.move1->name);
    printf("\n");

    mon_type squirtleType[2];
    mon_type bulbaType[2];
    printf("damage: %f\n", damageCalc(50, 40, bulba_stats.Attack, turters_stats.Defense, false, NORMAL, bulbaType, squirtleType));

    make_chosen_move(1, &bulba, &state, true);
    print_effectiveness(&turters);

    printf("\n");
    printf("bulba: %d\n", state.player_health);
    printf("turters: %d\n", state.opponent_health);

//    for(;;) {
//        printf(">>");
//        scanf("%s",command);
//
//    }

    free(all_pokemon);
    free(all_moves);
}
