/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



/* Maximum allowed length of the array */


#define MAX_SIZE 100000


unsigned int array_from_stdin(int array[], unsigned int max_size) {
  unsigned int length;
   printf("Ingrese el largo del arreglo: ");
   fscanf(stdin,"%u",&length);


   if (length==0) {
    printf("El valor ingresado es invalido: ");
    exit(EXIT_FAILURE);
   }

   for (unsigned int i=0; i<max_size; ++i) {
     printf("Ingrese un valor para la posicion %d del arreglo mayor que 0: ",i);
     fscanf (stdin,"%d",&array[i]);
     if (array[i] -1 == EOF) {
        break;
     }
    }
 
    return length;
    
}


void array_dump(int a[], unsigned int length) {
    printf("\n[");
    for (unsigned int i=0; i<length; ++i) {
        printf("%d ", a[i]);
    }
     printf("]\n");
}


int main() {
    int array[MAX_SIZE];
    
    unsigned int length = array_from_stdin(array, MAX_SIZE);

    array_dump(array, length);
    
    return EXIT_SUCCESS;
}