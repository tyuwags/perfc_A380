#ifndef UTILS_H
#define UTILS_H

int get_unit_index(const char*, int, const char**);
double convert(double, const char*, const char*, int num_units, const char**, double[num_units][num_units]);

#endif
