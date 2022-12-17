#include "dex.h"
#include "pokemon.h"
#include "types.h"
#include <stdlib.h>
#include <stdbool.h>

species bulbasuar = {
.name = "bulbasuar",
.description = "Seed Pokemon",
.pokedex = 1,
.type1 = GRASS,
.type2 = POISON,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 0.7,
.weight = 6.9,
.pokedex_entry = "A strange seed was planted on its back at birth. The plant sprouts and grows with this Pokémon.",
.HP = 45,
.Attack = 49,
.Defense = 49,
.Sp_Atk = 65,
.Sp_Def = 65,
.Speed = 45
};

species squirtle = {
.name = "squirtle",
.description = "Tiny Turtle Pokémon",
.pokedex = 7,
.type1 = WATER,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 0.5,
.weight = 9.0,
.pokedex_entry = "After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth.",
.HP = 44,
.Attack = 48,
.Defense = 65,
.Sp_Atk = 50,
.Sp_Def = 64,
.Speed = 43
};

species** getDex(void) {

    species** all_pokemon;

    all_pokemon[0] = &bulbasuar;
    all_pokemon[8] = &squirtle;

    return all_pokemon;
}
