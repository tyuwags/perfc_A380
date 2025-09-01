#include <check.h>
#include "../include/length.h"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <math.h>


START_TEST (test_length) {
    double tol = pow(10, -5);
    double value_in_feet = 100.0;
    double value_in_meters = length(value_in_feet, "ft", "m");
    double convert_back = length(value_in_meters, "m", "ft");
    ck_assert_double_eq_tol(value_in_feet, convert_back, tol);
}
END_TEST

Suite* length_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Length");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_length);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = length_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
