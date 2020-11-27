 /* sortdata.c 
Erzeugt Daten auf der Standard-Ausgabe oder in einem File, die zum testen von
Sortierprogrammen verwendet werden können. 
Das Programm folgende Argumente:

sortdata [-f][-r][-s] n [filename]

Optional:
    -v : vorwärts fast sortiert
    -r : rückwärts fast sortiert
    -k : kleine Zahlen zwischen 0 und 2*n

Notwendig: n, eine Zahl die angibt wie viele Zahlen erzeugt werden sollen.

Optional: filename : Name eines Files, in das die Daten geschrieben werden.

Autor: J. Weimar, J.Weimar@tu-bs.de 03/2000
Korrigiert von Michael Otto und Markus Krebs 12.5.2000
Korrigiert und verändert von Dominik Juergens 25.11.2008
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  
 *  creates random integers in file "fp"
 */
void createdata(FILE *fp, long n, int fwd, int rwd, int small)
{
    long i;
    long maxvalue;
    int  value;
    
    if (small)
    	maxvalue = 2*n;
    else
    	maxvalue = n*1000;
    
    srand(n); //SEED
    fprintf(fp,"%ld\n",n);
    for (i=0; i<n; i++)
    {
    	if (fwd)
    	    value = (int)(i*(double)maxvalue/n + (rand() % (maxvalue*2/n)));
	if (rwd)
    	    value = (int)((n-i)*(double)maxvalue/n - (rand() % (maxvalue*2/n))+maxvalue/n);
	if(!fwd&&!rwd)
    	    value = (rand() % (maxvalue));
    	if (value >= maxvalue)
    	    value = maxvalue - (rand()%3)-1;
    	fprintf(fp,"%d\n",value);
    }
}

void printusage(FILE* fp)
{
  int i;
  char* usagestring[7] = {
	  "!!!Program generates nearly sorted random data!!!",
	  "Arguments: \t[-f]\t\tdata is approximately sorted in increasing order (optional)",
	  "\t\t[-r]\t\tdata is approximately sorted in decreasing order (optional)",
	  "\t\t[-s]\t\tcreated numbers are small (optional)",
	  "\t\tn\t\tamount of numbers",
	  "\t\t[filename]\tTargetfile (optional)",
	  "Usage: sortdata [-f][-r][-s] n [filename]"
  };
  for(i=0;i!=7;i++)
  {
    fprintf(fp,usagestring[i]);
    fprintf(fp,"\n");
  }
}

/* 
 * Main: Read and interprete arguments, open file, write data, close file
 */
int main (int argc, char* argv[])
{
    int fwd=0;
    int rwd=0;
    int small=0;
    long n=-1;
    int i;
    FILE *fp = stdout;

    /* interpreting arguments */
    for (i=1; i<argc; i++)
    {
    	if (argv[i][0] == '-')
	{     /* options */
    	    switch(argv[i][1])
	    {
    	    	case 'f': fwd = 1; break;
    	    	case 'r': rwd = 1; break;
    	    	case 's': small = 1; break;
    	    	default: printusage(stderr);
    	    }
    	}
	else if (argv[i][0] >= '0' && argv[i][0] <= '9')
    	{   /* argument is a number */
    	    sscanf(argv[i],"%ld",&n);
    	}
	else
	{   /* argument is a filename */
    	    fp = fopen(argv[i],"w");
    	}
    }
    if(fwd&&rwd)
    {
      fprintf(stderr,"Sorting nearly upwardly AND downwardly makes no sense!\n");
      return -1;
    }
    if (n == -1)
    {
    	printusage(stderr);
    	return -1;
    }
    /* create random data file */
    createdata(fp, n, fwd, rwd, small);
    
    /* close file */
    if (fp != stdout)
    {
    	fclose(fp);
    }
    return 0;
}
    
