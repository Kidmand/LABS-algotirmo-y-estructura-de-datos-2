#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    
    FILE *texto;
     texto = fopen(filepath,"r");

     if (texto==NULL) {
        printf("Error, no se pudo abrir el archivo.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(texto,"%u", &max_size);
    
    for (unsigned int i=0; i<max_size; ++i) {
      fscanf (texto,"%d",&array[i]);
    }

    fclose(texto);


    return max_size;
    
}


void array_dump(int a[], unsigned int length) {
    printf("\n[");
    for (unsigned int i=0; i<length; ++i) {
        printf("%d ", a[i]);
    }
     printf("]\n");
}