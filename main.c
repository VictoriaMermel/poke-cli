#include "pokemon.h"
#include "damage.h"
#include "types.h"
#include "moves.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct battle_state initialize(pokemon* player, pokemon* opponent) {

    struct battle_state state;
    state.player_pokemon = player;
    state.opponent_pokemon = opponent;

    state.player_stages = 0;
    state.opponent_stages = 0;
    state.player_health = player->stats->HP;
    state.opponent_health = opponent->stats->HP;

    return state;
}

int main(int argc , char ** argv) {

    printf("\n");
    printf("Welcome\n");
    char command[255];

    move tackle;
    tackle.type = NORMAL;
    tackle.category = PHYSICAL;
    tackle.PP = 35;
    tackle.Power = 40;
    tackle.Accuracy = 100;
    tackle.contact = true;
    tackle.affected_by_protect = true;
    tackle.affected_by_magic_coat = false;
    tackle.affected_by_snatch  = false;
    tackle.affected_by_mirror_move = true;
    tackle.stat_change = 0;

    species bulbasaur;
    strcpy(bulbasaur.name, "bulbasaur");
    strcpy(bulbasaur.description, "Seed Pokémon");
    bulbasaur.pokedex = 1;
    bulbasaur.type1 = GRASS;
    bulbasaur.type2 = POISON;
    bulbasaur.genderless = false;
    bulbasaur.male_ratio = 0.875;
    bulbasaur.catch_rate = 45;
    bulbasaur.height = 0.7;
    bulbasaur.weight = 6.9;
    strcpy(bulbasaur.pokedex_entry,"A strange seed was planted on its back at birth. The plant sprouts and grows with this Pokémon.");
    bulbasaur.HP = 45;
    bulbasaur.Attack = 49;
    bulbasaur.Defense = 49;
    bulbasaur.Sp_Atk = 65;
    bulbasaur.Sp_Def = 65;
    bulbasaur.Speed = 45;

    struct stats bulba_stats;
    bulba_stats.Attack = 48;
    bulba_stats.HP = 105;
    bulba_stats.Defense = 48;
    bulba_stats.Sp_Atk = 63;
    bulba_stats.Sp_Def = 63;
    bulba_stats.Speed = 45;

    pokemon bulba;
    bulba.species = &bulbasaur;
    bulba.level = 50;
    bulba.stats = &bulba_stats;

    species squirtle;
    strcpy(squirtle.name, "squirtle");
    strcpy(squirtle.description, "Tiny Turtle Pokémon");
    squirtle.pokedex = 7;
    squirtle.type1 = WATER;
    squirtle.genderless = false;
    squirtle.male_ratio = 0.875;
    squirtle.catch_rate = 45;
    squirtle.height = 0.5;
    squirtle.weight = 9.0;
    strcpy(squirtle.pokedex_entry, "After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth.");
    squirtle.HP = 44;
    squirtle.Attack = 48;
    squirtle.Defense = 65;
    squirtle.Sp_Atk = 50;
    squirtle.Sp_Def = 64;
    squirtle.Speed = 43;

    struct stats turters_stats;
    turters_stats.HP = 104;
    turters_stats.Attack = 47;
    turters_stats.Defense = 63;
    turters_stats.Sp_Atk = 49;
    turters_stats.Sp_Def = 62;
    turters_stats.Speed = 43;

    pokemon turters;
    turters.species = &squirtle;
    turters.level = 50;
    turters.stats = &turters_stats;
    turters.move1 = &tackle;

    struct battle_state state = initialize(&bulba, &turters);

    printf("bulba: %d\n", state.player_health);
    printf("turters: %d\n", state.opponent_health);

    mon_type squirtleType[2];
    mon_type bulbaType[2];

    printf("damage: %f\n", damageCalc(50, 40, bulba_stats.Attack, turters_stats.Defense, false, NORMAL, bulbaType, squirtleType));

    make_move(&state, &tackle, true);

    printf("bulba: %d\n", state.player_health);
    printf("turters: %d\n", state.opponent_health);

//    for(;;) {
//        printf(">>");
//        scanf("%s",command);
//
//    }
}
