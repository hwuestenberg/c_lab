#include <stdlib.h>
#include <stdio.h>

#include "lin_struct.h"

int main(void) {
	// create a vector of size 5
	int vector_size = 5;
	double *array = create_vector(vector_size);

	// init vector with numbers from 1 to vector size
	for(int i = 0; i < vector_size; ++i) 
		array[i] = i;

	// print vector to stdout
	for(int i = 0; i < vector_size; ++i)
		printf("array[%i]: %f\n", i, array[i]);

	// free used heap blocks
	free_vector(array);

	return 0;
}
