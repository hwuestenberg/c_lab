/* calc.c Calculator with Postfix-Notation */
#include <stdio.h>
#include <stdlib.h> 
#include "calc.h"
#include "rational.h"
#include <assert.h>

int main(void){
    int type;
    rational op1, op2, result=(rational){0,0}, zero=(rational){0,0};
    char s[MAXOPLEN];
    rational_stack stack;
    init_rational_stack(&stack);
	
    printf("Calculator with Postfix-Notation for rational numbers\n\n");
    printf("Example: 1|2 2|1 * 11|1 4|2 - +\n");
    printf("Quit with \"q\"\n\n");
	
     while ((type = getop(s)) != 'q' && type != EOF) {
    	switch (type) {
    	    case NUMBER:
    	    	push_rational_stack(&stack,rattostring(s));
    	    	break;
    	    case '+':
				if(pop2ops(&stack,&op1,&op2)) 
					push_rational_stack(&stack,rat_add(op1,op2));
    	    	break;
    	    case '*':
    	    	if(pop2ops(&stack,&op1,&op2)) 
					push_rational_stack(&stack,rat_mul(op1,op2));
				break;
    	    case '-':
    	    	if(pop2ops(&stack,&op1,&op2)) 
					push_rational_stack(&stack,rat_sub(op1,op2));
				break;
    	    case '/':
    	    	if(pop2ops(&stack,&op1,&op2)) 
					push_rational_stack(&stack,rat_div(op1,op2));
            	break;
			/*case '|':
				if(pop2ops(&stack,&op1,&op2))
					push_rational_stack(&stack,rat2f((rational) {(int)op1,(int)op2}));*/
    	    case 'c':
    	    	delete_rational_stack(&stack);
    	    	push_rational_stack(&stack,zero);	// There is probably a better way than using 'zero'
    	    	break;
    	    case '\n':
    	    	pop_rational_stack(&stack,&result);
				result = rat_normal(result);
    	    	printf("\t%i|%i (%.4g)\n", result.n,result.d,rat2f(result));
    	    	push_rational_stack (&stack,result);
    	    	break;
    	    default:
    	    	printf("Error: Unknown Command %s\n", s);
    	    	break;
    	}
    }
    return 0;
}


