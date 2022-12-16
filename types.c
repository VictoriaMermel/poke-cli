#include "types.h"


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
    return type1 * type2;
}
