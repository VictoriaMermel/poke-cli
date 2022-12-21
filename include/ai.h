/* Command Line Pokemon Battle Game
**
** Copyright © 2022 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef AI_H_
#define AI_H_

typedef struct pokemon pokemon;
struct battle_state;
void ai_faint(struct battle_state* state);

int move_selection(pokemon* pokemon, int skill);

#endif // AI_H_
