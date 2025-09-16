#include "../include/pressure.h"
#include "../include/temperature.h"

#include <math.h>

double pressure(double altitude_m) {
    double P0 = 101325.0;       // Pa
    double R = 287.05;          // J/kg/K
    double g = 9.80665;         // m/s²
    double L = -0.0065;         // J/kg/K

    double T0 = temperature(0.0, 0.0);

    double T = temperature(altitude_m, 0.0);

    double pressure_Pa = P0 * pow((T/T0), (-g/(L * R)));

    double delta_h = fmax(0.0, (altitude_m - 11000.0));
    pressure_Pa = pressure_Pa * exp(-g * delta_h / (R*T));

    return pressure_Pa;
}
