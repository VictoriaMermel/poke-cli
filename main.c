#include "pokemon.h"
#include "dex.h"
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

    move tackle = {
    .type = NORMAL,
    .category = PHYSICAL,
    .PP = 35,
    .Power = 40,
    .Accuracy = 100,
    .contact = true,
    .affected_by_protect = true,
    .affected_by_magic_coat = false,
    .affected_by_snatch  = false,
    .affected_by_mirror_move = true,
    .stat_change = 0,
};

    species** all_pokemon = getDex();

    struct stats bulba_stats = { 105, 48, 48, 63, 63, 45 };
    struct stats turters_stats = { 104, 47, 63, 49, 62, 43 };

    pokemon bulba = {
    .species = all_pokemon[0],
    .nickname = "Bulba",
    .level = 50,
    .stats = &bulba_stats,
};

    pokemon turters = {
    .species = all_pokemon[8],
    .nickname = "Turters",
    .level = 50,
    .stats = &turters_stats,
    .move1 = &tackle,
};

    struct battle_state state = initialize(&bulba, &turters);

    printf("bulba: %d\n", state.player_health);
    printf("turters: %d\n", state.opponent_health);

    mon_type squirtleType[2];
    mon_type bulbaType[2];

    printf("damage: %f\n", damageCalc(50, 40, bulba_stats.Attack, turters_stats.Defense, false, NORMAL, bulbaType, squirtleType));

    make_move(&state, &tackle, true);
    print_effectiveness(&turters);

    printf("bulba: %d\n", state.player_health);
    printf("turters: %d\n", state.opponent_health);

//    for(;;) {
//        printf(">>");
//        scanf("%s",command);
//
//    }
}
