#ifndef LINSTRUCT_H
#define LINSTRUCT_H

// function creates a (zero) vector of size size 
// and returns it
double* create_vector(int size);

// function frees the allocated memory of a vector
void free_vector(double*);

// function creates a square matrix containing zeros
// and returns it
double** create_square_matrix(int size);

// frunction frees the allocated memory of a square matrix
void free_square_matrix(double**);

// print matrix to stdout
void print_matrix_to_screen(double**, int*);

// print vector to stdout
void print_vector_to_screen(double*, int*);

#endif
