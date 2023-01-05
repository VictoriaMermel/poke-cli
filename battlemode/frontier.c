/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
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



void create_pokemon(pokemon* pool, species* species, int level, move* m1, ability ability, int i) {

    static struct stats demo_stats = {50,50,50,50,50,50};

    pokemon pokemon = {
    .species = species,
    .stats = &demo_stats,
    .level = 60,
    .move1 = m1,
    .ability = ability,
};
    strcpy(pokemon.nickname, species->name);
    memcpy(pool+(sizeof(pokemon)*i), &pokemon, sizeof(pokemon));
}

pokemon* initialize_pool(int level) {

    pokemon* pool = malloc(sizeof(pokemon)*15);

    create_pokemon(pool, &venusaur, level, &tackle, OVERGROW, 0);
    create_pokemon(pool, &gengar, level, &tackle, CURSED_BODY, 1);
    create_pokemon(pool, &blastoise, level, &tackle, OVERGROW, 2);
    create_pokemon(pool, &kingler, level, &tackle, SHELL_ARMOR, 3);
    create_pokemon(pool, &hypno, level, &tackle, INSOMNIA, 4);
    create_pokemon(pool, &alakazam, level, &tackle, SYNCRONIZE, 5);
    create_pokemon(pool, &slowbro, level, &tackle, OWN_TEMPO, 6);
    create_pokemon(pool, &rapidash, level, &tackle, FLASH_FIRE, 7);
    create_pokemon(pool, &golem, level, &tackle, STURDY, 8);
    create_pokemon(pool, &tentacruel, level, &tackle, CLEAR_BODY, 9);
    create_pokemon(pool, &machamp, level, &tackle, GUTS, 10);
    create_pokemon(pool, &primeape, level, &tackle, VITAL_SPIRIT, 11);

    return pool;
}

pokemon* get_rand_pokemon(pokemon* pool) {

    int rand = random_num(0, 11);
    return pool+(sizeof(pokemon)*rand);
}

void summary(pokemon* pokemon) {
    printf("%s\n%s\n%s\n%s\n%s/n", pokemon->nickname, pokemon->move1->name, pokemon->move2->name, pokemon->move3->name, pokemon->move4->name);
}

void factory_main() {
    printf("factory mode\n\n");
    int selection;
    char confirmation[2];
    int i;
    bool removal = false;
    pokemon* team[3];
    uint team_selected = 0;

    pokemon* offers[6];
    pokemon * pool = initialize_pool(60);
    for (i = 0; i<6; i++) {
        pokemon* new = get_rand_pokemon(pool);
        bool notnew = false;
        for(int j = 0; j<6; j++) {
            if (offers[j] == new) notnew = true;
        }
        if (i == 0 || (!notnew)){
            offers[i] = new;
        }
        else i--;
    }
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
            printf("Error: Enter a value between 1 and 3");
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

    free(pool);
}
