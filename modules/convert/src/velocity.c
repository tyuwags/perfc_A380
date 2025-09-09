#include "../include/velocity.h"
#include "../include/utils.h"

#include <stdio.h>

#define NUM_UNITS 8

double velocity(double velocity_in, char* unit_in, char* unit_out) {
    const char *unit_names[NUM_UNITS] = {
        "ft/s", "m/s", "km/s", "in/s", "km/h", "mph", "kts", "ft/min"
    };

    double conversion_factors[NUM_UNITS][NUM_UNITS] = {
        // ft/s
        {1,       0.3048,   0.0003048, 12.0,     1.09728,    0.6818181818,   0.592484,   60.0},
        // m/s
        {3.28084, 1,        0.001,     39.3701,  3.6,        2.23694,    1.94384,    196.85},
        // km/s
        {3280.84, 1000,     1,         39370.1,  3600.0,     2236.94,    1943.84,    196850},
        // in/s
        {0.0833333,0.0254,  2.54e-5,   1,        0.09144,    0.0568182,  0.0493737,  5.0},
        // km/h
        {0.911344, 0.277778,1.0/3600,    1.0/0.09144,  1,          0.621371,   0.539957,   54.6807},
        // mph
        {1.4666666667,  1.0/2.23694, 1.0/2236.94,17.6,     1.0/0.621371,    1,          0.868976,   88.0},
        // kts
        {1.68781,  1.0/1.94384,1.0/1943.84,20.2537, 1.852,      1.15078,    1,          101.269},
        // ft/min
        {1.0/60,   1.0/196.85, 1.0/196850,   0.2,      1.0/54.6807,   1.0/88,  1.0/101.269, 1}
    };

    return convert(velocity_in, unit_in, unit_out, NUM_UNITS, unit_names, conversion_factors);
}

