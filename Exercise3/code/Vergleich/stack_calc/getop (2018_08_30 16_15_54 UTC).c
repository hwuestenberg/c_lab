#include <stdio.h>
#include <ctype.h>
#include "calc.h"


/****************************************************************************/
/* getop reads in operator or operand from stdin                            */
/****************************************************************************/
int getop(char s[]){
    int counter=0, c;
    /* terminating return-string (with '\0')                                */
    s[1] = '\0';
 
    /* read input, ignore leading white-space (tab, space)                  */
    /* postcondition: s[0] contains first regular symbol                    */
    while ((s[0] = c = get_character()) == ' ' || c == '\t')
      ;//empty loop

    /* START READING OPERATOR  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    if (!(isdigit(c) || c == '.')) return toupper(c); 
    /* FINISHED READING OPERATOR <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

    /* START READING NUMBER    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
    if (isdigit(c)) /* reading integer places                               */
      while (counter<MAXOPLEN && isdigit(s[++counter] = c = get_character()))
        ;//empty loop
    if (c == '.')   /* reading decimal places                               */   
      while (counter<MAXOPLEN && isdigit(s[++counter] = c = get_character())) 
        ;//empty loop
    /* ignore the rest of the number                                        */
    if (counter==MAXOPLEN)
    {
      printf("Given number was longer than MAXOPLEN ...\n");
      while (c == '.' || isdigit(c))
        c = get_character();
    }
    /* terminating return-string (with '\0')                                */
    s[counter] = '\0';
    /* FINISHED READING NUMBER <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/


    if (c != EOF) unget_character(c);//put last character back to buffer

    return NUMBER;     /* A number has been read                            */
}

