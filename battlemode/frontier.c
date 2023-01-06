/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "frontier.h"
#include "pokemon.h"
#include "moves.h"
#include "ability.h"
#include "damage.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void create_pokemon(pokemon* pool, species* species, int level, move* m1, ability ability, int i, char IVs[6], unsigned char EVs[6]) {

    int hp = HP_calc(IVs[0], EVs[0], species->HP, level);
    int atk = stat_calc(IVs[1], EVs[1], species->Attack, level);
    int def = stat_calc(IVs[2], EVs[2], species->Defense, level);
    int spa = stat_calc(IVs[3], EVs[3], species->Sp_Atk, level);
    int spd = stat_calc(IVs[4], EVs[4], species->Sp_Def, level);
    int spe = stat_calc(IVs[5], EVs[5], species->Speed, level);


    pokemon pokemon = {
    .species = species,
    .level = level,
    .move1 = m1,
    .player = false,
    .ability = ability,
    .HP = hp,
    .Attack = atk,
    .Defense = def,
    .Sp_Atk = spa,
    .Sp_Def = spd,
    .Speed = spe,
};
    strcpy(pokemon.nickname, species->name);
    memcpy(pool+(sizeof(pokemon)*i), &pokemon, sizeof(pokemon));
}

pokemon* initialize_pool(int level) {

    pokemon* pool = malloc(sizeof(pokemon)*15);

    char demoIVs[6] = {21,30,12,7,3,19};
    unsigned char demoEVs[6] = {255,0,4,0,0,255};

    create_pokemon(pool, &venusaur, level, &tackle, OVERGROW, 0, demoIVs, demoEVs);
    create_pokemon(pool, &gengar, level, &dbg, CURSED_BODY, 1, demoIVs, demoEVs);
    create_pokemon(pool, &blastoise, level, &tackle, OVERGROW, 2, demoIVs, demoEVs);
    create_pokemon(pool, &kingler, level, &tackle, SHELL_ARMOR, 3, demoIVs, demoEVs);
    create_pokemon(pool, &hypno, level, &tackle, INSOMNIA, 4, demoIVs, demoEVs);
    create_pokemon(pool, &alakazam, level, &tackle, SYNCRONIZE, 5, demoIVs, demoEVs);
    create_pokemon(pool, &slowbro, level, &tackle, OWN_TEMPO, 6, demoIVs, demoEVs);
    create_pokemon(pool, &rapidash, level, &tackle, FLASH_FIRE, 7, demoIVs, demoEVs);
    create_pokemon(pool, &golem, level, &tackle, STURDY, 8, demoIVs, demoEVs);
    create_pokemon(pool, &tentacruel, level, &tackle, CLEAR_BODY, 9, demoIVs, demoEVs);
    create_pokemon(pool, &machamp, level, &tackle, GUTS, 10, demoIVs, demoEVs);
    create_pokemon(pool, &primeape, level, &tackle, VITAL_SPIRIT, 11, demoIVs, demoEVs);

    return pool;
}

pokemon* get_rand_pokemon(pokemon* pool) {

    int rand = random_num(0, 11);
    return pool+(sizeof(pokemon)*rand);
}

void summary(pokemon* pokemon) {
    printf("%s\n\n%s\n%s\n%s\n%s\n", pokemon->nickname, pokemon->move1->name, pokemon->move2->name, pokemon->move3->name, pokemon->move4->name);
}

