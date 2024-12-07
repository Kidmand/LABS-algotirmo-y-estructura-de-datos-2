#include <assert.h>
#include <stdio.h>
#include <stdbool.h>


struct bound_data {
bool is_upperbound;
bool is_lowerbound;
bool exists;
unsigned int where;
};



bool mayor(int arr[], int length, int value) {

   bool retorno;

   for (int counter=0; counter<length; counter++) {
       if (value >arr[counter]) {
           retorno=false;
       } else 
           retorno=true;
   }
  
   return retorno; 
   
}


bool menor(int arr[], int length, int value) {
 
   bool retorno;

   for (int counter=0; counter<length; counter++) {
       if (value <arr[counter]) {
           retorno=false;
       } else {
           retorno=true; 
       }
   } 

   return retorno; 
}

bool existe(int arr[], int length, int value) {

    bool retorno;

    for (int counter=0; counter<length; counter++) {
        if (value==arr[counter]) {
            retorno=true;  
        } else
         retorno=false; 
    }

    return retorno; 
}


unsigned int posicion(int arr[], int length, int value) {

    int retorno; 

    for (int counter=0; counter<length; counter++) {
        if (value==arr[counter]){
            retorno=counter+1; 
            break;
        } else 
        retorno=length; 
    }

    return retorno;
}


struct bound_data check_bound(int value, int arr[], unsigned int length) {
  struct bound_data info; 

  info.is_upperbound = mayor(arr, length, value);
  info.is_lowerbound = menor(arr, length, value);
  info.exists = existe(arr, length, value); 
  info.where = posicion(arr, length, value);

  return info; 

}


void pedirArreglo( int a[], int length) {
  for (int counter=0; counter<length; counter++) {
    printf("Ingrese el valor de la %d posicion del arreglo: ", counter);
    scanf("%d",&a[counter]);  
  }
}




int main() {

struct bound_data info; 
    

int length;
int value;

printf ("Ingrese el largo del arreglo: ");
scanf("%d",&length);
printf ("Ingrese un valor para ser comparado por los elementos del arreglo: ");
scanf("%d",&value);

int arr[length];

pedirArreglo(arr, length);
info = check_bound(value, arr, length);

if (info.is_upperbound==info.exists) {
    printf("El valor que ingreso es una cota superior y se encuentra en la posicion %u: ",info.where);
  } 
    else if (info.is_lowerbound==info.exists) {
         printf("El valor que ingreso es una cota inferior y se encuentra en la posicion %u: ",info.where);
    }


    return 0;
}