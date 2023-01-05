/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "factory.h"
#include "pokemon.h"
#include "moves.h"
#include "ability.h"
#include <stdio.h>
#include "string.h"

pokemon* get_random_rental(void) {

    species venusaur;
    static pokemon r_venusaur = {
    .level = 60,
    .ability = OVERGROW,
};
    r_venusaur.species = &venusaur;
    strcpy(r_venusaur.nickname, venusaur.name);
    return &r_venusaur;
}

void factory_main() {
    printf("factory");
}
