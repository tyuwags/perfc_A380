#include "../include/force.h"
#include "../include/utils.h"

#include <stdio.h>

#define NUM_UNITS 2

double force(double force_in, char* unit_in, char* unit_out) {

    const char *unit_names[NUM_UNITS] = {"lbf", "N"};

    double conversion_factors[NUM_UNITS][NUM_UNITS] = {
        {1,                     4.448222000000000},
        {0.224808923655339,     1},
    };

    int from_idx = get_unit_index(unit_in, NUM_UNITS, unit_names);
    int to_idx = get_unit_index(unit_out, NUM_UNITS, unit_names);

    if (from_idx == -1 || to_idx == -1) {
        printf("Unknown unit\n");
        return -1;
    }

    return force_in * conversion_factors[from_idx][to_idx];
}




