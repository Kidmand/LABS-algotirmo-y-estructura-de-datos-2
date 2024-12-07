#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
  unsigned int pivot;
  pivot = izq;
  ++izq;
  while (izq<=der ) {
    if (goes_before(a[izq],a[pivot])) {
        ++izq;

    }  else { 
            if (goes_before(a[pivot],a[der])){
                --der;
             } 
               else { 
                    if (goes_before(a[pivot],a[izq]) && goes_before(a[der],a[pivot])) {
                        swap(a,izq,der);
                        ++izq;
                        --der;
                }    
            }
        }
  
  }    
   
    swap(a,pivot,der);
    pivot = der;

    return pivot;

} 

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;

    if (izq<der){ 
        pivot = partition(a,izq,der);
        
        quick_sort_rec(a,izq,pivot-1);
        quick_sort_rec(a,pivot+1,der);
   }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

