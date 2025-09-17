#include <check.h>
#include <math.h>
#include "../include/speed_sound.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

START_TEST(test_speed_sound_values) {
    double tol = 5e-2;

    // Test at sea level (0 m)
    ck_assert_msg(
        fabs(speed_sound(0.0, 0.0) - 340.29) < tol,
        "Speed of sound at 0 m failed"
    );

    // Test at 5,100 m
    double expected_5100 = 320.14;
    double calculated_5100 = speed_sound(5100.0, 0.0);
    ck_assert_msg(
        fabs(calculated_5100 - expected_5100) < tol,
        "Speed of sound at 5100 m failed, calculated: %.10f, real: %.10f (diff=%.10f)",
        calculated_5100, expected_5100, fabs(calculated_5100 - expected_5100)
    );

    // Test at 11,100 m (end of troposphere lapse rate)
    double expected_11100 = 295.07;
    double calculated_11100 = speed_sound(11100.0, 0.0);
    ck_assert_msg(
        fabs(calculated_11100 - expected_11100) < tol,
        "Speed of sound at 11100 m failed, calculated: %.10f, real: %.10f (diff=%.10f)",
        calculated_11100, expected_11100, fabs(calculated_11100 - expected_11100)
    );

    // Test at 15,000 m
    double expected_15000 = 295.07;
    double calculated_15000 = speed_sound(15000.0, 0.0);
    ck_assert_msg(
        fabs(calculated_15000 - expected_15000) < tol,
        "Speed of sound above 15000 m failed, calculated: %.10f, real: %.10f (diff=%.10f)",
        calculated_15000, expected_15000, (calculated_15000 - expected_15000)
    );
}
END_TEST

Suite* convert_suite(void) {
    Suite *s = suite_create("Speed of Sound");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_speed_sound_values);
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

