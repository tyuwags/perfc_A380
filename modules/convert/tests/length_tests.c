#include <check.h>
#include "../include/length.h"
#include <math.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

START_TEST(test_length_roundtrip) {
    const char *units[] = {"ft", "m", "km", "in", "mi", "naut mi"};
    const int num_units = sizeof(units) / sizeof(units[0]);
    double tol = pow(10, -3);
    double value = 10000.0;

    for (int i = 0; i < num_units; i++) {
        for (int j = i; j < num_units; j++) {
            if (i == j) continue;

            double converted = length(value, (char *)units[i], (char *)units[j]);
            double back = length(converted, (char *)units[j], (char *)units[i]);

            ck_assert_msg(
                fabs(value - back) < tol,
                "Roundtrip failed: %.10f %s -> %s -> %s = %.10f (diff=%.10e)",
                value, units[i], units[j], units[i], back, fabs(value - back)
            );
        }
    }
}
END_TEST

Suite* convert_suite(void) {
    Suite *s = suite_create("Length");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_length_roundtrip);
    suite_add_tcase(s, tc_core);
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
