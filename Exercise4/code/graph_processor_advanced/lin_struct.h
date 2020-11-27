#ifndef LINSTRUCT__H
#define LINSTRUCT__H

// Returns a vector of length size
double* create_double_vector(int size);

// Free data of a pointer for a vector
void free_double_vector(double* vector);

// Visualize as column vector
void display_double_vector(int size, double* vector);

// Returns a square matrix of length size
double** create_double_square_matrix(int size);

// Free data of a pointer to pointer for a square matrix
void free_double_square_matrix(double** matrix);

// Function to visualize the square matrix
void display_double_square_matrix(int size, double** matrix);

// Int functions for Assignment 4
// Functionality as above
int* create_int_vector(int size);

void free_int_vector(int* vector);

void display_int_vector(int size, int* vector);

int** create_int_square_matrix(int size);

void free_int_square_matrix(int** matrix);

void display_int_square_matrix(int size, int** matrix);

#endif