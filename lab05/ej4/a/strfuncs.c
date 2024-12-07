#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char *str) {
 size_t length = 0; 
 while (str[length] != '\0') {
  length++;
 } 
 
 return length;
}


char *string_filter(const char *str, char c) {
 char *filter = (char*)malloc(sizeof(str));
 unsigned int i = 0u; 
 unsigned int j = 0u; 
 while (str[i] != '\0') {
  if (str[i] != c) {
   filter[j] = str[i];
   i++;
   j++;
  } else {
   i++;
  }
 } 
  
 return filter; 
}

