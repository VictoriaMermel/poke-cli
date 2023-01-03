/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "pokemon.h"
#include "types.h"
#include "ability.h"
#include "moves.h"
#include <stdlib.h>
#include <stdbool.h>

species bulbasaur = {
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
.abilities = {OVERGROW},
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
.abilities = {OVERGROW},
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
.abilities = {OVERGROW},
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
.abilities = {BLAZE},
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
.abilities = {BLAZE},
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
.abilities = {BLAZE},
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
.abilities = {TORRENT},
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
.abilities = {TORRENT},
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
.abilities = {TORRENT},
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
.abilities = {SHIELD_DUST},
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
.abilities = {SHED_SKIN},
};

species butterfree = { "Butterfree", "Butterfly Pokémon", 12, BUG, FLYING, false, 0.5, 45, 1.1, 32.0, "In battle, it flaps its wings at high speed to release highly toxic dust into the air.", 60,45,50,80,80,70,0,0, {COMPOUND_EYES} };

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
.abilities = {SHIELD_DUST},
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
.abilities = {SHED_SKIN},
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
.abilities = {SWARM},
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
.abilities = {KEEN_EYES, TANGLED_FEET},
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
.abilities = {KEEN_EYES, TANGLED_FEET},
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
.abilities = {KEEN_EYES, TANGLED_FEET},
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
.abilities = {RUN_AWAY, GUTS},
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
.abilities = {RUN_AWAY,GUTS},
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
.abilities = {KEEN_EYES},
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
.abilities = {KEEN_EYES},
};

species Ekans = {
"Ekans",
"Snake Pokémon",
23,
POISON,
NONE,
false,
0.5,
255,
2.0,
6.9,
"Moves silently and stealthily. Eats the eggs of birds, such as Pidgey and Spearow, whole.",
35,60,44,40,54,55,
24,
22,
.abilities = {INTIMIDATE, SHED_SKIN},
};

species Arbok = {
"Arbok",
"Cobra Pokémon",
24,
POISON,
NONE,
false,
0.5,
90,
3.5,
65.0,
"It is rumored that the ferocious warning markings on its belly differ from area to area.",
60,95,69,65,79,80,
.abilities = {INTIMIDATE, SHED_SKIN},
};

species Pikachu = {
"Pikachu",
"Mouse Pokémon",
25,
ELECTRIC,
NONE,
false,
0.5,
190,
0.4,
6.0,
"When several of these Pokémon gather, their electricity could build and cause lightning storms.",
35,55,40,50,50,90,
.evolution_num = 26,
.abilities = {STATIC},
};

species raichu = {
"Raichu",
"Mouse Pokémon",
26,
ELECTRIC,
NONE,
false,
0.5,
75,
0.8,
30.0,
"Its long tail serves as a ground to protect itself from its own high voltage power.",
60,90,55,90,80,100,
.abilities = {STATIC},
};

species sandshrew = {
"Sandshrew",
"Mouse Pokémon",
27,
GROUND,
NONE,
false,
0.5,
255,
0.6,
12.0,
"Burrows deep underground in arid locations far from water. It only emerges to hunt for food.",
50,75,85,20,30,40,
28,22,
.abilities = {SAND_VEIL},
};

species sandslash = {
"Sandslash",
"Mouse Pokémon",
28,
GROUND,
NONE,
false,
0.5,
90,
1.0,
29.5,
"Curls up into a spiny ball when threatened. It can roll while curled up to attack or escape.",
75,100,110,45,55,65,
.abilities = {SAND_VEIL},
};

species nidoranf = {
"Nidoran♀",
"Poison Pin Pokémon",
29,
POISON,
NONE,
false,
0.0,
235,
0.4,
7.0,
"Although small, its venomous barbs render this Pokémon dangerous. The female has smaller horns.",
55,47,52,40,40,41,
30,16,
.abilities = {POISON_POINT, RIVALRY},
};

species nidorina = {
"Nidorina",
"Poison Pin Pokémon",
30,
POISON,
NONE,
false,
0.0,
120,
0.8,
20.0,
"The female's horn develops slowly. Prefers physical attacks such as clawing and biting.",
70,62,67,55,55,56,
31,
.abilities = {POISON_POINT, RIVALRY},
};

