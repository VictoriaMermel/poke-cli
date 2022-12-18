/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef DAMAGE_H_
#define DAMAGE_H_
#include <stdbool.h>
#include "types.h"

float damageCalc(unsigned char level, unsigned char power,
unsigned short atk, unsigned short def, bool multitarget,
mon_type atk_type, mon_type pokemon_type[2], mon_type def_type[2]);

void print_crit(void);

int random_num(unsigned int lowest, unsigned int highest);

#endif // DAMAGE_H_
