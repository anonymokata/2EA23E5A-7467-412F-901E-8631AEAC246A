#include <check.h>
#include "../src/roman_math.h"

START_TEST (adds_simple_numeral_to_nothing)
{
 	//at this point I realize I have no idea how to do test doubles in C.
	//but lets see how much trouble I get into.
        char result[100] = "";

	add_numerals(result, 100, "I", "");

	ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST (adds_complicated_number)
{
        char result[100] = " ";
        
	add_numerals(result, 100, "CCCLXIX","DCCCXLV");

	ck_assert_str_eq(result, "MCCXIV");
}
END_TEST

START_TEST (too_short_buffer_results_in_error)
{
        char result[80];
        
        add_numerals(result, 80, "CCCCC", "II");

        ck_assert_str_eq(result,  "Buffer must be 81+ size");
}
END_TEST

TCase* addition_tests(void)
{
  TCase *additionCase = tcase_create("addition");
  tcase_add_test(additionCase, adds_simple_numeral_to_nothing);
  tcase_add_test(additionCase, adds_complicated_number);
  tcase_add_test(additionCase, too_short_buffer_results_in_error);
  return additionCase;
}



