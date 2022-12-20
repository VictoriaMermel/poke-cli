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
.Speed = 45,
.evolution_num = 2,
.evolution_level = 16,
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
.evolution_num = 3,
.evolution_level = 32,
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
.evolution_num = 5,
.evolution_level = 16,
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
.evolution_num = 6,
.evolution_level = 36,
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
.Speed = 43,
.evolution_num = 8,
.evolution_level = 16,
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
.evolution_num = 9,
.evolution_level = 36,
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

species caterpie = {
.name = "Caterpie",
.description = "Worm Pokémon",
.pokedex = 10,
.type1 = BUG,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.5,
.catch_rate = 255,
.height = 0.3,
.weight = 2.9,
.pokedex_entry = "Its short feet are tipped with suction pads that enable it to tirelessly climb slopes and walls.",
.HP = 45,
.Attack = 30,
.Defense = 35,
.Sp_Atk = 20,
.Sp_Def = 20,
.Speed = 45,
.evolution_num = 11,
.evolution_level = 7,
};

species metapod = {
.name = "Metapod",
.description = "Cocoon pokémon",
.pokedex = 11,
.type1 = BUG,
.type2 = NONE,
.genderless = false,
.male_ratio = 0.5,
.catch_rate = 120,
.height = 0.7,
.weight = 9.9,
.pokedex_entry = "This Pokémon is vulnerable to attack while its shell is soft, exposing its weak and tender body.",
.HP = 50,
.Attack = 20,
.Defense = 55,
.Sp_Atk = 25,
.Sp_Def = 25,
.Speed = 30,
.evolution_num = 12,
.evolution_level = 10,
};

species butterfree = { "Butterfree", "Butterfly Pokémon", 12, BUG, FLYING, false, 0.5, 45, 1.1, 32.0, "In battle, it flaps its wings at high speed to release highly toxic dust into the air.", 60,45,50,80,80,70 };

species weedle = {
"Weedle",
"Hairy Bug Pokémon",
13,
BUG,
POISON,
false,
0.5,
255,
0.3,
3.2,
"Often found in forests, eating leaves. It has a sharp venomous stinger on its head.",
40,
35,
30,
20,
20,
50,
.evolution_num = 14,
.evolution_level = 7,
};

species kakuna = {
"Kakuna",
"Cocoon Pokémon",
14,
BUG,
POISON,
false,
0.5,
120,
0.6,
10.0,
"Almost incapable of moving, this Pokémon can only harden its shell to protect itself from predators.",
45,
25,
50,
25,
25,
35,
.evolution_num = 15,
.evolution_level = 10,
};

species beedrill = {
"Beedrill",
"Poison Bee Pokémon",
15,
BUG,
POISON,
false,
0.5,
45,
1.0,
29.5,
"Flies at high speed and attacks using its large venomous stingers on its forelegs and tail.",
65,
80,
40,
45,
80,
75,
};

species pidgey = {
"Pidgey",
"Tiny Bird Pokémon",
16,
NORMAL,
FLYING,
false,
0.5,
255,
0.3,
1.8,
"A common sight in forests and woods. It flaps its wings at ground level to kick up blinding sand.",
40,
45,
40,
35,
35,
56,
17,
18,
};

species pidgoetto = {
"Pidgeotto",
"Bird Pokémon",
17,
NORMAL,
FLYING,
false,
0.5,
120,
1.1,
30.0,
"Very protective of its sprawling territorial area, this Pokémon will fiercely peck at any intruder.",
63,
60,
55,
50,
50,
71,
18,
36,
};

species pidgeot = {
"Pigeot",
"Bird Pokémon",
18,
NORMAL,
FLYING,
false,
0.5,
45,
1.5,
39.5,
"When hunting, it skims the surface of water at high speed to pick off unwary prey such as Magikarp.",
83,
80,
75,
70,
70,
101,
};

species rattata = {
"Rattata",
"Mouse Pokémon",
19,
NORMAL,
NONE,
false,
0.5,
255,
0.3,
3.5,
"Bites anything when it attacks. Small and very quick, it is a common sight in many places.",
30,
56,
35,
25,
35,
72,
20,
20,
};

species raticate = {
"Raticate",
"Mouse Pokémon",
20,
NORMAL,
NONE,
false,
0.5,
127,
0.7,
18.5,
"It uses its whiskers to maintain its balance. It apparently slows down if they are cut off.",
55,
81,
60,
50,
70,
97,
};

species spearow = {
"Spearow",
"Tiny Bird Pokémon",
21,
NORMAL,
FLYING,
false,
0.5,
255,
0.3,
2.0,
"Eats bugs in grassy areas. It has to flap its short wings at high speed to stay airborne.",
40,
60,
30,
31,
31,
70,
22,
20,
};

species fearow = {
"Fearow",
"Beak Pokémon",
22,
NORMAL,
FLYING,
false,
0.5,
90,
1.2,
38.0,
"With its huge and magnificent wings, it can keep aloft without ever having to land for rest.",
65,90,65,61,61,100,
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
    &caterpie,
    &metapod,
    &caterpie,
    &weedle,
    &kakuna,
    &beedrill,
    &pidgey,
    &pidgoetto,
    &pidgeot,
    &rattata,
    &raticate,
    &spearow,
    &fearow,

};

    return all_pokemon;
}
