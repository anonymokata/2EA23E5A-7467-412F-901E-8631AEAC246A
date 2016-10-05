#include <stdlib.h>
#include <string.h>

#include "sort.h"
#include "subtractives.h"
#include "cross_out.h"
#include "subtraction.h"

char* subtract_numerals(char* result, const char* first_numeral, const char* second_numeral)
{
  const int MAX_NUMERAL = 40;
  result[0] = '\0';
  char first_numeral_substituted[MAX_NUMERAL];
  char second_numeral_substituted[MAX_NUMERAL];
  strcpy(first_numeral_substituted, first_numeral);
  strcpy(second_numeral_substituted, second_numeral);
  
  substitute_out_subtractives(first_numeral_substituted);
  substitute_out_subtractives(second_numeral_substituted);
  sort_descending(first_numeral_substituted);
  sort_descending(result);

  strcat(result, first_numeral_substituted);
  cross_out_numerals(result, second_numeral_substituted);
  sort_descending(result);
  substitute_in_subtractives(result);
  return result;
}
