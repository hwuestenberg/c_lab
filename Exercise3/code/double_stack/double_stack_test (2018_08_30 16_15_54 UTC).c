#include "double_stack.h"
#include <assert.h>
#include <stdio.h>
int main()
{
  double value;
  double_stack stack;
  init_double_stack(&stack);
  assert(empty_double_stack(&stack));
  push_double_stack(&stack,1);
  push_double_stack(&stack,2);
  push_double_stack(&stack,3);
  printf("1: %f\n2: %f\n3: %f\n",stack.head->value,stack.head->tail->value,stack.head->tail->tail->value);
  assert(pop_double_stack(&stack,&value));
  assert(value==3);
  assert(pop_double_stack(&stack,&value));
  assert(value==2);
  assert(pop_double_stack(&stack,&value));
  assert(value==1);
  assert(empty_double_stack(&stack));

  delete_double_stack(&stack);
  //double deletion check ;-)
  delete_double_stack(&stack);
  assert(empty_double_stack(&stack));
  printf("Test Succeeded!\n");
  return 0;
}
