#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "lu_decomp.h"
#include "lin_struct.h"

int LU_decomp(int n, double **A, int* piv)
{
        double eps=1e-10;

		// init pivot table
		for(int i = 0; i < n; ++i)
			piv[i] = i;

        int i,j,k;
        for(j=0; j<n; j++)
        {
                for(i=0; i<=j; i++)
                { 
                        for(k=0; k<i; k++)
                                A[piv[i]][j] -= A[piv[i]][k]*A[piv[k]][j];
                }
                for(i=j+1; i < n; i++) // originally, it was i < n - 1 but it has to be i < n or i <= n - 1!
                {
                        for(k=0; k<j; k++)
                        	A[piv[i]][j] -= A[piv[i]][k]*A[piv[k]][j];

                        if(fabs(A[piv[j]][j]) < eps)
                        	return 1;
                }

				// determine pivot element
				int index = get_pivot(A, &n, &j);
				swap_int(&piv[j], &piv[index]);

				for(i = j + 1; i < n; ++i)
                	A[piv[i]][j] /= A[piv[j]][j];
        }
        return 0;
}

// solve the linear system as given as pseude-code
double* LU_solve(double **A, int* piv, int *n, double *b) {
	for(int i = 1; i < *n; ++i)
		for(int j = 0; j < i; ++j)
			b[piv[i]] -= A[piv[i]][j] * b[piv[j]];

	b[piv[*n - 1]] = b[piv[*n - 1]] / A[piv[*n - 1]][*n - 1];

	for(int i = *n - 2; i >= 0; --i) {
		for(int j = i + 1; j < *n; ++j)
			b[piv[i]] -= A[piv[i]][j] * b[piv[j]];
		b[piv[i]] /= A[piv[i]][i];
	}

	// copy pivoted solution vector into a new vector (unpivoted)
	double* copy = create_vector(*n);
	for(int i = 0; i < *n; ++i)
		copy[i] = b[piv[i]];

	// free old vector
	free_vector(b);

	// return new vector as solution
	return copy;
}

// function swaps the content of 2 int pointers --> pivot elements are ints
void swap_int(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// function searches for the pivot element as it is given as pseud code
int get_pivot(double** A, int* n, int* j) {
	int index_piv = *j;
	for(int i = *j + 1; i < *n; ++i)
		if(fabs(A[i][*j]) > fabs(A[i - 1][*j]))
			index_piv = i;

	return index_piv;
}

