#include <stdio.h>


typedef enum { empty, full } t_state;


/* global variables shall have a unique name */
#define BUFFER __UNIQUE__BUFFER__NAME__816387216
#define STATE __UNIQUE__STATE__NAME__81765276

/* global variables */
char       BUFFER; 
t_state    STATE = empty;    

/************************************************************/
/* name: get_character                                      */
/* args: void                                               */
/* return: character from stdin/character from buffer       */
/************************************************************/                                           
int get_character(void){
    if (STATE == full) { // if value available in buffer
    	STATE = empty;   // return value from buffer
    	return BUFFER;
    }else{
    	return getchar();// return value from stdin
    }
}

/************************************************************/
/* name: unget_character                                    */
/* args: character c to be put into buffer for next read    */                                          
/* return: void                                             */                                          
/************************************************************/ 
void unget_character(char c){   
    if (STATE == full){
    	printf("unget_character: Buffer full.\n");
    }else{
    	BUFFER = c;
    	STATE = full;
    }
}

