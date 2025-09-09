#include <check.h>
#include <math.h>
#include "../include/temperature.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

START_TEST(test_temperature_values) {
    double tol = 1e-1;

    // Test at sea level (0 m)
    ck_assert_msg(
        fabs(temperature(0.0, 0.0) - 288.15) < tol,
        "Temperature at 0 m failed"
    );

    // Test at 5,100 m
    double expected_5100 = 255.04;
    ck_assert_msg(
        fabs(temperature(5100.0, 0.0) - expected_5100) < tol,
        "Temperature at 5100 m failed"
    );

    // Test at 11,100 m (end of troposphere lapse rate)
    double expected_11100 = 216.66;
    ck_assert_msg(
        fabs(temperature(11100.0, 0.0) - expected_11100) < tol,
        "Temperature at 11100 m failed"
    );

    // Test at 15,000 m (should be capped at 11,000 m lapse rate)
    ck_assert_msg(
        fabs(temperature(15000.0, 0.0) - expected_11100) < tol,
        "Temperature above 11100 m failed"
    );

    // Test with ISA deviation (+10 K at sea level)
    ck_assert_msg(
        fabs(temperature(0.0, 10.0) - (288.15 + 10.0)) < tol,
        "Temperature with ISA deviation failed"
    );
}
END_TEST

Suite* convert_suite(void) {
    Suite *s = suite_create("Temperature");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_temperature_values);
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

