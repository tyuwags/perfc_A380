#include "../include/length.h"
#include "../include/utils.h"

#include <stdio.h>

#define NUM_UNITS 6


double length(double length_in, char* unit_in, char* unit_out) {
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

    return convert(length_in, unit_in, unit_out, NUM_UNITS, unit_names, conversion_factors); 

} 
