#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/* implement stack where */

typedef struct _s_stack {
    stack_elem e;
    stack next;
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
      stack_t *new = malloc(sizeof(struct _s_stack));
      if (new == NULL){
          return s;
      }
      new->e = e;
      new->next =s;
      return new;
}

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/

stack stack_pop(stack s){
      if(!stack_is_empty(s)){
      stack t = s;
      s = s->next;
      free(t);
      }
      return s;
}

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack s){
	unsigned int c = 0u;
	if(!stack_is_empty(s)){
	stack p = s;
	c++;
	    while(p->next != NULL){
		p = p->next;
		c++;
	    }
	}
        
        return c;
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
        stack_elem *r = NULL;
        if (!stack_is_empty(s)){
           r = calloc(stack_size(s), sizeof(stack_elem));
           stack a = s;
           int n = stack_size(s);
           for (int i = n-1; i>-1; --i){
               r[i] = stack_top(a);
               a = a-> next;
           }
        }
        return r;
}

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/

stack stack_destroy(stack s){
     
      while(!stack_is_empty(s)){
          s = stack_pop(s);
      }
      return s;
      
}

