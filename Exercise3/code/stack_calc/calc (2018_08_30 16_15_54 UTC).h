#ifndef __CALC_H
#define __CALC_H

#include "double_stack.h"

#define MAXOPLEN 20
#define NUMBER '0'

/* read character from stdin          */
int  get_character(void);       

/* write character back to input      */
void unget_character(int c);

/* read operator/operand from input   */
int  getop(char s[]);       

/* get upper most operands from stack */
int  pop2ops(double_stack* stack, double* op1, double* op2);
#endif
