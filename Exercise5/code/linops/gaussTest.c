#include "linops.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
  int i,j;
  matrix test_mat={3,3,0};
  test_mat.value=(double**)calloc(3,sizeof(double*));
  test_mat.value[0]=(double*)calloc(3,sizeof(double));
  test_mat.value[1]=(double*)calloc(3,sizeof(double));
  test_mat.value[2]=(double*)calloc(3,sizeof(double));
  test_mat.value[0][0]=2;
  test_mat.value[0][1]=1;
  test_mat.value[0][2]=0;
  test_mat.value[1][0]=1;
  test_mat.value[1][1]=2;
  test_mat.value[1][2]=1;
  test_mat.value[2][0]=0;
  test_mat.value[2][1]=1;
  test_mat.value[2][2]=2;
  printf("Matrix test_mat:\n");
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%g ",test_mat.value[i][j]);
    }
    printf("\n");
  }
  vector rhs_vec={3,0};
  double rhs_value[3]={1,2,3};
  rhs_vec.value=(double*)rhs_value;
  vector result_vec={3,0};
  double result_value[3]={0,0,0};
  result_vec.value=(double*)result_value;
  printf("Right Hand Side :\n");
  for(i=0;i<3;i++)
  {
    printf("%g ",rhs_vec.value[i]);
  }
  printf("\n");  
 

  //testing solver
  //error_type solve(vector x, matrix A, vector b)
  assert(solve(result_vec,test_mat,rhs_vec)==SUCCESS);
  double result_check[3];
  /*computing Ax*/
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      result_check[i]+=test_mat.value[i][j]*result_vec.value[j];
    }
  }
  printf("Solution result_vec :\n");
  for(i=0;i<3;i++)
  {
    printf("%g ",result_vec.value[i]);
  }
  printf("\n");
  printf("Test Result :\n");
  for(i=0;i<3;i++)
  {
    printf("%g ",result_check[i]);
  }
  printf("\n");  
  assert(fabs(result_check[0]-rhs_vec.value[0])<1e-8);
  assert(fabs(result_check[1]-rhs_vec.value[1])<1e-8);
  assert(fabs(result_check[2]-rhs_vec.value[2])<1e-8);

  /*... let your test-code follow ...*/



  return 0;
}
