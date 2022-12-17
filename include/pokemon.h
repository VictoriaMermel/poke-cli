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

struct battle_state {
    pokemon* player_pokemon;
    pokemon* opponent_pokemon;
    signed char player_stages;
    signed char opponent_stages;
    short player_health;
    short opponent_health;
};

struct battle_state initialize(pokemon* player, pokemon* opponent);


#endif // POKEMON_H_
