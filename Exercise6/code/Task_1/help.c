#include "help.h"
static int HELP_LINES=4;
static char help[4][80]
            ={  "COMMANDS:\tNODE(string name): Define a Node",
                "\t\tEDGE(#id, #id, float weight): Define an Edge",
                "\t\tEND: Quits input and proceeds with calculation",
                "\t\tHELP: Print this help text"
             };

void print_help(FILE* fp)
{
  int i;
  for(i=0;i<HELP_LINES;i++)
    fprintf(fp, "%s\n",help[i]);
}