void factory_main() {
    printf("factory mode\n\n");
    int selection;
    char confirmation[2];
    int i;
    bool removal = false;
    pokemon* team[3];
    uint team_selected = 0;

    pokemon * pool = initialize_pool(60);
    pokemon* offers[9];
    for (i = 0; i<9; i++) {
        pokemon* new = get_rand_pokemon(pool);
        bool notnew = false;
        for(int j = 0; j<9; j++) {
            if (offers[j] == new) notnew = true;
        }
        if (i == 0 || (!notnew)){
            offers[i] = new;
        }
        else i--;
    }
#ifdef DEBUG
    offers[0] = pool+sizeof(pokemon); // Gengar will be always available in DEBUG mode because it knows dbg move.
#endif
offer_prompt:
    for (i = 0; i<6; i++) {
        if (offers[i] == team[0] || offers[i] == team[1] || offers[i] == team[2] ) {
            printf("(%d) %s *\n",i+1, offers[i]->nickname);
        }
        else {
            printf("(%d) %s\n", i+1, offers[i]->nickname);
        }
    }
    printf("\n");
    printf("\n>> ");
    scanf("%d", &selection);
    pokemon* viewed_pokemon;
    if (selection > 6 || selection < 1) {
        printf("Error: Enter a selection between 1 and 6\n");
        goto offer_prompt;
    }
    viewed_pokemon = offers[selection-1];
    printf("What would you like to do with %s?\n", viewed_pokemon->nickname);
    if (viewed_pokemon == team[0] || viewed_pokemon == team[1] || viewed_pokemon == team[2]) {
        printf("(1) Remove from team\n");
        removal = true;
    }
    else {
        printf("(1) Add to team\n");
        removal = false;
    }
    printf("(2) Summary\n(3) Back\n");
what_to_do_prompt:
    printf("\n>> ");
    scanf("%d", &selection);
    switch(selection) {
        case 1 :
            if(!removal) {
                team[team_selected] = viewed_pokemon;
                team_selected++;
                goto done;
            }
            else {
                for (i = 0; i<team_selected; i++) {
                    if (team[i] == viewed_pokemon) team[i] = NULL;
                }
                pokemon* arr[3];
                int j = 0;
                for (i = 0; i<3; i++) {
                    if (team[i] != NULL) {
                        arr[j] = team[i];
                        j++;
                    }
                }
                memcpy(team, arr, sizeof(team));
                team_selected--;
                goto offer_prompt;
            }
        case 2 :
            summary(viewed_pokemon);
            goto what_to_do_prompt;
        case 3 :
            goto offer_prompt;
        default:
            printf("Error: Enter a value between 1 and 3\n");
            goto what_to_do_prompt;
    }
done:
    if (team_selected < 3) goto offer_prompt;
confirmation_prompt:
    printf("Is this selection OK? (y/n) ");
    scanf("%s", confirmation);
    if (strcmp(confirmation, "y") == 0) {
        printf("Begin Challenge\n");
    }
    else if (strcmp(confirmation, "n") == 0) {
        goto offer_prompt;
    }
    else goto confirmation_prompt;

    int streak = 0;
    for(;;) {
        struct battle_state state;                  // This looks awful, need to fix structures
        struct pokemon_state player_pokemon1;       // in pokemon.h ASAP
        struct pokemon_state player_pokemon2;
        struct pokemon_state player_pokemon3;
        struct pokemon_state opponent_pokemon1;
        struct pokemon_state opponent_pokemon2;
        struct pokemon_state opponent_pokemon3;
        state.player_teamsize = 3;
        state.opponent_teamsize = 3;
        state.player_pokemon1 = &player_pokemon1;
        state.player_pokemon2 = &player_pokemon2;
        state.player_pokemon3 = &player_pokemon3;
        state.opponent_pokemon1 = &opponent_pokemon1;
        state.opponent_pokemon2 = &opponent_pokemon2;
        state.opponent_pokemon3 = &opponent_pokemon3;

        team[0]->player = true;
        team[1]->player = true;
        team[2]->player = true;

        state.player_pokemon1->pokemon = team[0];
        state.player_pokemon2->pokemon = team[1];
        state.player_pokemon3->pokemon = team[2];

        state.opponent_pokemon1->pokemon = offers[6];
        state.opponent_pokemon2->pokemon = offers[7];
        state.opponent_pokemon3->pokemon = offers[8];

        team[0]->status = state.player_pokemon1;
        team[1]->status = state.player_pokemon2;
        team[2]->status = state.player_pokemon3;
        offers[6]->status = state.opponent_pokemon1;
        offers[7]->status = state.opponent_pokemon2;
        offers[8]->status = state.opponent_pokemon3;

        state.player_pokemon1->health = team[0]->HP;
        state.opponent_pokemon1->health = offers[6]->HP;
        state.player_pokemon2->health = team[1]->HP;
        state.opponent_pokemon2->health = offers[7]->HP;
        state.player_pokemon3->health = team[2]->HP;
        state.opponent_pokemon3->health = offers[8]->HP;
        state.player_pokemon1-> fainted = false;
        state.player_pokemon2-> fainted = false;
        state.player_pokemon3-> fainted = false;
        state.opponent_pokemon1 -> fainted = false;
        state.opponent_pokemon2 -> fainted = false;
        state.opponent_pokemon3 -> fainted = false;

        unsigned int PP[5];
        state.player_pokemon1->PP[1] = team[0]->move1->PP;
        if(team[0]->move2 > 0) state.player_pokemon1->PP[2] = team[0]->move2->PP;
        if(team[0]->move3 > 0) state.player_pokemon1->PP[3] = team[0]->move3->PP;
        if(team[0]->move4 > 0) state.player_pokemon1->PP[4] = team[0]->move4->PP;
        state.opponent_pokemon1->PP[1] = offers[6]->move1->PP;
        if(offers[6]->move2 > 0) state.opponent_pokemon1->PP[2] = offers[6]->move2->PP;
        if(offers[6]->move3 > 0) state.opponent_pokemon1->PP[3] = offers[6]->move3->PP;
        if(offers[6]->move4 > 0) state.opponent_pokemon1->PP[4] = offers[6]->move4->PP;
        state.player_pokemon2->PP[1] = team[0]->move1->PP;
        if(team[1]->move2 > 0) state.player_pokemon2->PP[2] = team[1]->move2->PP;
        if(team[1]->move3 > 0) state.player_pokemon2->PP[3] = team[1]->move3->PP;
        if(team[1]->move4 > 0) state.player_pokemon2->PP[4] = team[1]->move4->PP;
        state.opponent_pokemon2->PP[1] = offers[6]->move1->PP;
        if(offers[7]->move2 > 0) state.opponent_pokemon2->PP[2] = offers[7]->move2->PP;
        if(offers[7]->move3 > 0) state.opponent_pokemon2->PP[3] = offers[7]->move3->PP;
        if(offers[7]->move4 > 0) state.opponent_pokemon2->PP[4] = offers[7]->move4->PP;
        state.player_pokemon3->PP[1] = team[0]->move1->PP;
        if(team[2]->move2 > 0) state.player_pokemon3->PP[2] = team[2]->move2->PP;
        if(team[2]->move3 > 0) state.player_pokemon3->PP[3] = team[2]->move3->PP;
        if(team[2]->move4 > 0) state.player_pokemon3->PP[4] = team[2]->move4->PP;
        state.opponent_pokemon3->PP[1] = offers[6]->move1->PP;
        if(offers[8]->move2 > 0) state.opponent_pokemon3->PP[2] = offers[8]->move2->PP;
        if(offers[8]->move3 > 0) state.opponent_pokemon3->PP[3] = offers[8]->move3->PP;
        if(offers[8]->move4 > 0) state.opponent_pokemon3->PP[4] = offers[8]->move4->PP;

        int win = (battle_main(&state) == 0);
        if(!win) break;
        streak++;

        printf("\nCongratulations! Would you like to switch out a pokemon?\n\n");
mon_to_steel:
        for(i=6; i<9; i++) {
            printf("(%d) %s\n", i-5, offers[i]->nickname);
        }
        printf("Press 'q' to contiue\n\n>> ");
        scanf("%d", &selection);
        if (selection == 'q') continue;
        else if (selection > 8 || selection < 1) {
            printf("Error: Select number between 1 and 3\n");
            goto mon_to_steel;
        }
        pokemon * wanted = offers[selection+5];
mon_to_return:
        printf("Replace which pokemon with %s?\n\n", wanted->nickname);
        for (i=0; i<3; i++) {
            printf("(%d) %s\n", i+1, team[i]->nickname);
        }
        printf("Press 'q' to cancel\n\n>>");
        scanf("%d", &selection);
        if (selection == 'q') goto mon_to_steel;
        else if (selection > 3 || selection < 1) {
            printf("Error: Select number between 1 and 3\n");
            goto mon_to_return;
        }
        team[selection-1] = wanted;

        memcpy(offers, team, sizeof(team));
        for(i = 6; i<9; i++) {
            pokemon* new = get_rand_pokemon(pool);
            bool notnew = false;
            for(int j = 0; j<9; j++) {
                if (offers[j] == new) notnew = true;
            }
            if (i == 0 || (!notnew)){
                offers[i] = new;
            }
            else i--;
        }
    }
    printf("Your Streak: %d",streak);

    free(pool);
}
