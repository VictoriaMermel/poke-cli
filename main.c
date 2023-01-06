/* Sel Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "pokemon.h"
#include "damage.h"
#include "types.h"
#include "moves.h"
#include "ai.h"
#include "ability.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef NT
#include <windows.h>
#else
#include <unistd.h>
#endif

void healthbar(pokemon* pokemon, char** healthbar) {
    int outoftwenty = ((float)pokemon->status->health / (float)pokemon->HP) * 20;
    memset(*healthbar, '-', 20);
    if (pokemon->status->health > 0) {
    memset(*healthbar, '*', outoftwenty);
    }
}

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
    if(state->player_pokemon1->pokemon->Speed > state->opponent_pokemon1->pokemon->Speed) {
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

    int i;
    bool fainted = false;
    struct pokemon_state** selected_pokemon;
    struct pokemon_state* placeholder;
    do {
        if (state->player_teamsize>1) printf("%s (1)\n", state->player_pokemon2->pokemon->nickname);
        else return;
        if (state->player_teamsize>2) printf("%s (2)\n", state->player_pokemon3->pokemon->nickname);
        if (state->player_teamsize>3) printf("%s (3)\n", state->player_pokemon4->pokemon->nickname);
        if (state->player_teamsize>4) printf("%s (4)\n", state->player_pokemon5->pokemon->nickname);
        if (state->player_teamsize>5) printf("%s (5)\n", state->player_pokemon6->pokemon->nickname);

        printf("\n>> ");
        scanf("%d", &i);

        placeholder = state->player_pokemon1;
        switch (i) {
            case 1 :
                selected_pokemon = &state->player_pokemon2;
                break;
            case 2 :
                selected_pokemon = &state->player_pokemon3;
                break;
            case 3 :
                selected_pokemon = &state->player_pokemon4;
                break;
            case 4 :
                selected_pokemon = &state->player_pokemon5;
                break;
            case 5 :
                selected_pokemon = &state->player_pokemon6;
                break;
            default:
                fainted = true;
                continue;
        }
        if ((*selected_pokemon)->fainted) {
            printf("FAINTED\n");
            fainted = true;
        }
        else {
            state->player_pokemon1 = *selected_pokemon;
            *selected_pokemon = placeholder;
            fainted = false;
        }
    } while (fainted);
    printf("\nGo %s!\n\n", state->player_pokemon1->pokemon->nickname);
    sleep(1);

    state->player_pokemon1->atk_stage = 0;
    state->player_pokemon1->def_stage = 0;
    state->player_pokemon1->spa_stage = 0;
    state->player_pokemon1->spe_stage = 0;
    state->player_pokemon1->spd_stage = 0;

}


int make_chosen_move(int selection, pokemon * pokemon, struct battle_state* state, bool attack) {

    void *movevoid;
    move *move;
    int sel;  // Selection by either player or AI

    if(pokemon->player) {
        sel = selection;
        if(!attack) {
            return 0;
        }
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
    void (*movefunc)(struct battle_state*, const struct move*, bool) = (void (*)(struct battle_state*, const struct move*, bool))movevoid;

    printf("%s used %s\n\n", pokemon->nickname, move->name);
    (movefunc)(state, move, pokemon->player);

    return 0;
}

int battle_main(struct battle_state* state) {

    int sel;
    bool attack;
    bool sw;
    bool help;
    char command[8];
    pokemon* order[2];
    int i;

    state->player_pokemon1->atk_stage = 0;
    state->player_pokemon1->def_stage = 0;
    state->player_pokemon1->spa_stage = 0;
    state->player_pokemon1->spe_stage = 0;
    state->player_pokemon1->spd_stage = 0;

    state->opponent_pokemon1->atk_stage = 0;
    state->opponent_pokemon1->def_stage = 0;
    state->opponent_pokemon1->spa_stage = 0;
    state->opponent_pokemon1->spe_stage = 0;
    state->opponent_pokemon1->spd_stage = 0;


    char* health_bar = malloc(sizeof(char)*22);
    char* opp_bar = malloc(sizeof(char)*22);
    healthbar(state->player_pokemon1->pokemon, &health_bar);
    health_bar[20] = '\0';
    healthbar(state->opponent_pokemon1->pokemon, &opp_bar);
    opp_bar[20] = '\0';
    printf("\n%s: %d  [%s]\n", state->player_pokemon1->pokemon->nickname, state->player_pokemon1->health, health_bar);
    printf("%s:  [%s]\n\n", state->opponent_pokemon1->pokemon->nickname, opp_bar);

    for(;;) {    // Rounds
main_prompt:
        printf("What to do?\n\n>> ");
        scanf("%s",command);
        for (int i = 0; i<strlen(command); i++) {
            attack = strncmp(command, "attack", i+1) == 0;
            if (!attack) {
                break;
            }
        }
        for (int i = 0; i<strlen(command); i++) {
            sw = strncmp(command, "switch", i+1) == 0;
            if (!sw) break;
        }
        for (int i = 0; i<strlen(command); i++) {
            help = strncmp(command, "help", i+1) == 0;
            if (!help) {
                break;
            }
        }
        if (!sw && !attack && !help) {
            printf("Error: %s is not a valid command.\n", command);
            goto main_prompt;
        }
        if (help) {
            printf("\nCommands: \n\nattack\nswitch\n\n");
            goto main_prompt;
        }
        if (sw && state->player_teamsize == 1) {
            printf("Error: Only one pokemon\n\n");
            goto main_prompt;
        }

move_prompt:
        if (!sw) {
            printf("\n%s (1)\n%d\n", state->player_pokemon1->pokemon->move1->name,state->player_pokemon1->PP[1]);
            printf("%s (2)\n%d\n", state->player_pokemon1->pokemon->move2->name,state->player_pokemon1->PP[2]);
            printf("%s (3)\n%d\n", state->player_pokemon1->pokemon->move3->name,state->player_pokemon1->PP[3]);
            printf("%s (4)\n%d\n", state->player_pokemon1->pokemon->move4->name,state->player_pokemon1->PP[4]);
            printf("\n>> ");
            scanf("%d",&sel);
            if(state->player_pokemon1->PP[sel] == 0) {
                printf("PP depleted\n");
                goto move_prompt;
            }
            else {
                state->player_pokemon1->PP[sel]--;
            }
        }

        speed_order(state, order);
        if(sw) switch_out(state);
        for(i = 0; i < SINGLES; i++) {                  // Each pokemon makes a move
            if(!faint(order[i])) {
                make_chosen_move(sel, order[i], state, attack);
                healthbar(state->player_pokemon1->pokemon, &health_bar);
                healthbar(state->opponent_pokemon1->pokemon, &opp_bar);
                printf("\n%s: %d  [%s]\n", state->player_pokemon1->pokemon->nickname, state->player_pokemon1->health, health_bar);
                printf("%s:  [%s]\n\n", state->opponent_pokemon1->pokemon->nickname, opp_bar);
            }
            if(faint(state->player_pokemon1->pokemon)) {
                printf("%s fainted\n", state->player_pokemon1->pokemon->nickname);
                state->player_teamsize--;
                if(player_whited_out(state)) {
                    printf("You whited out\n");
                    free(health_bar);
                    free(opp_bar);
                    return 1;
                }
                else {
                    switch_out(state);
                }
            }
            if(faint(state->opponent_pokemon1->pokemon)) {
                printf("%s fainted\n", state->opponent_pokemon1->pokemon->nickname);
                state->opponent_teamsize--;
                if(player_wins(state)) {
                    printf("Victory\n");
                    free(health_bar);
                    free(opp_bar);
                    return 0;
                }
                else {
                    ai_faint(state);  // Opponent switched out
                }
            }
        }
    }
}
