#include <check.h>
#include "../include/mass.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <math.h>


START_TEST(test_lbm_to_kg) {
    double tol = pow(10, -3);
    double value_in_lbm = 10000.0;
    double value_in_kg = mass(value_in_lbm, "lbm", "kg");
    double convert_back = mass(value_in_kg, "kg", "lbm");
    ck_assert_double_eq_tol(value_in_lbm, convert_back, tol);
}

START_TEST(test_lbm_to_slug) {
    double tol = pow(10, -3);
    double value_in_lbm = 10000.0;
    double value_in_slug = mass(value_in_lbm, "lbm", "slug");
    double convert_back = mass(value_in_slug, "slug", "lbm");
    ck_assert_double_eq_tol(value_in_lbm, convert_back, tol);
}

START_TEST(test_kg_to_slug) {
    double tol = pow(10, -3);
    double value_in_kg = 10000.0;
    double value_in_slug = mass(value_in_kg, "kg", "slug");
    double convert_back = mass(value_in_slug, "slug", "kg");
    ck_assert_double_eq_tol(value_in_kg, convert_back, tol);
}


Suite* convert_suite(void) {
    Suite *s;
    TCase *tc_lbm_to_kg;
    TCase *tc_lbm_to_slug;

    TCase *tc_kg_to_slug;

    s = suite_create("Mass");

    /* lbm to kg test case */
    tc_lbm_to_kg = tcase_create("lbm to kg");
    tcase_add_test(tc_lbm_to_kg, test_lbm_to_kg);
    suite_add_tcase(s, tc_lbm_to_kg);

    /* lbm to slug test case */
    tc_lbm_to_slug = tcase_create("lbm to slug");
    tcase_add_test(tc_lbm_to_slug, test_lbm_to_slug);
    suite_add_tcase(s, tc_lbm_to_slug);

    /* kg to slug test case */
    tc_kg_to_slug = tcase_create("kg to slug");
    tcase_add_test(tc_kg_to_slug, test_kg_to_slug);
    suite_add_tcase(s, tc_kg_to_slug);

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
