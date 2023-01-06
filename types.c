/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "types.h"
#include "pokemon.h"
#include <stdio.h>

#ifdef NT
#include <windows.h>
#else
#include <unistd.h>
#endif

float effective_mult;

float effectiveness(mon_type atk_type, mon_type* def_type) {

    float type1;
    float type2;

    static const float effectiveness_table[19][19] = {
//   nrm fgt fly poi gnd rck bug gst ste fir wat grs ele psy ice drg drk fry sha
    {NRM,NRM,NRM,NRM,NRM,NVE,NRM,NEF,NVE,NRM,NRM,NRM,NRM,NRM,NRM,NRM,NRM,NRM}, // Normal
    {SPE,NRM,NVE,NVE,NRM,SPE,NVE,NEF,SPE,NRM,NRM,NRM,NRM,NVE,SPE,NRM,SPE,NVE}, // Fighting
    {NRM,SPE,NVE,NRM,NRM,NVE,SPE,NRM,NVE,NRM,NRM,SPE,NVE,NRM,NRM,NRM,NRM,NRM}, // Flying
    {NRM,NRM,NRM,NVE,NVE,NVE,NRM,NVE,NEF,NRM,NRM,SPE,NRM,NVE,NRM,NRM,NRM,SPE}, // Poison
    {NRM,NRM,NEF,SPE,NRM,SPE,NVE,NRM,SPE,SPE,NRM,NVE,SPE,NRM,NRM,NRM,NRM,NRM}, // Ground
    {NRM,NVE,SPE,NRM,NVE,NRM,SPE,NRM,NVE,SPE,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NRM}, // Rock
    {NRM,NVE,NVE,NVE,NRM,NRM,NRM,NVE,NVE,NVE,NRM,SPE,NRM,SPE,NRM,NRM,SPE,NVE}, // Bug
    {NEF,NRM,NRM,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NVE,NRM}, // Ghost
    {NRM,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NVE,NVE,NVE,NRM,NVE,NRM,SPE,NRM,NRM,SPE}, // Steel
    {NRM,NRM,NRM,NRM,NRM,NVE,SPE,NRM,SPE,NVE,NVE,SPE,NRM,NRM,SPE,NVE,NRM,NRM}, // Fire
    {NRM,NRM,NRM,NRM,SPE,SPE,NRM,NRM,NRM,SPE,NVE,NVE,NRM,NRM,NRM,NVE,NRM,NRM}, // Water
    {NRM,NRM,NVE,NVE,SPE,SPE,NVE,NRM,NVE,NVE,SPE,NVE,NRM,NRM,NRM,NVE,NRM,NRM}, // Grass
    {NRM,NRM,SPE,NRM,NEF,NRM,NRM,NRM,NRM,NRM,SPE,NVE,NVE,NRM,NRM,NVE,NRM,NRM}, // Electric
    {NRM,SPE,NRM,SPE,NRM,NRM,NRM,NRM,NVE,NRM,NRM,NRM,NRM,NVE,NRM,NRM,NEF,NRM}, // Psychic
    {NRM,NRM,SPE,NRM,SPE,NRM,NRM,NRM,NVE,NVE,NVE,SPE,NRM,NRM,NVE,SPE,NRM,NRM}, // Ice
    {NRM,NRM,NRM,NRM,NRM,NRM,NRM,NRM,NVE,NRM,NRM,NRM,NRM,NRM,NRM,SPE,NRM,NEF}, // Dragon
    {NRM,NVE,NRM,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NRM,NRM,NRM,SPE,NRM,NRM,NVE,NVE}, // Dark
    {NRM,SPE,NRM,NVE,NRM,NRM,NRM,NVE,NVE,NRM,NRM,NRM,NRM,NRM,NRM,SPE,SPE,NRM} // Fairy
};

    type1 = effectiveness_table[atk_type][def_type[0]];
    if(def_type[1] != NONE) {
        type2 = effectiveness_table[atk_type][def_type[1]];
    }
    else {
        type2 = 1;
    }
    float total = type1 * type2;
    effective_mult = total;
    return total;
}

void print_effectiveness(pokemon* pokemon) {
    #ifdef DEBUG
    printf("Effectiveness: X%f\n", effective_mult);
    #endif

    if(effective_mult >= SPE) {
        printf("Its Super Effective\n");
        sleep(1);
    }
    else if (effective_mult < NRM && effective_mult > NEF) {
        printf("Its Not Very Effective\n");
        sleep(1);
    }
    else if (effective_mult == NEF) {
        printf("It doesn't affect %s\n", pokemon->nickname);
        sleep(2);
    }
}
