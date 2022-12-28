/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "factory.h"
#include "pokemon.h"
#include "moves.h"
#include "dex.h"
#include "ability.h"

bool battle_mode_menu() {

    printf("(1) Battle Factory   ('!' for rules)\n");
    printf("\n>> ");
    int input;
    scanf("%d", &input);
    switch(input) {
        case 1 :
            factory_main();
        /* case '!' : */
        /*     printf("Battle With Rental Pokemon"); */
        /* case 'q' : */
        /*     return true; */
        default :
            return false;
    }
}

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
    state.player_pokemon2 = &player_pokemon2;
    state.player_pokemon3 = &player_pokemon3;
    state.player_pokemon4 = &player_pokemon4;
    state.player_pokemon5 = &player_pokemon5;
    state.player_pokemon6 = &player_pokemon6;
    state.opponent_pokemon1 = &opponent_pokemon1;
    state.opponent_pokemon2 = &opponent_pokemon2;
    state.opponent_pokemon3 = &opponent_pokemon3;
    state.opponent_pokemon4 = &opponent_pokemon4;
    state.opponent_pokemon5 = &opponent_pokemon5;
    state.opponent_pokemon6 = &opponent_pokemon6;
    state.player_pokemon1->pokemon = player;
    player->status = state.player_pokemon1;
    opponent->status = state.opponent_pokemon1;
    state.opponent_pokemon1->pokemon = opponent;

    state.player_pokemon1->health = player->stats->HP;
    state.opponent_pokemon1->health = opponent->stats->HP;
    state.player_pokemon1-> fainted = false;
    state.opponent_pokemon1 -> fainted = false;


    state.player_teamsize = 1;
    state.opponent_teamsize = 1;

    unsigned int PP[5];
    state.player_pokemon1->PP[1] = player->move1->PP;
    if(player->move2 > 0) state.player_pokemon1->PP[2] = player->move2->PP;
    if(player->move3 > 0) state.player_pokemon1->PP[3] = player->move3->PP;
    if(player->move4 > 0) state.player_pokemon1->PP[4] = player->move4->PP;
    state.opponent_pokemon1->PP[1] = opponent->move1->PP;
    if(opponent->move2 > 0) state.opponent_pokemon1->PP[2] = opponent->move2->PP;
    if(opponent->move3 > 0) state.opponent_pokemon1->PP[3] = opponent->move3->PP;
    if(opponent->move4 > 0) state.opponent_pokemon1->PP[4] = opponent->move4->PP;

    return state;
}

void demo() {

    species** all_pokemon = getDex();
    move** all_moves = getMoves();

    struct stats bulba_stats = { 105, 48, 48, 63, 63, 45 };
    struct stats turters_stats = { 104, 47, 63, 49, 62, 43 };

    pokemon bulba = {
    .species = all_pokemon[0],
    .nickname = "Bulba",
    .level = 50,
    .player = true,
    .stats = &bulba_stats,
    .ability = OVERGROW,
    .move1 = all_moves[TACKLE],
    .move2 = all_moves[GROWL],
};

    pokemon turters = {
    .species = all_pokemon[8],
    .nickname = "Turters",
    .level = 50,
    .player = false,
    .stats = &turters_stats,
    .ability = TORRENT,
    .move1 = all_moves[TACKLE],
    .move2 = all_moves[TAIL_WHIP],
};
    struct battle_state state = initialize(&bulba, &turters);

    battle_main(&state);

    free(all_moves);
}

int main(int argc, char** argv) {

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

    printf("(1) Demo\n");
    printf("(2) Battle Mode\n");
    printf("\n>> ");
    int input;
    bool back = true;
    scanf("%d", &input);
    while (back) {
        switch (input) {
            case 1 :
                demo();
                back = false;
            case 2 :
                back = battle_mode_menu();
        }
    }
}
