#include "damage.h"
#include "types.h"
#include <stdbool.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MULTIHITDIV 0.75
#define STAB 1.25
#define CRITDAMAGE 2

int random_num(unsigned int lowest, unsigned int highest) {
    long* buf = malloc(sizeof(long));
    FILE* rand_src = fopen("/dev/urandom", "rb");
    if(rand_src) {
        fread(buf, sizeof(buf), 1, rand_src);
        srand(time(0) * *buf);
        fclose(rand_src);
    }
    else {
        srand(time(0));
    }

    free(buf);
    return rand() % (highest - lowest) + lowest;
}

bool rollcrit(void) {
    return random_num(0,15)/15;
}

float damageCalc(unsigned char level, unsigned char power,
                 unsigned short atk, unsigned short def, bool multitarget,
                 mon_type atk_type, mon_type pokemon_type[2], mon_type def_type[2]) {

    float ajusted_level = ((2*level)/5)+2;

    float damage = (((ajusted_level*power*(float)atk/(float)def)/50.0) + 2.0);

    if(multitarget) damage = damage*MULTIHITDIV;
    if(rollcrit()) damage = damage*CRITDAMAGE;

    float rand_factor = (float)random_num(85, 100)/100.0;
    damage = damage * rand_factor;
    damage = damage * effectiveness(atk_type, def_type);
    if(atk_type == pokemon_type[0] || atk_type == pokemon_type[1]) damage = damage * STAB;

    if(damage == 0 && effectiveness(atk_type, def_type) != 0) {
        return 1;
    }
    else return damage;
}
