#ifndef MOVES_H_
#define MOVES_H_
#include "types.h"
#include <stdbool.h>

#define STATUS 0
#define SPECIAL 1
#define PHYSICAL 2

typedef struct move {
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

void make_move(struct battle_state* state, move* move, bool player);

#endif // MOVES_H_
