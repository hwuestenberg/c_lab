#include <stdio.h> //printf
#include "calc.h"
/**************************************************************/
/* name: pop2ops                                              */
/* args: rational_stack* stack: stack which is to be used       */                                          
/*       rational* op1        : memory for storing stack value  */
/*       rational* op2        : memory for storing stack value  */
/* return: void                                               */                                          
/**************************************************************/ 
int pop2ops(rational_stack* stack, rational* op1, rational* op2)
{
  if(!pop_rational_stack(stack,op2))
  {
    printf("STACK EMPTY\n");
    return 0;
  }
  else if(!pop_rational_stack(stack,op1))
  {
      printf("STACK EMPTY\n");
      push_rational_stack(stack,*op2);
      return 0;
  }
  return 1;
}

