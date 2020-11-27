#include <stdio.h> //printf
#include "calc.h"
/**************************************************************/
/* name: pop2ops                                              */
/* args: double_stack* stack: stack which is to be used       */                                          
/*       double* op1        : memory for storing stack value  */
/*       double* op2        : memory for storing stack value  */
/* return: void                                               */                                          
/**************************************************************/ 
int pop2ops(double_stack* stack, double* op1, double* op2)
{
  if(!pop_double_stack(stack,op2))
  {
    printf("STACK EMPTY\n");
    return 0;
  }
  else if(!pop_double_stack(stack,op1))
  {
      printf("STACK EMPTY\n");
      push_double_stack(stack,*op2);
      return 0;
  }
  return 1;
}

