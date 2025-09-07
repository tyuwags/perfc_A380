#include "../include/utils.h"

#include <string.h>
#include <stdio.h>

int get_unit_index(const char *unit, int num_units, const char **units) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i], unit) == 0) {
            return i;
        }
    }
    return -1; // not found 
}


double convert(double in, const char* unit_in, const char* unit_out, int num_units, const char** unit_names, double conversion_factors[num_units][num_units]) {
    int from_idx = get_unit_index(unit_in, num_units, unit_names);
    int to_idx = get_unit_index(unit_out, num_units, unit_names);
    
    if (from_idx == -1 || to_idx == -1) {
        printf("Unknown unit\n");
        return -1;
    }

    return in * conversion_factors[from_idx][to_idx];
}
