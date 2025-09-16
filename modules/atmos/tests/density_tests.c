#include <check.h>
#include <math.h>
#include "../include/density.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

START_TEST(test_density_values) {
    double tol = 1e-2;

    // Test at sea level (0 m)
    ck_assert_msg(
        fabs(density(0.0, 0.0) - 1.225) < tol,
        "Density at 0 m failed"
    );

    // Test at 5,100 m
    double expected_5100 = 0.72851;
    double calculated_5100 = density(5100.0, 0.0);
    ck_assert_msg(
        fabs(calculated_5100 - expected_5100)/expected_5100 < tol,
        "Density at 5100 m failed, calculated: %.10f, real: %.10f (relative diff=%.10f)",
        calculated_5100, expected_5100, fabs(calculated_5100 - expected_5100)/expected_5100
    );

    // Test at 11,100 m (end of troposphere lapse rate)
    double expected_11100 = 0.35932;
    double calculated_11100 = density(11100.0, 0.0);
    ck_assert_msg(
        fabs(calculated_11100 - expected_11100)/expected_11100 < tol,
        "Pressure at 11100 m failed, calculated: %.10f, real: %.10f (relative diff=%.10f)",
        calculated_11100, expected_11100, fabs(calculated_11100 - expected_11100)/expected_11100
    );

    // Test at 15,000 m
    double expected_15000 = 0.19475;
    double calculated_15000 = density(15000.0, 0.0);
    ck_assert_msg(
        fabs(calculated_15000 - expected_15000)/expected_15000 < tol,
        "Density above 15000 m failed, calculated: %.10f, real: %.10f (relative diff=%.10f)",
        calculated_15000, expected_15000, (calculated_15000 - expected_15000)/expected_15000
    );
}
END_TEST

Suite* convert_suite(void) {
    Suite *s = suite_create("Density");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_density_values);
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
