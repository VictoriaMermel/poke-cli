/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef MOVES_H_
#define MOVES_H_
#include "types.h"
#include <stdbool.h>

#define STATUS 0
#define SPECIAL 1
#define PHYSICAL 2

#define POUND 1
#define KARATE_CHOP 2
#define DOUBLE_SLAP 3
#define COMET_PUNCH 4
#define MEGA_PUNCH 5
#define PAY_DAY 6
#define FIRE_PUNCH 7
#define ICE_PUNCH 8
#define THUNDER_PUNCH 9
#define SCRATCH 10
#define VISE_GRIP 11
#define GUILLOTINE 12
#define RAZER_WIND 13
#define SWORDS_DANCE 14
#define CUT 15
#define GUST 16
#define WING_ATTACK 17
#define WHIRLWIND 18
#define FLY 19
#define BIND 20
#define SLAM 21
#define VINE_WHIP 22
#define STOMP 23
#define DOUBLE_KICK 24
#define MEGA_KICK 25
#define JUMP_KICK 26
#define ROLLING_KICK 27
#define SAND_ATTACK 28
#define HEADBUTT 29
#define HORN_ATTACK 30
#define FURY_ATTACK 31
#define HORN_DRILL 32
#define TACKLE 33
#define BODY_SLAM 34
#define WRAP 35
#define TAKE_DOWN 36
#define THRASH 37
#define DOUBLE_EDGE 38
#define TAIL_WHIP 39
#define POISON_STING 40
#define TWINEEDLE 41
#define PIN_MISSILE 42
#define LEER 43
#define BITE 44
#define GROWL 45
#define ROAR 46
#define SING 47
#define SUPERSONIC 48
#define SONIC_BOOM 49
#define DISABLE 50
#define ACID 51
#define EMBER 52
#define FLAMEFLOWER 53
#define MIST 54
#define WATER_GUN 55
#define HYDRO_PUMP 56
#define SURF 57
#define ICE_BEAM 58
#define BLIZARD 59
#define PSYBEAM 60
#define BUBBLE_BEAM 61
#define AURORA_BEAM 62
#define HYPER_BEAM 63
#define PECK 64
#define DRILL_PECK 65
#define SUBMISSION 66
#define LOW_KICK 67
#define COUNTER 68
#define SEISMIC_TOSS 69
#define STRENGTH 70
#define ABSORB 71
#define MEGA_DRAIN 72
#define LEECH_SEED 73
#define GROWTH 74
#define RAZOR_LEAF 75
#define SOLAR_BEAM 76
#define POISON_POWDER 77
#define STUN_SPORE 78
#define SLEEP_POWDER 79
#define PETAL_DANCE 80
#define STRING_SHOT 81
#define DRAGON_RAGE 82
#define FIRE_SPIN 83
#define THUNDER_SHOCK 84
#define THUNDERBOLT 85
#define THUNDER_WAVE 86
#define THUNDER 87
#define ROCK_THROW 88
#define EARTHQUAKE 89
#define FISSURE 90
#define DIG 91
#define TOXIC 92
#define CONFUSION 93
#define PSYCHIC_M 94
#define HYPNOSIS 95
#define MEDIDATE 96
#define AGILITY 97
#define QUICK_ATTACK 98
#define RAGE 99
#define TELEPORT 100
#define NIGHT_SHADE 101
#define MIMIC 102
#define SCREETCH 103
#define DOUBLE_TEAM 104
#define RECOVER 105
#define HARDEN 106
#define MINIMIZE 107
#define SMOKESCREEN 108
#define CONFUSE_RAY 109
#define WITHDRAW 110
#define DEFENSE_CURL 111
#define BARRIER 112
#define LIGHT_SCREEN 113
#define HAZE 114
#define REFLECT 115
#define FOCUS_ENERGY 116
#define BIDE 117
#define METRONOME 118
#define MIRROR_MOVE 119
#define SELF_DESTRUCT 120
#define EGG_BOMB 121
#define LICK 122
#define SMOG 123
#define SLUDGE 124
#define BONE_CLUB 125
#define FIRE_BLAST 126
#define WATERFALL 127
#define CLAMP 128
#define SWIFT 129
#define SKULL_BASH 130
#define SPIKE_CANNON 131
#define CONSTRICT 132
#define AMNESIA 133
#define KINESIS 134
#define SOFT_BOILED 135
#define HIGH_JUMP_KICK 136
#define GLARE 137
#define DREAM_EATER 138
#define POISON_GAS 139
#define BARRAGE 140
#define LEECH_LIFE 141
#define LOVELY_KISS 142
#define SKY_ATTACK 143
#define TRANSFORM 144
#define BUBBLE 145
#define DIZZY_PUNCH 146
#define SPORE 147
#define FLASH 148
#define PSYWAVE 149
#define SPLASH 150
#define ACID_ARMOR 151
#define CRAB_HAMMER 152
#define EXPLOSION 153
#define FURY_SWEEPS 154
#define BONEMERANG 155
#define REST 156
#define ROCK_SLIDE 157
#define HYPER_FANG 158
#define SHARPEN 159
#define CONVERSION 160
#define TRI_ATTACK 161
#define SUPER_FANG 162
#define SLASH 163
#define SUBSTITUTE 164
#define STRUGGLE 165

typedef struct move {
    char name[64];
    void* func;
    mon_type type;
    unsigned char category;
    unsigned char PP;
    unsigned char Power;
    unsigned char Accuracy;
    bool contact;
    bool affected_by_protect;
    bool affected_by_magic_coat;
    bool affected_by_snatch;
    bool affected_by_mirror_move;
    signed char atk_change;
    signed char opponent_atk_change;
    signed char def_change;
    signed char opponent_def_change;
    signed char spa_change;
    signed char opponent_spa_change;
    signed char spd_change;
    signed char opponent_spd_change;
    signed char spe_change;
    signed char opponent_spe_change;
} move;

struct battle_state;

move** getMoves(void);

#endif // MOVES_H_
