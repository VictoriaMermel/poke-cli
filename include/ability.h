/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef ABILITY_H_
#define ABILITY_H_

typedef unsigned int ability;

#define OVERGROW 1
#define TORRENT 2
#define BLAZE 3
#define SWARM 4

typedef struct pokemon pokemon;
typedef struct move move;

void overgrow_like( move* move, pokemon* pokemon, unsigned short* atk );

#endif // ABILITY_H_
