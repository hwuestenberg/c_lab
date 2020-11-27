#include <stdio.h>
#include <stdlib.h>

#include "lin_struct.h"
#include "lu_decomp.h"

int main(void) {
	// create a matrix of size 3
	int matrix_size = 3;
	double **matrix = create_square_matrix(matrix_size);
	if(matrix == NULL) {
		fprintf(stderr, "Matrix creation failed\n");
		return -1;
	}
	
	// fill matrix according to task description
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[0][2] = 2;
	matrix[1][0] = 2;
	matrix[1][1] = 3;
	matrix[1][2] = 1;
	matrix[2][0] = 3;
	matrix[2][1] = -1;
	matrix[2][2] = -1;

	// create solution vector
	double *b = create_vector(matrix_size);
	b[0] = 7;
	b[1] = 9;
	b[2] = 1;

	// create array for pivot elements
	int *piv = malloc(sizeof(int) * matrix_size);
	if(piv == NULL)	{
		fprintf(stderr, "Could not allocate space for pivot\n");
		exit(-1);
	}

	// perform LU decomposition of matrix using pivot
	int r = LU_decomp(matrix_size, matrix, piv);
	printf("LU decomposition (pivoted) returned: %i\n", r);
	print_matrix_to_screen(matrix, &matrix_size);

	// only solve linear system if the LU decomp. was successful
	if(r != 1) {
		// solve linear system using LU decomposition
		b = LU_solve(matrix, piv, &matrix_size, b);
		// print solution to screen --> non-pivoted
		print_vector_to_screen(b, &matrix_size);
	}

	// free heap memory
	free_square_matrix(matrix);
	free(piv);
	free_vector(b);
	return 0;
}
