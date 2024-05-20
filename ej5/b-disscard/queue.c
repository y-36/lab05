#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_queue {
     struct  s_node *head;
     struct  s_node *end;
     size_t size;
} queue_t;

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

static struct s_node *
create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q = malloc(sizeof(struct s_queue));
    q->head = q->end = NULL;
    q->size = 0;
    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    if (q->head==NULL) {
        q->head = q->end = new_node;
        q->size = q->size + 1;
    } else {
       q->end->next = new_node; // uwu
       q->end = new_node;
       q->size = q->size + 1;
    }
    assert(invrep(q) && !queue_is_empty(q));
    return q;
}

queue queue_disscard(queue q, unsigned int n){
	assert(invrep(q) && n <= q->size);
	if(n == 0 ){
	return queue_dequeue(q);
	}
	struct s_node *prev = NULL;
	struct s_node *actual = q->head;
	for(unsigned int i = 0; i < n; i++){
	prev = actual;
	actual = actual->next;
	}
	if (actual == q->end){
	    q->end = prev;
	}
	if(prev != NULL){
	   prev->next = actual->next;
	}
	
	destroy_node(actual);
	q->size--;
	
	return q;
	assert(invrep(q));
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->head == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->head->elem;
}

unsigned int queue_size(queue q) {
    assert(invrep(q));
    
    /*
     * COMPLETADO
     *
     */
    return q->size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node * killme=q->head;
    q->head = q->head->next;
    killme = destroy_node(killme);
    assert(invrep(q));
    return q;

}

void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->head;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->head;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}

