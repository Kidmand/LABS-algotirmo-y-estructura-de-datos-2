#include <stdlib.h>
#include <assert.h>
#include "stack.h"

 
struct _s_stack {
 stack_elem elem;
 unsigned int size; 
 struct _s_stack *next;
};

stack stack_empty() {
 stack s = NULL; 
 return s; 
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e) {
 stack q;
 q = malloc(sizeof(struct _s_stack));
 q -> elem = e; 
 q -> size = s == NULL ? 1: s -> size + 1u;
 q -> next = s;

 return q; 
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack stack_pop(stack s) {

assert(!stack_is_empty(s));
  stack p = s; 
  s = s -> next;
  if (s != NULL) {
    s -> size = p -> size - 1;
  } 
  free (p);
  return s; 
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s) {
 unsigned int sizet;
  if (s == NULL) {
   sizet = 0;
  } else {
   sizet = s -> size;
  }
 return sizet; 
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s) {

assert(!stack_is_empty(s));

 return s -> elem; 
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack s) {
 return s == NULL; 
}

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s) {

 stack p = s; 
 stack_elem *arreglo_calloc; 
 unsigned int size = stack_size (s);
 
 if (s == NULL || size == 0u) {
  arreglo_calloc = NULL;
 } else {
  arreglo_calloc = calloc(size, sizeof(stack_elem));
  for (unsigned int i = 0u; i<size; ++i) {
   arreglo_calloc[i] = p -> elem; 
   p = p -> next; 
  }
 }
 return arreglo_calloc; 
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
 stack p; 

 while (s != NULL) {
  p = s; 
  s = s -> next; 
  free (p);
 }
 
 return s; 
}


