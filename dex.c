/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "dex.h"
#include "pokemon.h"
#include "types.h"
#include <stdlib.h>
#include <stdbool.h>

species bulbasuar = {
.name = "bulbasuar",
.description = "Seed Pokémon",
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

species ivysaur = {
.name = "Ivysaur",
.description = "Seed Pokémon",
.pokedex = 2,
.type1 = GRASS,
.type2 = POISON,
.genderless =false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 1.0,
.weight = 13.0,
.pokedex_entry = "When the bulb on its back grows large, it appears to lose the ability to stand on its hind legs.",
.HP = 60,
.Attack = 62,
.Defense = 63,
.Sp_Atk = 80,
.Sp_Def = 80,
.Speed = 60,
};

species venusaur = {
.name = "Venusaur",
.description = "Seed Pokémon",
.pokedex = 3,
.type1 = GRASS,
.type2 = POISON,
.genderless =false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 2.0,
.weight = 100.0,
.pokedex_entry = "The plant blooms when it is absorbing solar energy. It stays on the move to seek sunlight.",
.HP = 80,
.Attack = 82,
.Defense = 83,
.Sp_Atk = 100,
.Sp_Def = 100,
.Speed = 80,
};

species charmander = {
.name = "Charmander",
.description = "Lizard Pokémon",
.pokedex = 4,
.type1 = FIRE,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 0.6,
.weight = 8.5,
.pokedex_entry = "Obviously prefers hot places. When it rains, steam is said to spout from the tip of its tail.",
.HP = 39,
.Attack = 52,
.Defense = 43,
.Sp_Atk = 60,
.Sp_Def = 50,
.Speed = 65,
};

species charmeleon = {
.name = "Charmeleon",
.description = "Flame Pokémon",
.pokedex = 5,
.type1 = FIRE,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 1.1,
.weight = 19.0,
.pokedex_entry = "When it swings its burning tail, it elevates the temperature to unbearably high levels.",
.HP = 58,
.Attack = 64,
.Defense = 58,
.Sp_Atk = 80,
.Sp_Def = 65,
.Speed = 80,
};

species charizard = {
.name = "Charizard",
.description = "Flame Pokémon",
.pokedex = 6,
.type1 = FIRE,
.type2 = FLYING,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 1.7,
.weight = 90.5,
.pokedex_entry = "Spits fire that is hot enough to melt boulders. Known to cause forest fires unintentionally.",
.HP = 78,
.Attack = 84,
.Defense = 78,
.Sp_Atk = 109,
.Sp_Def = 85,
.Speed = 100,
};

species squirtle = {
.name = "Squirtle",
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

species wartortle = {
.name = "Wartortle",
.description = "Turtle Pokémon",
.pokedex = 8,
.type1 = WATER,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 1.0,
.weight = 22.5,
.pokedex_entry = "Often hides in water to stalk unwary prey. For swimming fast, it moves its ears to maintain balance.",
.HP = 59,
.Attack = 63,
.Defense = 80,
.Sp_Atk = 65,
.Sp_Def = 80,
.Speed = 58,
};

species blastoise = {
.name = "Blastoise",
.description = "Shellfish Pokémon",
.pokedex = 9,
.type1 = WATER,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.875,
.catch_rate = 45,
.height = 1.6,
.weight = 85.5,
.pokedex_entry = "A brutal Pokémon with pressurized water jets on its shell. They are used for high speed tackles.",
.HP = 79,
.Attack = 83,
.Defense = 100,
.Sp_Atk = 85,
.Sp_Def = 105,
.Speed = 78,
};

species** getDex(void) {

    static species* all_pokemon[151] = {
    &bulbasuar,
    &ivysaur,
    &venusaur,
    &charmander,
    &charmeleon,
    &charizard,
    &squirtle,
    &wartortle,
    &blastoise,
};

    return all_pokemon;
}
