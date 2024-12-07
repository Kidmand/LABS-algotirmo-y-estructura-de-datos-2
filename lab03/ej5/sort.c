/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"


void swap(player_t a[], unsigned int i, unsigned int j ) {
    player_t aux; 
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}


bool goes_before(player_t x, player_t y){
    return x.rank<=y.rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}



void sort(player_t a[], unsigned int length) {
     quick_sort(a,length);
  // insertion_sort(a,length);
}


 static void insert(player_t a[], unsigned int i) {
    unsigned int j;
    j=i;

    while (j>0 && goes_before(a[j],a[j-1])) {
        swap(a,j,j-1);
        j=j-1;
    }
}

void insertion_sort(player_t a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}



static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
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

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;

    if (izq<der && izq < 0u-1u && der < 0u -1u ){ 
        pivot = partition(a,izq,der);
        
        quick_sort_rec(a,izq,pivot-1);
        quick_sort_rec(a,pivot+1,der);
   }
}

void quick_sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
