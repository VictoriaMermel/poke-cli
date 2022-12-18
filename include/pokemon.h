/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
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

typedef struct species {
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
} species;

struct stats {
    unsigned short HP;
    unsigned short Attack;
    unsigned short Defense;
    unsigned short Sp_Atk;
    unsigned short Sp_Def;
    unsigned short Speed;
};

typedef struct move move;

typedef struct pokemon {
    species* species;
    char nickname[16];
    unsigned char level;
    struct stats* stats;
    move* move1;
    move* move2;
    move* move3;
    move* move4;

} pokemon;

struct pokemon_state {
    short health;
    signed char atk_stage;
    signed char def_stage;
    signed char spa_stage;
    signed char spd_stage;
    signed char speed;
    pokemon* pokemon;
    unsigned int move1_PP;
    unsigned int move2_PP;
    unsigned int move3_PP;
    unsigned int move4_PP;
};

struct battle_state {
    struct pokemon_state* player_pokemon1;
    struct pokemon_state* player_pokemon2;
    struct pokemon_state* player_pokemon3;
    struct pokemon_state* player_pokemon4;
    struct pokemon_state* player_pokemon5;
    struct pokemon_state* player_pokemon6;
    struct pokemon_state* opponent_pokemon1;
    struct pokemon_state* opponent_pokemon2;
    struct pokemon_state* opponent_pokemon3;
    struct pokemon_state* opponent_pokemon4;
    struct pokemon_state* opponent_pokemon5;
    struct pokemon_state* opponent_pokemon6;
};

struct battle_state initialize(pokemon* player, pokemon* opponent);


#endif // POKEMON_H_
