#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char mon_type;

// Macro definitions

#define NORMAL 0
#define FIGHTING 1
#define FLYING 2
#define POISON 3
#define GROUND 4
#define ROCK 5
#define BUG 6
#define GHOST 7
#define STEEL 8
#define FIRE 9
#define WATER 10
#define GRASS 11
#define ELECTRIC 12
#define PSYCHIC 13
#define ICE 14
#define DRAGON 15
#define DARK 16
#define FAIRY 17
#define SHADOW 18
#define NONE 19

#define SPE 2.0
#define NVE 0.5
#define NRM 1.0
#define NEF 0.0

float effectiveness(mon_type atk_type, mon_type* def_type);

typedef struct pokemon pokemon;
void print_effectiveness(pokemon* pokemon);

#endif // TYPES_H_
