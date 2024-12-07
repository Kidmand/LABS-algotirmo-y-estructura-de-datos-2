#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


///////////////////CONSTRUCTORES///////////////////

list empty(void) {
 
 list l = NULL;
 
 return l;
}

/*Crea una lista vacia*/

list addl(list_elem e, list l) {

 list k = malloc(sizeof(list));
 k -> elem = e;
 k -> next = l;
 
 return k; 
}
/*agregar el elemento e al comienzo de la lista*/

void destroy(list l) {
 list k = NULL; 
 
  while (l != NULL) {
   k = l;
   l = l -> next; 
   free(k); 
  }
}
/*libera memoria en caso de ser necesario*/

///////////////////OPERACIONES//////////////////////


bool is_empty(list l) {
  return l == NULL; 
}
/*devuelve TRUE si l es vacia*/

list_elem head(list l) {
 return l -> elem; 
}
/*devuelve el primer elemento de l*/

list tail(list l) {

assert(!is_empty(l));

 list k = l;
 l = l -> next; 
 free (k);
 return l; 
}
/*elimina el primer elemento de l
pre !is_empty(l)*/

list addr (list l, list_elem e) {
  list p,q; 
  q = malloc(sizeof(list));
  q -> elem = e;
  q -> next = NULL;
  p = l; 
  
  if (l == NULL) {
   l = q; 
  } else {
  
   while (p -> next != NULL) {
    p = p -> next; 
   } 
   
   p -> next = q; 
 } 
 
  
  return l; 
}
/*agrega el elemento e al final de l*/

int length(list l) {
 list p = l; 
 unsigned int n = 0u;
 
  while (p != NULL) {
   n++;
   p = p -> next;
  }
 return n; 
}
/*devuelve el largo de la lista*/

list concat(list l, list k) {
 list p, q;
 p = l; 
 q = k; 
 
 if (p == NULL) {
  l = k; 
 } else {
  while (p -> next != NULL) {
   p = p -> next;
  }
  
  p -> next = q; 
 }
 
 return l; 
}
/*agrega al final de l todos los elementos de k en el mismo orden*/

list_elem index(list l, int n) {
 assert (length(l) < n);
 
 list p = l; 
 for (int i = 0u; i<n; ++i) {
  p = p -> next; 
 }
 
 return p -> elem; 
}
/*devuelve el n_esimo elemento de la lista
pre length(l)<n */

list take(list l, int n) {
 list p, q;
 p = l; 
 q = NULL; 

 while (p -> next != NULL && n>0) {
   p = p -> next;
   n--;
 }
 q = p; 
 p = p -> next;
 q -> next = NULL; 
 
 while (p != NULL) {
  q = p; 
  p = p -> next;
  free (q);  
 }
 
 return l; 
}


/*deja en l solo los primeros n elementos, eliminando el resto*/

list drop(list l, int n) {
 list p = l;
 
 while (l -> next != NULL && n>0) {
  l = l -> next; 
  free(p);
  p = l; 
 }
 
 return l; 
}
/*elimina los primeros n elementos de l*/

list copy(list l) {
 list p, k;
 k = NULL;
 p = l;
 
 while (p != NULL) {

   k = addr(k,p -> elem);
   p = p -> next;
 } 

 return k; 
}
/*copia todos los elementos de l en la nueva lista k*/

