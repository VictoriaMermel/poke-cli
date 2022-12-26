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
#include "ai.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

bool player_whited_out(struct battle_state* state) {

    if(state->player_teamsize == 0) {
        return true;
    }
    else return false;
}

bool player_wins(struct battle_state* state) {

    if(state->opponent_teamsize == 0) {
        return true;
    }
    else return false;
}

void speed_order(struct battle_state* state, pokemon** order) {

    bool player_first;
    if(state->player_pokemon1->pokemon->stats->Speed > state->opponent_pokemon1->pokemon->stats->Speed) {
        order[0] = state->player_pokemon1->pokemon;
        order[1] = state->opponent_pokemon1->pokemon;
    }
    else {
        order[0] = state->opponent_pokemon1->pokemon;
        order[1] = state->player_pokemon1->pokemon;
    }
}

bool faint(pokemon* target) {

    if(target->status->health <= 0) {
        target->status->fainted = true;
        return true;
    }
    else return false;
}

void switch_out(struct battle_state* state) {

    int selection;
    bool fainted = false;
    struct pokemon_state* selected_pokemon;
    struct pokemon_state* placeholder;
    do {
        printf("%s (1)\n", state->player_pokemon2->pokemon->nickname);
        printf("%s (2)\n", state->player_pokemon3->pokemon->nickname);
        printf("%s (3)\n", state->player_pokemon4->pokemon->nickname);
        printf("%s (4)\n", state->player_pokemon5->pokemon->nickname);
        printf("%s (5)\n", state->player_pokemon6->pokemon->nickname);

        printf(">>");
        scanf("%d", &selection);

        placeholder = state->player_pokemon1;
        switch (selection) {
            case 1 :
                selected_pokemon = state->player_pokemon2;
            case 2 :
                selected_pokemon = state->player_pokemon3;
            case 3 :
                selected_pokemon = state->player_pokemon4;
            case 4 :
                selected_pokemon = state->player_pokemon5;
            case 5 :
                selected_pokemon = state->player_pokemon6;
        }
        if (selected_pokemon->fainted) {
            printf("FAINTED");
            fainted = true;
        }
        else {
            state->player_pokemon1 = selected_pokemon;
            selected_pokemon = placeholder;
        }
    } while (fainted);
    printf("Go %s!\n", state->player_pokemon1->pokemon->nickname);
    
}

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

int make_chosen_move(int selection, pokemon * pokemon, struct battle_state* state) {

    void *movevoid;
    move *move;
    int sel;  // Selection by either player or AI

    if(pokemon->player) {
        sel = selection;
    }
    else {
        sel = move_selection(pokemon, 0);
    }

    switch(sel) {
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

    printf("%s used %s\n\n", pokemon->nickname, move->name);
    (movefunc)(state, move, pokemon->player);
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
    pokemon* order[2];
    int i;

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
    .move1 = all_moves[TACKLE],
    .move2 = all_moves[VINE_WHIP],
    .move3 = all_moves[SWORDS_DANCE],
};

    pokemon turters = {
    .species = all_pokemon[8],
    .nickname = "Turters",
    .level = 50,
    .player = false,
    .stats = &turters_stats,
    .move1 = all_moves[TACKLE],
};

    struct battle_state state = initialize(&bulba, &turters);    // Temporary. For beta version this fills each team with pokemon
    printf("\n%s: %d\n", state.player_pokemon1->pokemon->nickname, state.player_pokemon1->health);
    printf("%s: %d\n\n", state.opponent_pokemon1->pokemon->nickname, state.opponent_pokemon1->health);

    for(;;) {    // Rounds

        printf("%s (1)\n%d\n", state.player_pokemon1->pokemon->move1->name,state.player_pokemon1->PP[1]);
        printf("%s (2)\n%d\n", state.player_pokemon1->pokemon->move2->name,state.player_pokemon1->PP[2]);
        printf("%s (3)\n%d\n", state.player_pokemon1->pokemon->move3->name,state.player_pokemon1->PP[3]);
        printf("%s (4)\n%d\n", state.player_pokemon1->pokemon->move4->name,state.player_pokemon1->PP[4]);
        printf(">> ");
        scanf("%d",&command);
        if(state.player_pokemon1->PP[command] == 0) {
            printf("PP depleted");
            break;
        }
        else {
            state.player_pokemon1->PP[command]--;
        }

        speed_order(&state, order);

        for(i = 0; i < SINGLES; i++) {                  // Each pokemon makes a move
            if(!faint(order[i])) {
                make_chosen_move(command, order[i], &state);
            }
            if(faint(state.player_pokemon1->pokemon)) {
                printf("%s fainted\n", state.player_pokemon1->pokemon->nickname);
                state.player_teamsize--;
                if(player_whited_out(&state)) {
                    printf("You whited out\n");
                    return 1;
                }
                else {
                    switch_out(&state);
                }
            }
            if(faint(state.opponent_pokemon1->pokemon)) {
                printf("%s fainted\n", state.opponent_pokemon1->pokemon->nickname);
                state.opponent_teamsize--;
                if(player_wins(&state)) {
                    printf("Victory\n");
                    return 0;
                }
                else {
                    ai_faint(&state);  // Opponent switched out
                }
            }
        }
    }
}
