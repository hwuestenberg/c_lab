#include <stdio.h>
#include "linops.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
error_type solve(vector _x, matrix _A, vector _b)
{
  int N=_A.dim1;
  if(N!=_A.dim2) return WRONGDIMENSION; 
  if(_x.dim!=N)  return WRONGDIMENSION;
  if(_b.dim!=N)  return WRONGDIMENSION;
  int i, j, k;                          /* loop counter */ 
  int mark;                             /* mark a line permutation */
  double tmp;                             
  double** a=(double**)calloc(N,sizeof(double*));
  for(i=0;i<N;i++)
  {
    a[i]=calloc(N,sizeof(double));
    for(j=0;j<N;j++)
      a[i][j]=_A.value[i][j];           /* copying matrix */
  }
  double*  b=(double*)calloc(N,sizeof(double));
  memcpy(b,_b.value,N*sizeof(double));
  double*  x=_x.value;                  /* Solution */

  /* Elimination */
  for(i = 1; i <= (N-1); i++)
  { 
    mark = i;
    for(k = i+1; k <= N; k++)
      if (abs(a[k-1][i-1]) > abs(a[mark-1][i-1]))
        mark = k;
    if (mark != i) /* exchange */
    {
 	   for (j = i+1; j <= N; j++) 
     {
       tmp = a[i-1][j-1]; 
       a[i-1][j-1] = a[mark-1][j-1];
       a[mark-1][j-1] = tmp;
     }
     tmp = b[i-1]; 
     b[i-1] = b[mark-1];
     b[mark-1] = tmp;
   }
   if(fabs(a[i-1][i-1])<1e-12) /*matrix may be singular or partial pivoting is not enough*/
     return NUMERICAL_ERROR;
   for(k = i+1; k <= N; k++)
   { 
     tmp = a[k-1][i-1] / a[i-1][i-1];
     for(j = i+1; j <= N; j++) 
        a[k-1][j-1] -= tmp*a[i-1][j-1];
     b[k-1] -= tmp*b[i-1];
   }
  }

  /* backward substitution */
  for(i = N; i >= 1; i--)
  { 
    for(j = i+1; j <= N; j++) 
      b[i-1] -= a[i-1][j-1] * x[j-1];
    if(fabs(a[i-1][i-1])<1e-12) /*matrix may be singular or partial pivoting is not enough*/
      return NUMERICAL_ERROR;
    x[i-1] = b[i-1] / a[i-1][i-1];
  }
  for(i=0;i<N;i++)
  {
     free(a[i]);           /* copying matrix */
  }
  free(a);
  free(b);
  
  return SUCCESS;
}
