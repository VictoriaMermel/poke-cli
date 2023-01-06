/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "moves.h"
#include "pokemon.h"
#include "damage.h"
#include "ability.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef NT
#include <windows.h>
#else
#include <unistd.h>
#endif

void stat_change(pokemon* pokemon, signed char* stage, signed char change, char* stat) {
    char rise[16];
    bool sharp;
    if(*stage >= 6) {
        printf("%s's %s won't go any higher\n", pokemon->nickname, stat);
        sleep(1);
    }
    else if(*stage <= -6) {
        printf("%s's %s won't go any lower\n", pokemon->nickname, stat);
        sleep(1);
    }
    else {
        if (change != 0) {
            *stage = *stage + change;
            if (change > 1 || change < -1) sharp = true;
            if (change > 0) strcpy(rise, "rose");
            else strcpy(rise, "fell");

            if (sharp) printf("%s's %s sharply %s\n", pokemon->nickname, stat, rise);
            else printf("%s's %s %s\n", pokemon->nickname, stat, rise);
            sleep(1);
        }
    }
}

float get_Effective_stat(signed char stage) {
    float atk_mod;

        switch (stage) {
            case 0 :
                atk_mod = 1;
            case 1 :
                atk_mod = 3/2;
            case 4 :
                atk_mod = 6/2;
            case 5 :
                atk_mod = 8/2;
            case -1 :
                atk_mod = 2/3;
            case -2 :
                atk_mod = 2/4;
            case -3 :
                atk_mod = 2/5;
            case -4 :
                atk_mod = 2/6;
            case -5 :
                atk_mod = 2/7;
            case -6 :
                atk_mod = 2/8;
            default:
                atk_mod = 1;
        }
        return atk_mod;
}

void make_generic_move(struct battle_state* state, move* move, bool player) {

    pokemon* attacker;
    pokemon* defender;
    short* health;
    float damage;
    unsigned short atk;
    unsigned short def;
    float atk_mod;
    float def_mod;

    sleep(2);

    if(player) {
        attacker = state->player_pokemon1->pokemon;
        defender = state->opponent_pokemon1->pokemon;
        health = &state->opponent_pokemon1->health;
    }
    else {
        attacker = state->opponent_pokemon1->pokemon;
        defender = state->player_pokemon1->pokemon;
        health = &state->player_pokemon1->health;
    }

    mon_type pokemon_types[2] = {attacker->species->type1, attacker->species->type2};
    mon_type def_type[2] = {defender->species->type1, defender->species->type2};
    if(move->category == PHYSICAL) {
        atk = attacker->Attack * get_Effective_stat(attacker->status->atk_stage);
        def = defender->Defense * get_Effective_stat(attacker->status->def_stage);
    }
    else {
        atk = attacker->Sp_Atk * get_Effective_stat(attacker->status->spa_stage);
        def = defender->Sp_Def * get_Effective_stat(attacker->status->spd_stage);
    }

    stat_change(attacker, &attacker->status->atk_stage, move->atk_change, "Attack");
    stat_change(attacker, &attacker->status->def_stage, move->def_change, "Defense");
    stat_change(attacker, &attacker->status->spa_stage, move->spa_change, "Special Attack");
    stat_change(attacker, &attacker->status->spd_stage, move->spd_change, "Special Defense");
    stat_change(attacker, &attacker->status->spe_stage, move->spe_change, "Speed");

    stat_change(defender, &defender->status->atk_stage, move->opponent_atk_change, "Attack");
    stat_change(defender, &defender->status->def_stage, move->opponent_def_change, "Defense");
    stat_change(defender, &defender->status->spa_stage, move->opponent_spa_change, "Special Attack");
    stat_change(defender, &defender->status->spd_stage, move->opponent_spd_change, "Special Attack");
    stat_change(defender, &defender->status->spe_stage, move->opponent_spe_change, "Speed");
    if(move->category == STATUS) {
        damage = 0;
    }
    else {
        ability attacker_ability = attacker->ability;
        if( attacker_ability == OVERGROW || attacker_ability == BLAZE || attacker_ability == SWARM || attacker_ability == TORRENT ) {
            overgrow_like(move, attacker, &atk);
        }
        damage = damageCalc(attacker->level, move->Power, atk, defender->Defense, false, move->type,
                        pokemon_types, def_type);

        print_effectiveness(defender);
        print_crit();
    }

    *health = *health - (int)damage;
}

void damage_dealing(struct battle_state* state, move* move, bool player) {
    make_generic_move(state, move, player);
}

void use_splash(void) {
    sleep(1);
    printf("But nothing happened\n");
    sleep(1);
}

move tackle = { "Tackle", &damage_dealing, NORMAL,PHYSICAL,53,40,100,true,true,false,false,true};
move pound = { "Pound", &damage_dealing, NORMAL,PHYSICAL,35,40,100,true,true,false,false,true };
move vine_whip = { "Vine Whip", &damage_dealing, GRASS,PHYSICAL,25,45,100,true,true,false,false,true };
move swords_dance = { "Swords Dance",&damage_dealing,NORMAL,STATUS,20,0,100,false,false,false,true,false, 2};
move growl = { "Growl",&damage_dealing,NORMAL,STATUS,40,0,100,false,true,true,false,true,0,-1 };
move tail_whip = { "Tail Whip",&damage_dealing,NORMAL,STATUS,30,0,100,false,true,true,false,true,0,0,0,-1 };
move splash = { "Splash", &use_splash, WATER,PHYSICAL };
#ifdef DEBUG
move dbg = { "Big Attack",&damage_dealing,NORMAL,PHYSICAL,99,200,100 };
#endif
