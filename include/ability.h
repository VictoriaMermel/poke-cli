/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef ABILITY_H_
#define ABILITY_H_

typedef unsigned int ability;

#define OVERGROW 1
#define TORRENT 2
#define BLAZE 3
#define SWARM 4
#define SHIELD_DUST 5
#define SHED_SKIN 6
#define COMPOUND_EYES 7
#define KEEN_EYES 8
#define TANGLED_FEET 9
#define RUN_AWAY 10
#define GUTS 11
#define INTIMIDATE 12
#define STATIC 13
#define SAND_VEIL 14
#define POISON_POINT 15
#define RIVALRY 16
#define MAGIC_GUARD 17
#define FLASH_FIRE 18
#define CUTE_CHARM 19
#define COMPETITIVE 20
#define INNER_FOCUS 21
#define CHLOROPHYLL 22
#define EFFECT_SPORE 23
#define DRY_SKIN 24
#define TINTED_LENS 25
#define ARENA_TRAP 26
#define PICKUP 27
#define TECHNICIAN 28
#define LIMBER 29
#define DAMP 30
#define CLOUD_NINE 31
#define VITAL_SPIRIT 32
#define ANGER_POINT 33
#define WATER_ABSORB 34
#define SYNCRONIZE 35
#define NO_GUARD 36
#define CLEAR_BODY 37
#define LIQUID_OOZE 38
#define ROCK_HEAD 39
#define STURDY 40
#define OBLIVIOUS 41
#define OWN_TEMPO 42
#define MAGNET_PULL 43
#define EARLY_BIRD 44
#define THICK_FAT 45
#define HYDRATION 46
#define STENCH 47
#define STICKY_HOLD 48
#define SHELL_ARMOR 49
#define SKILL_LINK 50
#define LEVITATE 51
#define CURSED_BODY 52
#define INSOMNIA 53
#define FOREWARN 54
#define HYPER_CUTTER 55
#define SOUNDPROOF 56

typedef struct pokemon pokemon;
typedef const struct move move;

void overgrow_like( move* move, pokemon* pokemon, unsigned short* atk );

#endif // ABILITY_H_