species nidoqueen = {
"Nidoqueen",
"Drill Pokémon",
31,
POISON,
GROUND,
false,
0.0,
45,
1.3,
60.0,
"Its hard scales provide strong protection. It uses its hefty bulk to execute powerful moves.",
90,92,87,75,85,76,
.abilities = {POISON_POINT, RIVALRY},
};

species nidoranm = {
"Nidoran♂",
"Poison Pin Pokémon",
32,
POISON,
NONE,
false,
1.0,
235,
0.5,
9.0,
"Stiffens its ears to sense danger. The larger its horns, the more powerful its secreted venom.",
46,57,40,40,40,50,
33,16,
.abilities = {POISON_POINT, RIVALRY},
};

species nidorino = {
"Nidorino",
"Poison Pin Pokémon",
33,
POISON,
NONE,
false,
1.0,
120,
0.5,
9.0,
"An aggressive Pokémon that is quick to attack. The horn on its head secretes a powerful venom.",
61,72,57,55,55,65,
34,
.abilities = {POISON_POINT, RIVALRY},
};

species nidoking = {
"Nidoking",
"Drill Pokémon",
34,
POISON,
GROUND,
false,
1.0,
45,
1.4,
62.0,
"It uses its powerful tail in battle to smash, constrict, then break the prey's bones.",
81,102,77,85,75,85,
.abilities = {POISON_POINT, RIVALRY},
};

species clefairy = {
"Clefairy",
"Fairy Pokémon",
35,
FAIRY,
NONE,
false,
0.25,
150,
0.6,
7.5,
"Its magical and cute appeal has many admirers. It is rare and found only in certain areas.",
70,45,48,60,65,35,
36,
.abilities = {MAGIC_GUARD},
};

species Clefable = {
"Clefable",
"Fairy Pokémon",
36,
FAIRY,
NONE,
false,
0.25,
25,
1.3,
40.0,
"A timid fairy Pokémon that is rarely seen. It will run and hide the moment it senses people.",
95,70,73,85,90,60,
.abilities = {MAGIC_GUARD},
};

species vulpix = {
"Vulpix",
"Fox Pokémon",
37,
FIRE,
NONE,
false,
0.25,
190,
0.6,
9.9,
"At the time of birth, it has just one tail. The tail splits from its tip as it grows older.",
38,41,40,50,65,65,
38,
.abilities = {FLASH_FIRE},
};

species ninetales = {
"Ninetales",
"Fox Pokémon",
38,
FIRE,
NONE,
false,
0.25,
75,
1.1,
19.9,
"Very smart and very vengeful. Grabbing one of its many tails could result in a 1000-year curse.",
73,76,75,81,100,100,
.abilities = {FLASH_FIRE},
};

species jigglypuff = {
"Jigglypuff",
"Balloon Pokémon",
39,
NORMAL,
FAIRY,
false,
0.25,
170,
0.5,
5.5,
"When its huge eyes light up, it sings a mysteriously soothing melody that lulls its enemies to sleep.",
115,45,20,45,25,20,
40,
.abilities = {CUTE_CHARM,COMPETITIVE},
};

species wigglytuff = {
"Wigglytuff",
"Balloon Pokémon",
40,
NORMAL,
FAIRY,
false,
0.25,
50,
1.0,
12.0,
"The body is soft and rubbery. When angered, it will suck in air and inflate itself to an enormous size.",
140,70,45,85,50,45,
.abilities = {CUTE_CHARM, COMPETITIVE},
};

species zubat = {
"Zubat",
"Bat Pokémon",
41,
POISON,
FLYING,
false,
0.5,
255,
0.8,
7.5,
"Forms colonies in perpetually dark places. Uses ultrasonic waves to identify and approach targets.",
40,45,35,30,40,55,
42,22,
.abilities = {INNER_FOCUS},
};

