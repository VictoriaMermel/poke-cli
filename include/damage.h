#ifndef DAMAGE_H_
#define DAMAGE_H_
#include <stdbool.h>
#include "types.h"

float damageCalc(unsigned char level, unsigned char power,
unsigned short atk, unsigned short def, bool multitarget,
mon_type atk_type, mon_type pokemon_type[2], mon_type def_type[2]);

#endif // DAMAGE_H_
