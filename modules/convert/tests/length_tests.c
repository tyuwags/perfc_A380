#include <check.h>
#include "../include/length.h"
#include "../include/force.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <math.h>


START_TEST (test_ft_to_m) {
    double tol = pow(10, -3);
    double value_in_feet = 10000.0;
    double value_in_meters = length(value_in_feet, "ft", "m");
    double convert_back = length(value_in_meters, "m", "ft");
    ck_assert_double_eq_tol(value_in_feet, convert_back, tol);
}
END_TEST

START_TEST(test_ft_to_km) {
    double tol = pow(10, -3);
    double value_in_ft = 10000.0;
    double value_in_km = length(value_in_ft, "ft", "km");
    double convert_back = length(value_in_km, "km", "ft");
    ck_assert_double_eq_tol(value_in_ft, convert_back, tol);
}

START_TEST (test_ft_to_in) {
    double tol = pow(10, -3);
    double value_in_feet = 1000.0;
    double value_in_inches = length(value_in_feet, "ft", "in");
    double convert_back = length(value_in_inches, "in", "ft");
    ck_assert_double_eq_tol(value_in_feet, convert_back, tol);
}
END_TEST

START_TEST(test_ft_to_mi) {
    double tol = pow(10, -3);
    double value_in_ft = 10000.0;
    double value_in_miles = length(value_in_ft, "ft", "mi");
    double convert_back = length(value_in_miles, "mi", "ft");
    ck_assert_double_eq_tol(value_in_ft, convert_back, tol);
}

START_TEST(test_ft_to_naut_mi) {
    double tol = pow(10, -3);
    double value_in_ft = 10000.0;
    double value_in_nautique_miles = length(value_in_ft, "ft", "naut mi");
    double convert_back = length(value_in_nautique_miles, "naut mi", "ft");
    ck_assert_double_eq_tol(value_in_ft, convert_back, tol);
}

START_TEST (test_m_to_km) {
    double tol = pow(10, -3);
    double value_in_meters = 10000.0;
    double value_in_km = length(value_in_meters, "m", "km");
    double convert_back = length(value_in_km, "km", "m");
    ck_assert_double_eq_tol(value_in_meters, convert_back, tol);
}
END_TEST

START_TEST(test_m_to_in) {
    double tol = pow(10, -3);
    double value_in_meters = 10000.0;
    double value_in_in = length(value_in_meters, "m", "in");
    double convert_back = length(value_in_in, "in", "m");
    ck_assert_double_eq_tol(value_in_meters, convert_back, tol);
}

START_TEST (test_m_to_mi) {
    double tol = pow(10, -3);
    double value_in_meters = 10000.0;
    double value_in_miles = length(value_in_meters, "m", "mi");
    double convert_back = length(value_in_miles, "mi", "m");
    ck_assert_double_eq_tol(value_in_meters, convert_back, tol);
}
END_TEST

START_TEST(test_m_to_naut_mi) {
    double tol = pow(10, -3);
    double value_in_meters = 10000.0;
    double value_in_nautique_miles = length(value_in_meters, "m", "naut mi");
    double convert_back = length(value_in_nautique_miles, "naut mi", "m");
    ck_assert_double_eq_tol(value_in_meters, convert_back, tol);
}
END_TEST

START_TEST (test_km_to_in) {
    double tol = pow(10, -3);
    double value_in_km = 1000.0;
    double value_in_inches = length(value_in_km, "km", "in");
    double convert_back = length(value_in_inches, "in", "km");
    ck_assert_double_eq_tol(value_in_km, convert_back, tol);
}
END_TEST

START_TEST(test_km_to_mi) {
    double tol = pow(10, -3);
    double value_in_km = 10000.0;
    double value_in_miles = length(value_in_km, "km", "mi");
    double convert_back = length(value_in_miles, "mi", "km");
    ck_assert_double_eq_tol(value_in_km, convert_back, tol);
}

START_TEST(test_km_to_naut_mi) {
    double tol = pow(10, -3);
    double value_in_km = 10000.0;
    double value_in_nautique_miles = length(value_in_km, "km", "naut mi");
    double convert_back = length(value_in_nautique_miles, "naut mi", "km");
    ck_assert_double_eq_tol(value_in_km, convert_back, tol);
}


Suite* convert_suite(void) {
    Suite *s;
    TCase *tc_ft_to_m;
    TCase *tc_ft_to_km;
    TCase *tc_ft_to_in;
    TCase *tc_ft_to_mi;
    TCase *tc_ft_to_naut_mi;

    TCase *tc_m_to_km;
    TCase *tc_m_to_in;
    TCase *tc_m_to_mi;
    TCase *tc_m_to_naut_mi;

    TCase *tc_km_to_in;
    TCase *tc_km_to_mi;
    TCase *tc_km_to_naut_mi;
    
    s = suite_create("Length");

    /* ft to m test case */
    tc_ft_to_m = tcase_create("ft to m");
    tcase_add_test(tc_ft_to_m, test_ft_to_m);
    suite_add_tcase(s, tc_ft_to_m);

    /* ft to km test case */
    tc_ft_to_km = tcase_create("ft to km");
    tcase_add_test(tc_ft_to_km, test_ft_to_km);
    suite_add_tcase(s, tc_ft_to_km);

    /* ft to in test case */
    tc_ft_to_in = tcase_create("ft to in");
    tcase_add_test(tc_ft_to_in, test_ft_to_in);
    suite_add_tcase(s, tc_ft_to_in);
    
    /* ft to mi test case */
    tc_ft_to_km = tcase_create("ft to mi");
    tcase_add_test(tc_ft_to_mi, test_ft_to_mi);
    suite_add_tcase(s, tc_ft_to_mi);
    
    /* ft to naut mi test case */
    tc_ft_to_km = tcase_create("ft to naut mi");
    tcase_add_test(tc_ft_to_naut_mi, test_ft_to_naut_mi);
    suite_add_tcase(s, tc_ft_to_naut_mi);
    
    /* m to km test case */
    tc_m_to_km = tcase_create("m to km");
    tcase_add_test(tc_m_to_km, test_m_to_km);
    suite_add_tcase(s, tc_m_to_km);

    /* m to in test case */
    tc_m_to_in = tcase_create("m to in");
    tcase_add_test(tc_m_to_in, test_m_to_in);
    suite_add_tcase(s, tc_m_to_in);

    /* m to mi test case */
    tc_m_to_mi = tcase_create("m to mi");
    tcase_add_test(tc_m_to_mi, test_m_to_mi);
    suite_add_tcase(s, tc_m_to_mi);
    
    /* m to naut mi test case */
    tc_m_to_naut_mi = tcase_create("m to naut mi");
    tcase_add_test(tc_m_to_naut_mi, test_m_to_naut_mi);
    suite_add_tcase(s, tc_m_to_naut_mi);
    
    /* km to in test case */
    tc_km_to_in = tcase_create("km to in");
    tcase_add_test(tc_km_to_in, test_km_to_in);
    suite_add_tcase(s, tc_km_to_in);

    /* km to mi test case */
    tc_km_to_mi = tcase_create("km to mi");
    tcase_add_test(tc_km_to_mi, test_km_to_mi);
    suite_add_tcase(s, tc_km_to_mi);
    
    /* km to naut mi test case */
    tc_km_to_naut_mi = tcase_create("km to naut mi");
    tcase_add_test(tc_km_to_naut_mi, test_km_to_naut_mi);
    suite_add_tcase(s, tc_km_to_naut_mi);
    
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
