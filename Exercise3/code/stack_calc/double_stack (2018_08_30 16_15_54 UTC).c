#include "double_stack.h"
#include <stdlib.h>

void init_double_stack(double_stack* stack)
{
    stack->size=0;
    stack->head=NULL;
}

void delete_double_stack(double_stack* stack)
{ 
    double tmp;
    while(!empty_double_stack(stack))
		pop_double_stack(stack,&tmp);
}

int empty_double_stack(const double_stack* stack)
{
     return (stack->size==0);
}

void push_double_stack(double_stack* stack, double value)
{
	double_stack_head* new_head = malloc(sizeof(double_stack_head));
	
	if(empty_double_stack(stack)) {
		stack->head = new_head;
	}
	else {
		new_head->tail = stack->head;
		stack->head = new_head;
	}
    new_head->value = value;
    stack->size++;
}

int pop_double_stack(double_stack* stack, double* value)
{
    if(empty_double_stack(stack)) {
		return 0;
	}
    else {
		*value = stack->head->value;
		stack->head = stack->head->tail;
		stack->size--;
		return 1;
	}
}

