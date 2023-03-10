/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef POKEMON_H_
#define POKEMON_H_
#include "types.h"
#include <stdbool.h>

#define SINGLES 2
#define DOUBLES 4

typedef unsigned int ability;
typedef const struct move move;

struct by_lu {
    int level;
    move* move;
};

typedef const struct species {
    char name[16];
    char description[32];
    unsigned short pokedex;
    mon_type type1;
    mon_type type2;
    bool genderless;
    float male_ratio;
    char catch_rate;
    float height;
    float weight;
    char pokedex_entry[255];
    unsigned char HP;
    unsigned char Attack;
    unsigned char Defense;
    unsigned char Sp_Atk;
    unsigned char Sp_Def;
    unsigned char Speed;
    unsigned short evolution_num;
    unsigned int evolution_level;
    ability abilities[2];
    unsigned int learnset[30];
    unsigned int tms[];
} species;

typedef const struct move move;


// TODO: Add natures, IVs, EVs, Experience (eventually), friendship, and OT
// TODO: Implement Hold Items and abilities

typedef struct pokemon {
    species* species;
    char nickname[16];
    unsigned char level;
    unsigned short HP;
    unsigned short Attack;
    unsigned short Defense;
    unsigned short Sp_Atk;
    unsigned short Sp_Def;
    unsigned short Speed;
    struct pokemon_state* status;
    ability ability;
    bool player;
    char atk_IV;
    char def_IV;
    char HP_IV;
    char spa_IV;
    char spd_IV;
    char spe_IV;
    unsigned char atk_EV;
    unsigned char def_EV;
    unsigned char spa_EV;
    unsigned char HP_EV;
    unsigned char spd_EV;
    unsigned char spe_EV;
    move* move1;
    move* move2;
    move* move3;
    move* move4;

} pokemon;


// TODO: Combine pokemon state and struct pokemon

struct pokemon_state {
    short health;
    bool fainted;
    signed char atk_stage;
    signed char def_stage;
    signed char spa_stage;
    signed char spd_stage;
    signed char spe_stage;
    pokemon* pokemon;
    unsigned int PP[5];
};

struct battle_state {
    struct pokemon_state* player_pokemon1;
    struct pokemon_state* player_pokemon2;
    struct pokemon_state* player_pokemon3;
    struct pokemon_state* player_pokemon4;
    struct pokemon_state* player_pokemon5;
    struct pokemon_state* player_pokemon6;
    unsigned char player_teamsize;
    unsigned char player_remaining;
    unsigned char opponent_remaining;
    unsigned char opponent_teamsize;
    struct pokemon_state* opponent_pokemon1;
    struct pokemon_state* opponent_pokemon2;
    struct pokemon_state* opponent_pokemon3;
    struct pokemon_state* opponent_pokemon4;
    struct pokemon_state* opponent_pokemon5;
    struct pokemon_state* opponent_pokemon6;
};

int battle_main(struct battle_state* state);


#endif // POKEMON_H_
