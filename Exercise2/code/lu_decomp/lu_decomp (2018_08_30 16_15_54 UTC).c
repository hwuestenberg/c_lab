#include <math.h>

int LU_decomp(int n, double **A)
{
        double eps=1e-10;
        int i,j,k;
        for(j=0; j<n; j++)
        {
                for(i=0; i<=j; i++)
                {
                        for(k=0; k<i; k++)
                                A[i][j] -= A[i][k]*A[k][j];
                }
                for(i=j+1; i < n; i++) // originally, it was i < n - 1 but it has to be i < n or i <= n - 1!
                {
                        for(k=0; k<j; k++)
                        	A[i][j] -= A[i][k]*A[k][j];

                        if(fabs(A[j][j]) < eps)
                        	return 1;
                        A[i][j] /= A[j][j];
                }
        }
        return 0;
}

// solve LU decomposed system as it is given as pseudo-code
int LU_solve(double **A, int *n, double *b) {
	for(int i = 1; i < *n; ++i)
		for(int j = 0; j < i; ++j)
			b[i] -= A[i][j] * b[j];

	b[*n - 1] = b[*n - 1] / A[*n - 1][*n - 1];

	for(int i = *n - 2; i >= 0; --i) {
		for(int j = i + 1; j < *n; ++j)
			b[i] -= A[i][j] * b[j];
		b[i] /= A[i][i];
	}

	return 0;
}

