#ifndef LU_DECOMP_H
#define LU_DECOMP_H

// make LU decomposition of matrix A
int LU_decomp(int n, double **A);

// solve linear system Ax=b for a LU decomposed matrix A
int LU_solve(double **A, int *n, double *b);

#endif
