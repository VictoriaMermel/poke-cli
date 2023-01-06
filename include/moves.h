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


typedef const struct move {
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

extern move tail_whip;
extern move tackle;
extern move growl;
extern move pound;
extern move vine_whip;
extern move swords_dance;
extern move splash;
extern move dbg;

#endif // MOVES_H_