species golbat = {
"Golbat",
"Bat Pokémon",
42,
POISON,
FLYING,
false,
0.5,
90,
1.6,
55.0,
"Once it strikes, it will not stop draining energy from the victim even if it gets too heavy to fly.",
75,80,70,65,75,90,
.abilities = {INNER_FOCUS},
};

species oddish = {
"Oddish",
"Weed Pokémon",
43,
GRASS,
POISON,
false,
0.5,
255,
0.5,
5.4,
"During the day, it keeps its face buried in the ground. At night, it wanders around sowing its seeds.",
45,50,55,75,65,30,
44,21,
.abilities = {CHLOROPHYLL},
};

species gloom = {
"Gloom",
"Weed Pokémon",
44,
GRASS,
POISON,
false,
0.5,
120,
0.8,
8.6,
"The fluid that oozes from its mouth isn't drool. It is a nectar that is used to attract prey.",
60,65,70,85,75,40,
.abilities = {CHLOROPHYLL},
};

species vileplume = {
"Vileplume",
"Flower Pokémon",
45,
GRASS,
POISON,
false,
0.5,
45,
1.2,
18.6,
"The larger its petals, the more toxic pollen it contains. Its big head is heavy and hard to hold up.",
75,80,85,110,90,50,
.abilities = {CHLOROPHYLL},
};

species paras = {
"Paras",
"Mushroom Pokémon",
46,
BUG,
GRASS,
false,
0.5,
190,
0.3,
5.4,
"Burrows to suck tree roots. The mushrooms on its back grow by drawing nutrients from the bug host.",
35,70,55,45,55,25,
47,24,
.abilities = {EFFECT_SPORE, DRY_SKIN},
};

species parasect = {
"Parasect",
"Mushroom Pokémon",
47,
BUG,
GRASS,
false,
0.5,
75,
1.0,
29.5,
"A host-parasite pair in which the parasite mushroom has taken over the host bug. Prefers damp places.",
60,95,80,60,80,30,
.abilities = {EFFECT_SPORE, DRY_SKIN},
};

species venonat = {
"Venonat",
"Insect Pokémon",
48,
BUG,POISON,
false,
0.5,
190,
1.0,
30.0,
"Lives in the shadows of tall trees where it eats insects. It is attracted by light at night.",
60,55,50,40,55,45,
49,31,
.abilities = {COMPOUND_EYES, TINTED_LENS},
};

species venomoth = {
"Venomoth",
"Poison Moth Pokémon",
49,
BUG,
POISON,
false,
0.5,
75,
1.5,
12.5,
"The dust-like scales covering its wings are color coded to indicate the kinds of poison it has.",
70,65,60,90,75,90,
.abilities = {SHIELD_DUST, TINTED_LENS},
};

species diglett = {
"Diglett",
"Mole Pokémon",
50,
GROUND,
NONE,
false,
0.5,
255,
0.2,
0.8,
"Lives about one yard underground where it feeds on plant roots. It sometimes appears above ground.",
10,55,25,35,45,95,
51, 26,
.abilities = {SAND_VEIL, ARENA_TRAP},
};

species dugtrio = {
"Dugtrio",
"Mole Pokémon",
51,
GROUND,
NONE,
false,
0.5,
50,
0.7,
33.3,
"A team of Diglett triplets. It triggers huge earthquakes by burrowing 60 miles underground.",
35,80,50,50,70,120,
.abilities = {SAND_VEIL, ARENA_TRAP},
};

species meowth = {
"Meowth",
"Scratch Cat Pokémon",
52,
NORMAL,
NONE,
false,
0.5,
255,
0.4,
4.2,
"Adores circular objects. Wanders the streets on a nightly basis to look for dropped loose change. ",
40,45,35,40,40,90,
53,28,
.abilities = {PICKUP, TECHNICIAN},
};

species persian = {
"Persian",
"Classy Cat Pokémon",
53,
NORMAL,
NONE,
false,
0.5,
90,
1.0,
32.0,
"Although its fur has many admirers, it is tough to raise as a pet because of its fickle meanness.",
65,70,60,65,115,
.abilities = {LIMBER, TECHNICIAN},
};

