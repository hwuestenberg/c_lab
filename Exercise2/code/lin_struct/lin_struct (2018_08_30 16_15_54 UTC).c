#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

double* create_vector(int size) {
	// make sure size is bigger than zeros
	assert(size >= 0);

	// create an array of doubles of size size
	// calloc --> initialised with zeros
	return calloc(sizeof(double), size);
}

void free_vector(double* ptr) {
	free(ptr); // free the vector
}

double** create_square_matrix(int size) {
	// make sure size of bigger than zero
	assert(size >= 0);

	// create the root array
	double **ptr = malloc(sizeof(double*) * size);
	// create the subarray and initialise it with zeros
	double *sub_ptr = calloc(sizeof(double), size * size);

	// fill the root array with ptr from the subarray
	for(int i = 0; i < size; ++i)
		ptr[i] = sub_ptr + i * size;

	// return the root array
	return ptr;
}

void free_square_matrix(double** ptr) {
	free(*ptr); // free the subarray
	free(ptr);	// free the root array
}

// function prints a matrix to stdout
void print_matrix_to_screen(double **matrix, int *matrix_size) {
	printf("--------------------------\n"); // delimiter
	for(int i = 0; i < *matrix_size; ++i)
		for(int j = 0; j < *matrix_size; ++j) {
			printf("%f", matrix[i][j]); // print matrix entries
			if(j == *matrix_size - 1)
				printf("\n"); // print a next line if one matrix row has been printed to stdout
			else
				printf(" "); // print a white space if we're still printing one matrix row to stdout
		}	
	printf("--------------------------\n"); // delimiter
}

// print a vector to stdout
void print_vector_to_screen(double *vector, int *vector_size) {
	printf("["); // delimiter
	for(int i = 0; i < *vector_size; ++i) {
		printf("%f", vector[i]); // print vector entry
		if(i == *vector_size - 1)
			printf("]^T\n"); // print delimiter 
		else				 // or
			printf(", "); 	 // print a space
	}
}

