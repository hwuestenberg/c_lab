#ifndef LU_DECOMP_H
#define LU_DECOMP_H

// perform LU decomposition
int LU_decomp(int n, double **A, int* piv);

//  solve linear system A * x = b
double* LU_solve(double **A, int* piv, int *n, double *b);

// swap two ints 
void swap_int(int*, int*);

// find pivot element
int get_pivot(double**, int*, int*);

#endif
