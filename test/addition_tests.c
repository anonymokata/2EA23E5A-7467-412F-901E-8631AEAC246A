#include <check.h>
#include "../src/roman_math.h"

START_TEST(adds_simple_numeral_to_nothing)
{
        //at this point I realize I have no idea how to do test doubles in C.
        //but lets see how much trouble I get into.
        char result[100] = "";

        add_numerals(result, 100, "I", "");

        ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(adds_complicated_number)
{
        char result[100] = " ";

        add_numerals(result, 100, "CCCLXIX", "DCCCXLV");

        ck_assert_str_eq(result, "MCCXIV");
}
END_TEST

START_TEST(adds_MMMCMXCIX_but_produces_invalid_numeral)
{
        char result[100] = " ";

        add_numerals(result, 100, "MMMCMXCIX", "I");
        ValidationResult validation_result = validate_numeral(result);

        ck_assert_int_ne(validation_result, SUCCESS);
}
END_TEST

TCase *addition_tests(void)
{
        TCase *additionCase = tcase_create("addition");
        tcase_add_test(additionCase, adds_simple_numeral_to_nothing);
        tcase_add_test(additionCase, adds_complicated_number);
        tcase_add_test(additionCase, adds_MMMCMXCIX_but_produces_invalid_numeral);
        return additionCase;
}