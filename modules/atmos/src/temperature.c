#include "../include/temperature.h"

#include <math.h>

double temperature(double altitude_m, double isa_dev) {
    double T0 = 288.15;
    double L = -0.0065;

    double temperature_K = T0 + L * fmin(altitude_m, 11000.0) + isa_dev;

    return temperature_K;
}
