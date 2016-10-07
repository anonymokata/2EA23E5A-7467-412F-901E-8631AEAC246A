#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void replace_substring(char * search, char* substring, char* replacement)
{
  while(1)
  { 
   if(strlen(substring) == 0)
     return;
   char buffer[4096];
   char* location = strstr(search, substring);
    
   if(!location)
     return;  
   
   size_t location_without_search = location-search;
   strncpy(buffer, search, location_without_search);
   sprintf(buffer+location_without_search, "%s%s", replacement, location + strlen(substring)); 
   strcpy(search, buffer);
  }  
}

void replace_substring_once(char* search, char* substring, char* replacement)
{
  if(strlen(substring) == 0)
     return;
   char buffer[4096];
   char* location = strstr(search, substring);
    
   if(!location)
     return;  
   
   size_t location_without_search = location-search;
   strncpy(buffer, search, location_without_search);
   sprintf(buffer+location_without_search, "%s%s", replacement, location + strlen(substring)); 
   strcpy(search, buffer);
}
