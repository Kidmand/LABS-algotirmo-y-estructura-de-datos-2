#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};


stack stack_empty() {
 stack s = malloc(sizeof(struct _s_stack));
 s -> capacity = 0;
 s -> size = 0; 
 s -> elems = NULL;
 //calloc(s -> capacity, sizeof(stack_elem));

 return s; 
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e) {
 assert (s != NULL);
  size_t new_cap = s -> size == 0 ? 1 : s -> size*2;
  s -> capacity = new_cap;
  s -> elems = realloc(s -> elems, sizeof(stack_elem)* new_cap);
 
  s -> elems[s -> size] = e;
  s -> size++; 
 
 return s; 
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s) {

assert(!stack_is_empty(s));
 s -> size--; 
  return s; 
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s) {
 return s -> size; 
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s) {

assert(!stack_is_empty(s));
assert(s -> size > 0);

 return s -> elems[s -> size - 1]; 
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s) {
 assert (s != NULL);
 return s -> size == 0; 
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s) {
 stack_elem *new_array;
 new_array = calloc(s -> capacity, sizeof(stack_elem));
 for (unsigned int i = 0u; i<s->size; ++i) {
  new_array[i] = s -> elems[i];
 }
 
 return new_array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
 free (s -> elems);
 free (s);
 return s; 
}


