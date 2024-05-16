#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

// Crear una pila vacía
stack stack_empty() {
    struct _s_stack *s = (struct _s_stack *)malloc(sizeof(struct _s_stack));
    assert(s != NULL);
    s->elems = NULL;
    s->size = 0;
    s->capacity = 0;
    return s;
}

// Insertar un elemento en la parte superior de la pila
stack stack_push(stack s, stack_elem e) {
    if (s->size == s->capacity) {
        // Pedir más memoria (doble de la capacidad actual)
        s->capacity = (s->capacity == 0) ? 1 : s->capacity * 2;
        s->elems = (stack_elem *)realloc(s->elems, s->capacity * sizeof(stack_elem));
        assert(s->elems != NULL);
    }
    s->elems[s->size++] = e;
    return s;
}

// Eliminar el elemento en la parte superior de la pila
stack stack_pop(stack s) {
    if (s->size > 0) {
        s->size--;
    }
    return s;
}

// Obtener el tamaño actual de la pila
unsigned int stack_size(stack s) {
    return s->size;
}

// Obtener el elemento en la parte superior de la pila
stack_elem stack_top(stack s) {
    assert(s->size > 0); // Verificar si la pila no está vacía
    return s->elems[s->size - 1];
}

// Verificar si la pila está vacía
bool stack_is_empty(stack s) {
    return (s->size == 0);
}

// Crear un arreglo con todos los elementos de la pila
stack_elem *stack_to_array(stack s) {
    stack_elem *arr = (stack_elem *)malloc(s->size * sizeof(stack_elem));
    assert(arr != NULL);
    for (unsigned int i = 0; i < s->size; i++) {
        arr[i] = s->elems[i];
    }
    return arr;
}

// Liberar todos los recursos de memoria asociados con la pila
stack stack_destroy(stack s) {
    free(s->elems);
    free(s);
    return NULL;
}

