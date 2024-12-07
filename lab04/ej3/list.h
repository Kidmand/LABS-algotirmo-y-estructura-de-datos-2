#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>


typedef int list_elem; 

typedef struct Node {
 list_elem elem;
 struct Node *next;
}list_;

typedef list_ * list;



///////////////////CONSTRUCTORES///////////////////

list empty(void);

/*Crea una lista vacia*/

list addl(list_elem e, list l);
/*agregar el elemento e al comienzo de la lista*/

void destroy(list l);
/*libera memoria en caso de ser necesario*/

///////////////////OPERACIONES//////////////////////


bool is_empty(list l);
/*devuelve TRUE si l es vacia*/

list_elem head(list l);
/*devuelve el primer elemento de l*/

list tail(list l);
/*elimina el primer elemento de l
pre !is_empty(l)*/

list addr (list l, list_elem e);
/*agrega el elemento e al final de l*/

int length(list l);
/*devuelve el largo de la lista*/

list concat(list l, list k); 
/*agrega al final de l todos los elementos de k en el mismo orden*/

list_elem index(list l, int n); 
/*devuelve el n_esimo elemento de la lista
pre length(l)<n */

list take(list l, int n);
/*deja en l solo los primeros n elementos, eliminando el resto*/

list drop(list l, int n);
/*elimina los primeros n elementos de l*/

list copy(list l);
/*copia todos los elementos de l en la nueva lista k*/



#endif
