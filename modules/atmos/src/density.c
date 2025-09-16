#include "../include/density.h"
#include "../include/temperature.h"

#include <math.h>

double density(double altitude_m, double isa_dev) {
    double R = 287.05;             // Constante des gaz parfaits (J/kg/K)
    double rho_0 = 1.225;
    double L  = -0.0065;           // K/m (gradient dans la troposphère)
    double g  = 9.80665;           // m/s²
    
    double T0 = temperature(0.0, isa_dev);

    double T = temperature(altitude_m, isa_dev);

    double density_kgpm3 = rho_0 * pow((T/T0), (-g/(L*R)-1));

    double delta_h = fmax(0.0, altitude_m - 11000);

    density_kgpm3 = density_kgpm3 * exp(-g*delta_h / (R*T));

    return density_kgpm3;
}
