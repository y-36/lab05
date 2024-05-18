#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/* implement stack where */

typedef struct _s_stack {
    stack_elem e;
    stack next;
    stack_elem size; // Agregamos el campo size aquí
} stack_t;

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(){
      stack s = NULL;
      return s = NULL;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){

      stack p = malloc(sizeof(stack_t));
      p->e = e;
      p->next = s;
      if (!stack_is_empty(s)){
          p->size = s->size +1;
      }else{
         p->size = 0;
      }
      s = p;
      return p;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/

stack stack_pop(stack s){
      if(!stack_is_empty(s)){
      stack a = s;
      s = s->next;
      free(a);
      }
      return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(const stack s) {
    return s ? s->size : 0;
}

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(stack s){
      assert(!stack_is_empty(s));
      return s-> e;
}

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/

bool stack_is_empty(stack s){
     return s == NULL;
}

	/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(stack s){
        stack_elem *array = NULL;
        if(s != NULL){
            unsigned int size = stack_size(s);
            array = malloc(size * sizeof(stack_elem));
            for (unsigned int i = 0;i < size; i++) {
                  array[size -i -1] = stack_top(s);
                  s = stack_pop(s);
                  
            }
        }
     return array;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack stack_destroy(stack s) {
    while (!stack_is_empty(s)) {
        s = stack_pop(s);
    }
    return s;
}

