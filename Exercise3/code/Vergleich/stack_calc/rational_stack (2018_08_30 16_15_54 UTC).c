#include "rational_stack.h"
#include "rational.h"
#include <stdlib.h>

  void init_rational_stack(rational_stack* stack)
  {
    stack->size=0;
    stack->head=NULL;
  }

  void delete_rational_stack(rational_stack* stack)
  { 
    rational tmp;
    while(!empty_rational_stack(stack))
      pop_rational_stack(stack,&tmp);
  }

  int empty_rational_stack(const rational_stack* stack)
  {
     return (stack->size==0);
  }

  void push_rational_stack(rational_stack* stack, rational value)
  {
		// allocate memory for new stack node
		rational_stack_head *new_head = malloc(sizeof(rational_stack_head));
		
		// make old head tail of new stack node		
		new_head->tail = stack->head;

		// make new stack node new head of stack
		stack->head = new_head;

		// assign value to stack node
		new_head->value = value;  

		// increment stack size by one
		++stack->size;
  }

  int pop_rational_stack(rational_stack* stack, rational* value)
  {
		if(stack == NULL) // stack is empty
			return false;

    	// store head's value in "value"
		*value = stack->head->value;

		// delete the head
		rational_stack_head *temp = stack->head;
		stack->head = stack->head->tail;
		free(temp);

		// decrease size of stack by one
		--stack->size;

		// return true
		return true;
  }

