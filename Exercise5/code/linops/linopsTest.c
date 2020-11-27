#include "linops.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main()
{
	matrix *A,*B,*R,*A3;
	A3 = malloc(sizeof(matrix));
	create_matrix(A3,3,3);
	A3->value[0][0] = 1;
	A3->value[0][1] = 2;
	A3->value[0][2] = 3;
	
	A3->value[1][0] = 4;
	A3->value[1][1] = 5;
	A3->value[1][2] = 6;

	A3->value[2][0] = 7;
	A3->value[2][1] = 8;
	A3->value[2][2] = 9;
	
	A = malloc(sizeof(matrix));
	create_matrix(A,2,2);
	A->value[0][0] = 1;
	A->value[0][1] = 2;
	
	A->value[1][0] = 3;
	A->value[1][1] = 4;
	
	B = malloc(sizeof(matrix));
	create_matrix(B,2,2);
	B->value[0][0] = 4;
	B->value[0][1] = 3;
	
	B->value[1][0] = 2;
	B->value[1][1] = 1;
	
	R = malloc(sizeof(matrix));
	create_matrix(R,2,2);
	
	mat_mat_mul(*R,*A,*B);
	printf("Multiplication A*B gives:\n%f %f\n%f %f\n",R->value[0][0],R->value[0][1],R->value[1][0],R->value[1][1]);
	
	mat_matT_mul(*R,*A,*B);
	printf("Multiplication A*B^T gives:\n%f %f\n%f %f\n",R->value[0][0],R->value[0][1],R->value[1][0],R->value[1][1]);
	
	delete_column(2,A3);
	printf("After call\n");
	printf("A is:\ndim1: %i\tdim2:%i\n",A3->dim1,A3->dim2);
	printf("with \n0.0: %f\t0.1: %f\t1.0: %f\t1.1: %f\n",A3->value[0][0],A3->value[0][1],A3->value[1][0],A3->value[1][1]);
	
	free_matrix(A);
	free_matrix(R);
	
	// Vector testing
	vector *x,*y,*rhs;
	x = malloc(sizeof(vector));
	create_vector(x,2);
	x->value[0] = 1;
	x->value[1] = 2;
	
	rhs = malloc(sizeof(vector));
	create_vector(rhs,2);
	rhs->value[0] = 5;
	rhs->value[1] = 4;
	
	y = malloc(sizeof(vector));
	create_vector(y,2);
	
	mat_vec_mul(*y,*B,*x);
	printf("Multiplication B*x gives:\n%f %f\n",y->value[0],y->value[1]);
	
	solve(*y,*B,*rhs);
	printf("Solving B*rhs gives x:\n%f %f\n",y->value[0],y->value[1]);
	
	return 0;
}
