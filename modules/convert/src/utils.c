#include "../include/utils.h"

#include <string.h>

int get_unit_index(const char *unit, int num_units, const char **units) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i], unit) == 0) {
            return i;
        }
    }
    return -1; // not found 
}
