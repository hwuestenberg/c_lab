#ifndef __CALC_H
#define __CALC_H

#include "rational_stack.h"
#include "rational.h"

#define MAXOPLEN 20
#define NUMBER '0'

/* read character from stdin          */
int  get_character(void);       

/* write character back to input      */
void unget_character(int c);

/* read operator/operand from input   */
int  getop(char s[]);       

/* get upper most operands from stack */
int  pop2ops(rational_stack* stack, rational* op1, rational* op2);
#endif
