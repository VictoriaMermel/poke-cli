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

#ifdef NT
#include <windows.h>
#else
#include <unistd.h>
#endif

struct pokemon_state player_pokemon1;
struct pokemon_state player_pokemon2;
struct pokemon_state player_pokemon3;
struct pokemon_state player_pokemon4;
struct pokemon_state player_pokemon5;
struct pokemon_state player_pokemon6;
struct pokemon_state opponent_pokemon1;
struct pokemon_state opponent_pokemon2;
struct pokemon_state opponent_pokemon3;
struct pokemon_state opponent_pokemon4;
struct pokemon_state opponent_pokemon5;
struct pokemon_state opponent_pokemon6;


struct battle_state initialize(pokemon* player, pokemon* opponent) {

    struct battle_state state;
    state.player_pokemon1 = &player_pokemon1;
    state.player_pokemon1 = &player_pokemon2;
    state.player_pokemon1 = &player_pokemon3;
    state.player_pokemon1 = &player_pokemon4;
    state.player_pokemon1 = &player_pokemon5;
    state.player_pokemon1 = &player_pokemon6;
    state.opponent_pokemon1 = &opponent_pokemon1;
    state.opponent_pokemon2 = &opponent_pokemon2;
    state.opponent_pokemon2 = &opponent_pokemon3;
    state.opponent_pokemon2 = &opponent_pokemon4;
    state.opponent_pokemon2 = &opponent_pokemon5;
    state.opponent_pokemon2 = &opponent_pokemon6;
    state.player_pokemon1->pokemon = player;
    state.opponent_pokemon1->pokemon = opponent;

    state.player_pokemon1->health = player->stats->HP;
    state.opponent_pokemon1->health = opponent->stats->HP;

    return state;
}

int make_chosen_move(int selection, pokemon * pokemon, struct battle_state* state, bool player) {

    void *movevoid;
    move *move;

    switch(selection) {
        case 1 :
            move = pokemon->move1;
            break;
        case 2 :
            move = pokemon->move2;
            break;
        case 3 :
            move= pokemon->move3;
            break;
        case 4 :
            move= pokemon->move4;
            break;
        default:
            return 1;
    }
    movevoid = move->func;
    void (*movefunc)(struct battle_state*, struct move*, bool) = (void (*)(struct battle_state*, struct move*, bool))movevoid;
    (movefunc)(state, move, player);

    printf("%s used %s\n\n", pokemon->nickname, move->name);
    sleep(2);
    print_effectiveness(pokemon);
    print_crit();
    printf("\n%s: %d\n", state->player_pokemon1->pokemon->nickname, state->player_pokemon1->health);
    printf("%s: %d\n\n", state->opponent_pokemon1->pokemon->nickname, state->opponent_pokemon1->health);

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

    int command;

    species** all_pokemon = getDex();
    move* all_moves = getMoves();

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
    printf("\n%s: %d\n", state.player_pokemon1->pokemon->nickname, state.player_pokemon1->health);
    printf("%s: %d\n\n", state.opponent_pokemon1->pokemon->nickname, state.opponent_pokemon1->health);

    for(;;) {
        printf("%s (1)\n", state.player_pokemon1->pokemon->move1->name);
        printf("%s (2)\n", state.player_pokemon1->pokemon->move2->name);
        printf("%s (3)\n", state.player_pokemon1->pokemon->move3->name);
        printf("%s (4)\n", state.player_pokemon1->pokemon->move4->name);
        printf(">> ");
        scanf("%d",&command);
        if(state.player_pokemon1->pokemon->stats->Speed >= state.opponent_pokemon1->pokemon->stats->Speed) {
            make_chosen_move(command, state.player_pokemon1->pokemon, &state, true);
            make_chosen_move(1, state.opponent_pokemon1->pokemon, &state, false);
        }
        else {
            make_chosen_move(1, state.opponent_pokemon1->pokemon, &state, false);
            make_chosen_move(command, state.player_pokemon1->pokemon, &state, true);
        }
        if(state.player_pokemon1->health <= 0) {
            printf("%s fainted", state.player_pokemon1->pokemon->nickname);
            break;
        }
        else if(state.opponent_pokemon1->health <= 0) {
            printf("%s fainted", state.opponent_pokemon1->pokemon->nickname);
            break;
        }
    }

    free(all_pokemon);
    free(all_moves);
}