species psyduck = {
"Psyduck",
"Duck Pokémon",
54,
WATER,
NONE,
false,
0.5,
190,
0.8,
19.6,
"While lulling its enemies with its vacant look, this wily Pokémon will use psychokinetic powers.",
50,52,48,65,50,55,
55,33,
.abilities = {DAMP, CLOUD_NINE},
};

species golduck = {
"Golduck",
"Duck Pokémon",
55,
WATER,
NONE,
false,
0.5,
75,
1.7,
76.6,
"Often seen swimming elegantly by lake shores. It is often mistaken for the Japanese monster, Kappa.",
80,82,78,95,80,85,
.abilities = {DAMP, CLOUD_NINE},
};

species mankey = {
"Mankey",
"Pig Monkey Pokémon",
56,
FIGHTING,
NONE,
false,
0.5,
190,
0.5,
28.0,
"Extremely quick to anger. It could be docile one moment then thrashing away the next instant.",
40,80,35,35,45,70,
57,28,
.abilities = {VITAL_SPIRIT, ANGER_POINT},
};

species primeape = {
"Primeape",
"Pig Monkey Pokémon",
57,
FIGHTING,
NONE,
false,
0.5,
75,
1.0,
32.0,
"Always furious and tenacious to boot. It will not abandon chasing its quarry until it is caught.",
65,105,60,60,70,95,
.abilities = {VITAL_SPIRIT, ANGER_POINT},
};

species growlithe = {
"Growlithe",
"Puppy Pokémon",
58,
FIRE,
NONE,
false,
0.75,
190,
0.7,
19.0,
"Very protective of its territory. It will bark and bite to repel intruders from its space.",
55,70,45,70,50,60,
59,
.abilities = {INTIMIDATE, FLASH_FIRE},
};

species arcanine = {
"Arcanine",
"Legendary Pokémon",
59,
FIRE,
NONE,
false,
0.75,
75,
1.9,
155.0,
"A Pokémon that has been admired since the past for its beauty. It runs agilely as if on wings.",
95,110,80,100,80,95,
.abilities = {INTIMIDATE, FLASH_FIRE},
};

species poliwag = {
"Arcanine",
"Tadpole Pokémon",
60,
WATER,
NONE,
false,
0.5,
255,
0.6,
12.4,
"Its newly grown legs prevent it from running. It appears to prefer swimming than trying to stand.",
40,50,40,40,40,90,
61, 25,
.abilities = {WATER_ABSORB, DAMP},
};

species poliwhirl = {
"Poliwhirl",
"Tadpole Pokémon",
61,
WATER,
NONE,
false,
0.5,
120,
1.0,
20.0,
"Capable of living in or out of water. When out of water, it sweats to keep its body slimy.",
65,65,65,50,50,90,
.abilities = {WATER_ABSORB, DAMP},
};

species poliwrath = {
"Poliwrath",
"Tadpole Pokémon",
62,
WATER,
FIGHTING,
false,
0.5,
45,
1.3,
54.0,
"An adept swimmer at both the front crawl and breast stroke. Easily overtakes the best human swimmers.",
90,95,95,70,90,70,
.abilities = {WATER_ABSORB, DAMP},
};

species abra = {
"Abra",
"Psi Pokémon",
63,
PSYCHIC,
NONE,
false,
0.75,
200,
0.9,
19.5,
"Using its ability to read minds, it will identify impending danger and Teleport to safety.",
25,20,15,105,55,90,
64, 16,
.abilities = {SYNCRONIZE, INNER_FOCUS},
};

species kadabra = {
"Kadabra",
"Psi Pokémon",
64,
PSYCHIC,
NONE,
false,
0.75,
100,
1.3,
56.5,
"It emits special alpha waves from its body that induce headaches just by being close by.",
40,35,30,120,70,105,
65,
.abilities = {SYNCRONIZE, INNER_FOCUS},
};

species alakazam = {
"Alakazam",
"Psi Pokémon",
65,
PSYCHIC,
NONE,
false,
0.75,
50,
1.5,
48.0,
"Its brain can outperform a super-computer. Its intelligence quotient is said to be 5,000.",
55,50,45,135,95,120,
.abilities = {SYNCRONIZE, INNER_FOCUS},
};

