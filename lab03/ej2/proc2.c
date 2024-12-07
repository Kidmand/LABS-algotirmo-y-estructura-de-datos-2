#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x >= 0) {
     *y = x;
    } 
    else {
     *y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    int *y = NULL;
    y = &res;
    a = -10;
    
    absolute(a,y);
    printf("%d",res);
    return EXIT_SUCCESS;
}

// El parametro int *y es de tipo out, primero porque lo dice 
// en el ejercicio del teorico, y segundo porque en ningún 
// momento estamos usando el valor de *y en la función absolute, 
// solo le estamos asignado un valor de salida.  
