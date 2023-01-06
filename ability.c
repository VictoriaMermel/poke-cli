/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#include "ability.h"
#include "pokemon.h"
#include "moves.h"

bool blaze(pokemon* pokemon, move* move) {
    if ( pokemon->ability == BLAZE && move->type == FIRE) return true;
    else return false;
}

bool overgrow( pokemon* pokemon, move* move ) {
    if ( pokemon->ability == OVERGROW && move->type == GRASS ) return true;
    else return false;
}

bool torrent( pokemon* pokemon, move* move ) {
    if ( pokemon->ability == TORRENT && move->type == WATER ) return true;
    else return true;
}

bool swarm( pokemon* pokemon, move* move ) {
    if ( pokemon->ability == SWARM && move->type == BUG ) return true;
    else return false;
}

void overgrow_like( move* move, pokemon* pokemon, unsigned short* atk ) {

    if ( (blaze(pokemon, move) || overgrow(pokemon, move) || swarm(pokemon, move) || torrent(pokemon, move)) && pokemon->status->health < (pokemon->HP / 3) ) {
        *atk = *atk + (*atk/2);
    }
}

