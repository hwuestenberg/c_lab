#include "rational_stack.h"
#include "rational.h"
#include <stdlib.h>

void init_rational_stack(rational_stack* stack) {
    stack->size=0;
    stack->head=NULL;
}

void delete_rational_stack(rational_stack* stack) { 
    rational tmpRat;
    while(!empty_rational_stack(stack))
		pop_rational_stack(stack,&tmpRat);
}

int empty_rational_stack(const rational_stack* stack) {
     return (stack->size==0);
}

void push_rational_stack(rational_stack* stack, rational a) {
	rational_stack_head* new_head = malloc(sizeof(rational_stack_head));
	
	if(empty_rational_stack(stack)) {
		stack->head = new_head;
	}
	else {
		new_head->tail = stack->head;
		stack->head = new_head;
	}
    new_head->rat.n = a.n;
	new_head->rat.d = a.d;
    stack->size++;
}

int pop_rational_stack(rational_stack* stack, rational* a) {
    if(empty_rational_stack(stack)) {
		return 0;
	}
    else {
		a->n = stack->head->rat.n;
		a->d = stack->head->rat.d;
		
		rational_stack_head* tmp = stack->head;
		stack->head = stack->head->tail;
		free(tmp);
		
		stack->size--;
		return 1;
	}
}

