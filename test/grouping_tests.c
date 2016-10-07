#include <check.h>
#include "../src/grouping.h"

typedef struct  {
 char* input;
 char* expected;
} GroupingScenario;

const GroupingScenario grouping_scenarios[] = 
{
  {"", ""},
  {"VV", "X"},
  {"VVII", "XII"},
  {"VVVV", "XX"},
  {"IIIII", "V"},
  {"XXXXX", "L"},
  {"LL", "C"},
  {"CCCCC", "D"},
  {"DD", "M"}
};

START_TEST(groups_properly)
{
  char buffer[4096];
  strcpy(buffer, grouping_scenarios[_i].input);
  combine_groups(buffer);
  ck_assert_str_eq(grouping_scenarios[_i].expected, buffer);
}
END_TEST

START_TEST(groups_in_correct_order_of_precedence)
{
  char inputOutput[] = "DCCCCLXXXXVIIIII";
  combine_groups(inputOutput);
  ck_assert_str_eq("M",inputOutput);
}
END_TEST

static const GroupingScenario expansion_scenarios[] = 
{
  {"", ""},
  {"V", "IIIII"},
  {"X", "VV"},
  {"XV", "XIIIII"}
};

START_TEST(expands_groups)
{ 
  char buffer[4096];
  strcpy(buffer, expansion_scenarios[_i].input);
  expand_next_smallest_group(buffer);
  ck_assert_str_eq(expansion_scenarios[_i].expected, buffer);
}
END_TEST

TCase* grouping_tests(void)
{
  TCase* grouping = tcase_create("grouping");
  tcase_add_loop_test(grouping, groups_properly, 0, sizeof(grouping_scenarios)/sizeof(GroupingScenario));
  tcase_add_test(grouping, groups_in_correct_order_of_precedence);
  tcase_add_loop_test(grouping, expands_groups, 0, sizeof(expansion_scenarios)/sizeof(GroupingScenario));
  return grouping;
}
