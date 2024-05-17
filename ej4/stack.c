#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/* implement stack where */

typedef struct _s_stack {
    stack_elem e;
    struct _s_stack *next;
} stack_t;

/**
* @brief Creates an empty stack
* @return An empty stack
*/
stack stack_empty(stack s){
      return s = NULL;
}

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
stack stack_push(stack s, stack_elem e){
      stack_t *p = (stack_t *)malloc(sizeof(stack_t));
      if (p == NULL){
          return s;
      }
      p->e=e;
      p-> next=s;
      return p;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/

stack stack_pop(stack s){
      assert(!stack_is_empty(s));
      stack_t *t = s;
      s = s->next;
      free(t);
      return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
	int l = 0;
	while(!stack_is_empty(s)){
		s = s->next;
		l++;
	}
        return l;
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
        unsigned int size = stack_size(s);
        if( size == 0){
        return NULL;
        }
    stack_elem *result = (stack_elem *)malloc(size * sizeof(stack_elem));
    
    if (result == NULL){
        exit(EXIT_FAILURE);
    }
        for (unsigned int i = 0; i < size; ++i) {
        result[i] = stack_top(s);
        s = stack_pop(s);
    }
     return result;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/

void stack_destroy(stack s){

      assert(stack_is_empty(s));
      free(s);
      
}

