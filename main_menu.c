/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "frontier.h"
#include "pokemon.h"
#include "moves.h"
#include "ability.h"


extern species bulbasaur;
extern species squirtle;

bool battle_mode_menu() {

    char input[8];
prompt:
    printf("(1) Battle Factory   ('!' for rules)\n");
    printf("\n>> ");
    scanf("%s", input);
    if (strcmp(input, "1") == 0) {
        factory_main();
        return true;
    }
    else if (strcmp(input, "!") == 0) { printf("Battle With Rental Pokemon\n"); goto prompt; }
    else if (strcmp(input, "q") == 0) return true;
    else {
        printf("Error: not a valid input\n");
        goto prompt;
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

    state.player_pokemon1->health = player->HP;
    state.opponent_pokemon1->health = opponent->HP;
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

    pokemon bulba = {
    .nickname = "Bulba",
    .level = 50,
    .player = true,
    .ability = OVERGROW,
    .HP = 105,
    .Attack = 48,
    .Defense = 48,
    .Sp_Atk = 63,
    .Sp_Def = 63,
    .Speed = 45,
    .move1 = &tackle,
    .move2 = &growl,
    #ifdef DEBUG
    .move3 = &dbg,
    #endif
};
    bulba.species = &bulbasaur;

    pokemon turters = {
    .nickname = "Turters",
    .level = 50,
    .player = false,
    .HP = 104,
    .Attack = 47,
    .Defense = 63,
    .Sp_Atk = 49,
    .Sp_Def = 62,
    .Speed = 43,
    .ability = TORRENT,
    .move1 = &splash,
    .move2 = &tail_whip,
};
    turters.species = &squirtle;

    struct battle_state state = initialize(&bulba, &turters);

    battle_main(&state);
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

    char input[8];
    bool back = true;
    while (back) {
        printf("(1) Demo\n");
        printf("(2) Battle Mode\n");
        printf("\n Type 'quit' to exit\n");
        printf("\n>> ");
        scanf("%s", input);
        if(strcmp(input, "1") == 0) {
            demo();
            back = false;
        }
        else if (strcmp(input, "2") == 0) {
            back = battle_mode_menu();
        }
        else if (strcmp(input, "quit") == 0) {
            return 0;
        }
        else {
            printf("Error: not a valid input");
        }
    }
}
