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
#define TACKLE 33

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
    signed char stat_change;
} move;

struct battle_state;

move* getMoves(void);

#endif // MOVES_H_
