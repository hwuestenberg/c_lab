/* calc.c Calculator with Postfix-Notation */
#include <stdio.h>
#include <stdlib.h> 
#include "calc.h"

int main(void){
    int type;
    double op1, op2, result=0.0;
    char s[MAXOPLEN];
    double_stack stack;
    init_double_stack(&stack);    
	
    printf("Calculator with Postfix-Notation\n\n");
    printf("Example: 5 7 *  11 4 - +\n");
    printf("Quit with \"q\"\n\n");
	
     while ((type = getop(s)) != 'q' && type != EOF) {
    	switch (type) {
    	    case NUMBER:
    	    	push_double_stack(&stack,atof(s));
    	    	break;
    	    case '+':
				if(pop2ops(&stack,&op1,&op2)) 
				push_double_stack(&stack,(op1 + op2));
    	    	break;
    	    case '*':
    	    	if(pop2ops(&stack,&op1,&op2)) 
				push_double_stack(&stack,(op1 * op2));
				break;
    	    case '-':
    	    	if(pop2ops(&stack,&op1,&op2)) 
				push_double_stack(&stack,(op1 - op2));
				break;
    	    case '/':
    	    	if(pop2ops(&stack,&op1,&op2)) 
				push_double_stack(&stack,(op1 / op2));
            	break;
    	    case 'c': /* Clear : new calculation  */
    	    	delete_double_stack(&stack);
    	    	push_double_stack(&stack,0.0);
    	    	break;
    	    case '\n':
    	    	pop_double_stack(&stack,&result);
    	    	printf("\t%.8g\n", result);
    	    	push_double_stack (&stack,result);
    	    	break;
    	    default:
    	    	printf("Error: Unknown Command %s\n", s);
    	    	break;
    	}
    }
    return 0;
}


