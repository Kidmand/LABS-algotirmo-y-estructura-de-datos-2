#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "string.h"

int main() {
/* string palabra1, palabra2;
 
 printf("Ingrese la primera palabra: \n");
 scanf("%s",&palabra1);
 printf("Ingrese la segunda palabra: \n");
 scanf("%s",&palabra2);
 */
 
 const char  *k = "Daian";
 const char  *p = "Daian";
 
 string palabra1 = string_create(k);
 string palabra2 = string_create(p);
 
 if (string_less(palabra2, palabra1)) {
  printf("Palabra1 < Palabra2\n");
 } else if (string_eq(palabra1,palabra2)) {
  printf("Palabra1 = Palabra2\n");
 }

 
 return 0;
}

