#include "help.h"
static int HELP_LINES=5;
static char help[5][80]
            ={  "COMMANDS:\tNODE(string name)\t\t:Define a Node",
                "\t\tEDGE(#id, #id, float weight)\t:Define an Edge",
                "\t\tSHORTESTPATH(#id, #id)\t\t:Calculates shortest Distance",
                "\t\tHELP\t\t\t\t:Print this help text",
				"\t\tEND\t\t\t\t:End the programme"
             };
	     
void print_help(FILE* fp)
{
  int i;
  for(i=0;i<HELP_LINES;i++)
    fprintf(fp,"%s\n",help[i]);
}
