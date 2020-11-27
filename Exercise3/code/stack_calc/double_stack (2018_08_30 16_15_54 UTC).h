#ifndef __STACK_H
#define __STACK_H
#define true  1 //we can use true instead of 1
#define false 0 //we can use false instead of 0

/*************************************************************************/
/* name       : Stack                                                    */
/* Description: Data-structure to represent a Stack for double values    */
/*************************************************************************/
  typedef struct double_stack_head_struct
  {
    struct double_stack_head_struct* tail;
    double                           value;
  } double_stack_head;

  typedef struct double_stack_struct    // the structure containing the state of a stack
  {
    int        size;     // size of stack
    double_stack_head* head;
  } double_stack;

/*************************************************************************/
/* name    : init_stack                                                  */
/* args    : pointer to a Stack, which is to be initialised,             */
/* return  : void                                                        */
/* function: delete stack if already allocated; initialise structure     */
/*************************************************************************/
  void init_double_stack(double_stack* stack);

/*************************************************************************/
/* name    : delete_stack                                                */
/* args    : pointer to a Stack, which will be deleted                   */
/* return  : void                                                        */
/* function: delete reserved memory if allocated                         */
/*           set size to 0, head to NULL                                 */
/*************************************************************************/
  void delete_double_stack(double_stack* stack);

/*************************************************************************/
/* name    : empty_stack                                                 */
/* args    : pointer to a constant Stack, which will not be changed here */
/* return  : true if stack is empty, false otherwise                     */
/* function: if stack is empty return true; else return false            */
/*************************************************************************/
  int empty_double_stack(const double_stack* stack);

/*************************************************************************/
/* name    : push_stack                                                  */
/* args    : pointer to stack which is to be pushed with "value"         */
/* return  : void                                                        */
/* function: push value onto stack                                       */
/*************************************************************************/
  void push_double_stack(double_stack* stack, double value);

/*************************************************************************/
/* name    : pop_stack                                                   */
/* args    : pointer to stack which is to be poped,                      */
/*           pointer to variable to which top value is to be written     */
/* return  : true if value has been written to "value"                   */
/*           false otherwise                                             */
/* function: if stack is not empty                                       */
/*               write to "value" the top value;                         */
/*               pop head and use tail as new head                       */ 
/*               return true                                             */
/*           else return false                                           */
/*************************************************************************/
  int pop_double_stack(double_stack* stack, double* value);

#endif
