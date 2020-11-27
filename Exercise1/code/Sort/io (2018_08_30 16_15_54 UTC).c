#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int is_eof(FILE* fp)
{
  char tmp=getc(fp);
  ungetc(tmp,fp);
  if(tmp==EOF)
    return 1;
  else
    return 0;  
}


int read(FILE* fp, int** data, int* n)
{
  int  i;
  //char tmp;
  assert(!feof(fp));                    // stream is OK
  assert((*data)==NULL);                  // data is not present
  if(!is_eof(fp))                       // if not end of file 
    fscanf(fp,"%i",n);                  // read size of array
  else
  {
    fprintf(stderr,"Unexpected End of File\n");
    return -1;
  }
  (*data)=(int*)calloc(sizeof(int),*n); // allocate memory for array
  for(i=0;i<(*n);i++)                   // loop over the entries
  {
   if(!is_eof(fp))
   {
     fscanf(fp,"%i",(*data)+i);         // read entry i
   }
   else
   {
     fprintf(stderr,"Unexpected End of File\n");   
     return -1;
   }
  }
  return 0;
}

void write(FILE* fp, int* data, int n)
{
  int i;
  assert(!feof(fp));                    // stream is OK
  assert(data!=NULL);                  // data is present
  fprintf(fp,"%i\n",n);                 // write array length
  for(i=0;i<n;i++)                      // loop over the entries
    fprintf(fp,"%i\n",data[i]);         // write entry i
}