species machop = {
"Machop",
"Superpower Pokémon",
66,
FIGHTING,
NONE,
false,
0.75,
180,
0.8,
19.5,
"Loves to build its muscles. It trains in all styles of martial arts to become even stronger.",
70,80,50,35,35,35,
67,28,
.abilities = {GUTS, NO_GUARD},
};

species machoke = {
"Machoke",
"Superpower Pokémon",
67,
FIGHTING,
NONE,
false,
0.75,
90,
1.5,
70.5,
"Its muscular body is so powerful, it must wear a power save belt to be able to regulate its motions.",
80,100,70,50,60,45,
68,
.abilities = {GUTS, NO_GUARD},
};

species machamp = {
"Machamp",
"Superpower Pokémon",
68,
FIGHTING,
NONE,
false,
0.75,
45,
1.6,130.0,
"Using its heavy muscles, it throws powerful punches that can send the victim clear over the horizon.",
90,130,80,65,85,55,
.abilities = {GUTS, NO_GUARD},
};

species bellsprout = {
"Bellsprout",
"Flower Pokémon",
69,
GRASS,
POISON,
false,
0.5,
255,
0.7,
4.0,
"A carnivorous Pokémon that traps and eats bugs. It uses its root feet to soak up needed moisture.",
50,75,35,70,30,40,
70,21,
.abilities = {CHLOROPHYLL},
};

species weepinbell = {
"Weepinbell",
"Flycatcher Pokémon",
70,
GRASS,
POISON,
false,
0.5,
120,
1.0,
6.4,
"It spits out PoisonPowder to immobilize the enemy and then finishes it with a spray of Acid.",
65,90,50,85,45,55,
71,
.abilities = {CHLOROPHYLL},
};

species victreebel = {
"Victreebel",
"Flycatcher Pokémon",
71,
GRASS,
POISON,
false,
0.5,
45,
1.7,
15.5,
"Said to live in huge colonies deep in jungles, although no one has ever returned from there.",
80,105,65,100,60,70,
.abilities = {CHLOROPHYLL},
};

species tentacool = {
"Tentacool",
"Jellyfish Pokémon",
72,
WATER,
POISON,
false,
0.5,
190,
0.9,
45.5,
"Drifts in shallow seas. Anglers who hook them by accident are often punished by its stinging acid.",
40,40,35,50,100,70,
.abilities = {CLEAR_BODY, LIQUID_OOZE},
};

species tentacruel = {
"Tentacruel",
"Jellyfish Pokémon",
73,
WATER,
POISON,
false,
0.5,
60,
1.6,
55.0,
"The tentacles are normally kept short. On hunts, they are extended to ensnare and immobilize prey.",
80,70,65,80,120,100,
.abilities = {CLEAR_BODY, LIQUID_OOZE},
};

species geodude = {
"Geodude",
"Rock Pokémon",
74,
ROCK,
GROUND,
false,
0.5,
255,
0.4,
20.0,
"Found in fields and mountains. Mistaking them for boulders, people often step or trip on them.",
40,80,100,30,30,20,
75, 25,
.abilities = {ROCK_HEAD, STURDY},
};

species graveler = {
"Graveler",
"Rock Pokémon",
75,
ROCK,
GROUND,
false,
0.5,
120,
1.0,
105.0,
"Rolls down slopes to move. It rolls over any obstacle without slowing or changing its direction.",
55,95,115,45,45,35,
76,
.abilities = {ROCK_HEAD, STURDY},
};

species golem = {
"Golem",
"Megaton Pokémon",
76,
ROCK,
GROUND,
false,
0.5,
45,
1.4,
300.0,
"Its boulder-like body is extremely hard. It can easily withstand dynamite blasts without damage.",
80,120,130,55,65,45,
.abilities = {ROCK_HEAD, STURDY},
};

species ponyta = {
"Ponyta",
"Fire Horse Pokémon",
77,
FIRE,
NONE,
false,
0.5,
190,
1.0,
30.0,
"Its hooves are 10 times harder than diamonds. It can trample anything completely flat in little time.",
50,85,55,65,65,90,
78, 40,
.abilities = {RUN_AWAY, FLASH_FIRE},
};

