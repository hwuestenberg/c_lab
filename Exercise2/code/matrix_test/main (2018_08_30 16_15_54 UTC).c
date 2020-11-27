#include <stdlib.h>
#include <stdio.h>

// use our newly created lin_struct lib
#include "lin_struct.h" 

int main(void) {
	// create a matrix of size -1 in order to test the assert() command
	int matrix_size = -1;
	double **matrix = create_square_matrix(matrix_size);
	

	// free allocated heap blocks
	free_square_matrix(matrix);

	return 0;
}
