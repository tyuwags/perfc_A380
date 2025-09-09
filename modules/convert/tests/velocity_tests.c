#include <check.h>
#include "../include/velocity.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <math.h>
#include <string.h>

START_TEST(test_velocity_roundtrip) {
    double tol = pow(10, -3);

    const char *units[] = {
        "ft/s", "m/s", "km/s", "in/s", "km/h", "mph", "kts", "ft/min"
    };
    int n_units = sizeof(units) / sizeof(units[0]);

    double value = 1000.0; // base test value

    for (int i = 0; i < n_units; i++) {
        for (int j = i; j < n_units; j++) {
            if (i == j) continue; // skip same-unit

            double converted = velocity(value, (char*)units[i], (char*)units[j]);
            double back = velocity(converted, (char*)units[j], (char*)units[i]);

            ck_assert_msg(
                fabs(value - back) < tol,
                "Conversion failed: %f %s -> %s -> %s (got %f, expected %f ± %e)",
                value, units[i], units[j], units[i], back, value, tol
            );
        }
    }
}
END_TEST

Suite* convert_suite(void) {
    Suite *s;
    TCase *tc;

    s = suite_create("Velocity");

    tc = tcase_create("roundtrip conversions");
    tcase_add_test(tc, test_velocity_roundtrip);
    suite_add_tcase(s, tc);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = convert_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

