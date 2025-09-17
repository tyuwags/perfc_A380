#include "../include/speed_sound.h"
#include "../include/temperature.h"

#include <math.h>

double speed_sound(double altitude_m, double isa_dev) {
    double gamma = 1.4;
    double R = 287.05;

    double T = temperature(altitude_m, isa_dev);

    double speed_sound_mps = sqrt(gamma*R*T);

    return speed_sound_mps;
}
