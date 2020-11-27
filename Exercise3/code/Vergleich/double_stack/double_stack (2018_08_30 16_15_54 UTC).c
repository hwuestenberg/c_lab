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
		// allocate memory for new stack node
		double_stack_head *new_head = malloc(sizeof(double_stack_head));
		
		// make old head tail of new stack node		
		new_head->tail = stack->head;

		// make new stack node new head of stack
		stack->head = new_head;

		// assign value to stack node
		new_head->value = value;  

		// increment stack size by one
		++stack->size;
  }

  int pop_double_stack(double_stack* stack, double* value)
  {
		if(stack == NULL) // stack is empty
			return false;

    	// store head's value in "value"
		*value = stack->head->value;

		// delete the head
		double_stack_head *temp = stack->head;
		stack->head = stack->head->tail;
		free(temp);

		// decrease size of stack by one
		--stack->size;

		// return true
		return true;
  }

