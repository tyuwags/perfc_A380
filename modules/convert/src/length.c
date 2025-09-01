#include "../include/length.h"

#include <stdio.h>
#include <string.h>

#define NUM_UNITS 6

const char *unit_names[NUM_UNITS] = {"ft", "m", "km", "in", "mi", "naut mi"};

double conversion_factors[NUM_UNITS][NUM_UNITS] = {
    //        ft          m           km          in            mi            naut mi
    {1,       0.3048,     0.0003048,  12,          0.0001893939, 0.0001645788},     // ft
    {3.28084, 1,          0.001,      39.3700787,  0.0006213712, 0.0005399568},     // m
    {3280.84, 1000,       1,          39370.0787,  0.621371192,  0.539956803},      // km
    {0.0833333,0.0254,    2.54e-5,    1,           1.5782828e-5, 1.3714903e-5},      // in
    {5280,     1609.344,  1.609344,   63360,       1,            0.8689762419},     // mi
    {6076.115, 1852,      1.852,      72913.3858,  1.15077945,   1}                 // naut mi
};

int get_unit_index(const char *unit) {
    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_names[i], unit) == 0) {
            return i;
        }
    }
    return -1; // not found
}

double length(double length_in, char* unit_in, char* unit_out) {
    int from_idx = get_unit_index(unit_in);
    int to_idx = get_unit_index(unit_out);
    
    if (from_idx == -1 || to_idx == -1) {
        printf("Unknown unit\n");
        return -1;
    }

    return length_in * conversion_factors[from_idx][to_idx];
} 
