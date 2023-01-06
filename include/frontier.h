/* Command Line Pokemon Battle Game
**
** Copyright © 2022, 2023 Victoria Mermel
**
** This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 */

#ifndef FACTORY_H_
#define FACTORY_H_

typedef const struct species species;
extern species venusaur;
extern species gengar;
extern species blastoise;
extern species kingler;
extern species hypno;
extern species alakazam;
extern species slowbro;
extern species rapidash;
extern species golem;
extern species tentacruel;
extern species machamp;
extern species primeape;
void factory_main();

void get_records();

#endif // FACTORY_H_