species rapidash = {
"Rapidash",
"Fire Horse Pokémon",
78,
FIRE,
NONE,
false,
0.5,
60,
1.7,
95.0,
"Very competitive, this Pokémon will chase anything that moves fast in the hopes of racing it.",
65,100,70,80,80,105,
.abilities = {RUN_AWAY, FLASH_FIRE},
};

species slowpoke = {
"Slowpoke",
"Dopey Pokémon",
79,
WATER,
PSYCHIC,
false,
0.5,
190,
1.2,
36.0,
"Incredibly slow and dopey. It takes 5 seconds for it to feel pain when under attack.",
90,65,65,40,40,15,
80,37,
.abilities = {OBLIVIOUS, OWN_TEMPO},
};

species slowbro = {
"Slowbro",
"Hermit Crab Pokémon",
80,
WATER,
PSYCHIC,
false,
0.5,
75,
1.6,
78.5,
"The Shellder that is latched onto Slowpoke's tail is said to feed on the host's left over scraps.",
95,75,110,100,80,30,
.abilities = {OBLIVIOUS, OWN_TEMPO},
};

species magnemite = {
"Magnemite",
"Magnet Pokémon",
81,
ELECTRIC,
STEEL,
true,
0.0,
190,
0.3,
6.0,
"Uses anti-gravity to stay suspended. Appears without warning and uses Thunder Wave and similar moves.",
25,35,70,95,55,45,
82,30,
.abilities = {MAGNET_PULL, STURDY},
};

species magneton = {
"Magneton",
"Magnet Pokémon",
82,
ELECTRIC,
STEEL,
true,
0.0,
60,
1.0,
60.0,
"Formed by several Magnemites linked together. They frequently appear when sunspots flare up.",
50,60,95,120,70,70,
.abilities = {MAGNET_PULL, STURDY},
};

species farfetchd = {
"Farfetch'd",
"Wild Duck Pokémon",
83,
NORMAL,
FLYING,
false,
0.5,
45,
0.8,
15.0,
"The sprig of green onions it holds is its weapon. It is used much like a metal sword.",
52,65,55,58,62,60,
.abilities = {KEEN_EYES, INNER_FOCUS},
};

species doduo = {
"Doduo",
"Twin Bird Pokémon",
84,
NORMAL,FLYING,
false,
0.5,
190,
1.4,
39.2,
"A bird that makes up for its poor flying with its fast foot speed. Leaves giant footprints.",
35,85,45,35,35,75,
85,31,
.abilities = {RUN_AWAY, EARLY_BIRD},
};

species dodrio = {
"Dodrio",
"Triple Bird Pokémon",
85,
NORMAL,
FLYING,
false,
0.5,
45,
1.8,
85.2,
"Uses its three brains to execute complex plans. While two heads sleep, one head stays awake.",
60,110,70,60,60,110,
.abilities = {RUN_AWAY, EARLY_BIRD},
};

species seel = {
"Seel",
"Sea Lion Pokémon",
86,
WATER,
NONE,
false,
0.5,
190,
1.1,
90.0,
"The protruding horn on its head is very hard. It is used for bashing through thick ice.",
65,45,55,45,70,45,
87, 34,
.abilities = {THICK_FAT, HYDRATION},
};

species dewgong = {
"Dewgong",
"Sea Lion Pokémon",
87,
WATER,
ICE,
false,
0.5,
75,
1.7,
120.0,
"Stores thermal energy in its body. Swims at a steady 8 knots even in intensely cold waters.",
90,70,80,70,95,70,
.abilities = {THICK_FAT, HYDRATION},
};

species grimer = {
"Grimer",
"Sludge Pokémon",
88,
POISON,
NONE,
false,
0.5,
190,
0.9,
30.0,
"Appears in filthy areas. Thrives by sucking up polluted sludge that is pumped out of factories.",
80,80,50,40,50,25,
89,38,
.abilities = {STENCH, STICKY_HOLD},
};

