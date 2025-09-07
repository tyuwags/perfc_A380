#include "../include/mass.h"
#include "../include/utils.h"

#include <stdio.h>

#define NUM_UNITS 3


double mass(double mass_in, char* unit_in, char* unit_out) {
    
    const char *unit_names[NUM_UNITS] = {"lbm", "kg", "slug"};

    double conversion_factors[NUM_UNITS][NUM_UNITS] = {
        {1,                 0.45359237,         0.0310809502508065},
        {2.20462262184878,  1,                  0.0685217660314843},
        {32.1740484744045,  14.5939029000000,   1}
    };

    return convert(mass_in, unit_in, unit_out, NUM_UNITS, unit_names, conversion_factors); 
}
