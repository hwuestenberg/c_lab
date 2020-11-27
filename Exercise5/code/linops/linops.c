#include "linops.h"
#include <assert.h>
void create_matrix(matrix* mat, int _dim1, int _dim2) {
	assert(_dim1>0 && _dim2>0);
	mat->dim1 = _dim1;
	mat->dim2 = _dim2;
	
	mat->value=(double**)malloc(sizeof(double*)*_dim1);
	mat->value[0] = (double*)calloc(sizeof(double),_dim1*_dim2);
	
	for( int i=1; i<_dim1; i++ ) {
		mat->value[i] = mat->value[i-1] + _dim2;
	}
}

void free_matrix(matrix* mat) {
	free(mat->value[0]);	// Free pointer
	free(mat->value);		// Free pointer to pointer
	free(mat);				// Free struct
}

void copy_matrix(matrix* new_mat, matrix old_mat) {
	new_mat->dim1 = old_mat.dim1;
	new_mat->dim2 = old_mat.dim2;
	
	for(int i=0; i<new_mat->dim1; ++i) {
		for(int j=0; j<new_mat->dim2; ++j) {
			new_mat->value[i][j] = old_mat.value[i][j];
		}
	}
}

void print_matrix(matrix* mat) {
	for( int j=0; j<mat->dim1; j++) {
		printf("\n");
		for( int i=0; i<mat->dim2; i++) {
			printf("%5.4f\t",mat->value[j][i]);
		}
	}
	printf("\n");
}

void create_vector(vector* vec, int _dim) {
	assert(_dim>0);
	vec->dim = _dim;
	
	vec->value = (double*)malloc(sizeof(double)*_dim);
}

void free_vector(vector* vec) {
	free(vec->value);	// Free pointer
	free(vec);			// Free struct
}

void copy_vector(vector* new_vec, vector old_vec) {
	new_vec->dim = old_vec.dim;
	
	for(int i=0; i<new_vec->dim; ++i) {
		new_vec->value[i] = old_vec.value[i];
	}
}

void print_vector(vector* vec) {
	printf("\n");
	for( int j=0; j<vec->dim; j++) {
		printf("%5.4f\t",vec->value[j]);
	}
	printf("\n");
}

/* implement multiplication result=AB */
error_type mat_mat_mul(matrix result, matrix A, matrix B)
{
	int i,j,k;
	double sum = 0.0;
	
	if(A.dim1!=B.dim2) return WRONGDIMENSION;
	if(result.dim1!=A.dim1||result.dim2!=B.dim2) return WRONGDIMENSION;
	
	for(i=0;i<result.dim1;++i) {
		for(j=0;j<result.dim2;++j) {
			for(k=0;k<result.dim2;++k) {
				sum = sum + A.value[i][k]*B.value[k][j];
			}
		result.value[i][j] = sum;
		sum = 0.0;
		}
	}
	return SUCCESS;
}

/* implement multiplication result=AB^T */
error_type mat_matT_mul(matrix result, matrix A, matrix B)
{
	int i,j,k;
	double sum = 0.0;
	
	if(A.dim1!=B.dim2) return WRONGDIMENSION;
	if(result.dim1!=A.dim1||result.dim2!=B.dim2) return WRONGDIMENSION;
	
	for(i=0;i<A.dim1;++i) {
		for(j=0;j<B.dim2;++j) {
			for(k=0;k<A.dim1;++k) {
				sum = sum + A.value[i][k]*B.value[j][k];
			}
		result.value[i][j] = sum;
		sum = 0.0;
		}
	}
	return SUCCESS;
}

/* implement multiplication result=Ax */
error_type mat_vec_mul(vector result, matrix A, vector x)
{
	int i,j;
	double sum = 0.0;
	
	if(A.dim1!=x.dim) return WRONGDIMENSION;
	if(result.dim!=A.dim1) return WRONGDIMENSION;
	
	for(i=0;i<A.dim1;++i) {
		for(j=0;j<x.dim;++j) {
			sum = sum + A.value[i][j]*x.value[j];
		}
	result.value[i] = sum;
	sum = 0.0;
	}
	return SUCCESS;
}

/* delete row i of matrix*/
error_type delete_row(int i, matrix* A) {
	if(i>A->dim1) return WRONGDIMENSION;
	if(i<0) return WRONGDIMENSION;
	if(A->dim1<2) return GENERALERROR;
	
	A->dim1--;	// Decrease row dimension
	// Move all elements "upwards" starting at row i
	while(i<A->dim1) {
		for(int j=0;j<A->dim2;++j) {
			A->value[i][j] = A->value[i+1][j];
		}
		i++;
	}
	// Resize and reset pointer to pointer
	A->value[0] = realloc(A->value[0], sizeof(double)*A->dim1*A->dim2);
	for(int j=1;j<A->dim1;++j)
		A->value[j] = A->value[j-1] + A->dim2;
	
	return SUCCESS;
}

/* delete column i of matrix*/
error_type delete_column(int i, matrix* A) {
	if(A->dim2<i) return WRONGDIMENSION;
	if(i<0) return WRONGDIMENSION;
	if(A->dim2<2) return GENERALERROR;

	int k,j,l=0;
	for(k=0;k<A->dim1;++k) 
		for(j=0;j<A->dim2;++j) {
			if( j == i ) // Detect column i (only first time)
				l++;
			else 
			*(A->value[0]+j+k*(A->dim2)-l) = *(A->value[0]+j+k*(A->dim2));
		}
	
	A->dim2--;	// Decrease column dimension
	// Resize and reset pointer to pointer
	A->value[0] = realloc(A->value[0], sizeof(double)*A->dim1*A->dim2);
	for(int j=1;j<A->dim1;++j)
		A->value[j] = A->value[j-1] + A->dim2;
	
	return SUCCESS;
}

