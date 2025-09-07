#include <check.h>
#include "../include/force.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <math.h>


START_TEST(test_force) {
    double tol = pow(10, -3);
    double value_in_newtons = 10000.0;
    double value_in_lbf = force(value_in_newtons, "N", "lbf");
    double convert_back = force(value_in_lbf, "lbf", "N");
    ck_assert_double_eq_tol(value_in_newtons, convert_back, tol);
}

Suite* convert_suite(void) {
    Suite *s;
    TCase *tc_force;

    s = suite_create("Force");

    /* N to lbf test case */
    tc_force = tcase_create("N to lbf");
    tcase_add_test(tc_force, test_force);
    suite_add_tcase(s, tc_force);

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
