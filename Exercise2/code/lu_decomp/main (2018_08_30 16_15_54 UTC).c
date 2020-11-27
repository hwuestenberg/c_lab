#include <stdio.h>
#include <stdlib.h>

#include "lin_struct.h"
#include "lu_decomp.h"

int main(void) {
	// create and init sqaure matrix of size 3
	int matrix_size = 3;
	double **matrix = create_square_matrix(matrix_size);
	if(matrix == NULL) {
		fprintf(stderr, "Matrix creation failed\n");
		return -1;
	}
	
	// init as given in task description
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
	b[0] = 4;
	b[1] = 6;
	b[2] = 1;

	// perform LU decomposition without pivoting
	int r = LU_decomp(matrix_size, matrix);
	printf("LU Decomposition returned: %i\n", r);
	print_matrix_to_screen(matrix, &matrix_size);

	// solve LU decomposed system without pivoting
	r = LU_solve(matrix, &matrix_size, b);
	printf("LU solve returned: %i\n", r);
	print_vector_to_screen(b, &matrix_size);

	// free heap
	free_vector(b);
	free_square_matrix(matrix);
	return 0;
}