species muk = {
"Muk",
"Sludge Pokémon",
89,
POISON,
NONE,
false,
0.5,
75,
1.2,
30.0,
"Thickly covered with a filthy, vile sludge. It is so toxic, even its footprints contain poison.",
105,105,75,65,100,50,
.abilities = {STENCH, STICKY_HOLD},
};

species shellder = {
"Shellder",
"Bivalve Pokémon",
90,
WATER,
NONE,
false,
0.5,190,
0.3,4.0,
"Its hard shell repels any kind of attack. It is vulnerable only when its shell is open.",
30,65,100,45,25,40,
91,
.abilities = {SHELL_ARMOR, SKILL_LINK},
};

species cloyster = {
"Cloyster",
"Bivalve Pokémon",
91,
WATER,
ICE,
false,
0.5,
60,
1.5,
132.5,
"When attacked, it launches its horns in quick volleys. Its innards have never been seen.",
50,95,180,85,45,70,
.abilities = {SHELL_ARMOR, SKILL_LINK},
};

species gastly = {
"Gastly",
"Gas Pokémon",
92,
GHOST,
POISON,
false,
0.5,
190,
1.3,
0.1,
"Almost invisible, this gaseous Pokémon cloaks the target and puts it to sleep without notice.",
30,35,30,100,35,80,
93,25,
.abilities = {LEVITATE},
};

species haunter = {
"Haunter",
"Gas Pokémon",
93,
GHOST,
POISON,
false,
0.5,
90,
1.6,
0.1,
"Because of its ability to slip through block walls, it is said to be from another dimension.",
45,50,45,115,55,95,
94,
.abilities = {LEVITATE},
};

species gengar = {
"Gengar",
"Shadow Pokémon",
94,
GHOST,
POISON,
false,
0.5,
45,
1.5,
40.5,
"Under a full moon, this Pokémon likes to mimic the shadows of people and laugh at their fright.",
60,65,60,130,75,110,
.abilities = {CURSED_BODY},
};

species onix = {
"Onix",
"Rock Snake Pokémon",
95,
ROCK,
GROUND,
false,
0.5,
45,
8.8,
210.0,
"As it grows, the stone portions of its body harden to become similar to a diamond, but colored black.",
35,45,160,30,45,70,
96,
.abilities = {ROCK_HEAD, STURDY},
};

species drowzee = {
"Drowzee",
"Hypnosis Pokémon",
96,
PSYCHIC,
NONE,
false,
0.5,
190,
1.0,
32.4,
"Puts enemies to sleep then eats their dreams. Occasionally gets sick from eating bad dreams.",
60,48,45,43,90,42,
97,26,
.abilities = {INSOMNIA, FOREWARN},
};

species hypno = {
"Hypno",
"Hypnosis Pokémon",
97,
PSYCHIC,
NONE,
false,
0.5,
75,
1.6,
75.6,
"When it locks eyes with an enemy, it will use a mix of PSI moves such as Hypnosis and Confusion.",
85,73,70,73,115,67,
.abilities = {INSOMNIA, FOREWARN},
};

species krabby = {
"Krabby",
"River Crab Pokémon",
98,
WATER,
NONE,
false,
0.5,
225,
0.4,
6.5,
"Its pincers are not only powerful weapons, they are used for balance when walking sideways.",
30,105,90,25,25,50,
99,28,
.abilities = {HYPER_CUTTER, SHELL_ARMOR},
};

species kingler = {
"Kingler",
"Pincer Pokémon",
99,
WATER,
NONE,
false,
0.5,
60,
1.3,
60.0,
"The large pincer has 10000 hp of crushing power. However, its huge size makes it unwieldy to use.",
55,130,115,50,50,75,
.abilities = {HYPER_CUTTER, SHELL_ARMOR},
};

species voltorb = {
"Voltorb",
"Ball Pokémon",
100,
ELECTRIC,
NONE,
true,
0.0,
190,
0.5,
10.4,
"Usually found in power plants. Easily mistaken for a Poké Ball, they have zapped many people.",
40,30,50,55,55,100,
101,30,
.abilities = {SOUNDPROOF, STATIC},
};
