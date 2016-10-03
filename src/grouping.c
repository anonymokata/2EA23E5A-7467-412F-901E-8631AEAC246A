#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "grouping.h"

void combine_groups(char * numeral)
{ 
  char buffer[4096];
  char* location = strstr(numeral, "VV");
  if(!location)
    return;  

  strncpy(buffer, numeral, location-numeral);
  sprintf(buffer+(location-numeral), "%s%s", "X", location + strlen("VV")); 
  strcpy(numeral, buffer);
}

