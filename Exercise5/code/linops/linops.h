#ifndef LINOPS__H
#define LINOPS__H
#include <stdlib.h>
#include <stdio.h>
  typedef enum error_type_enum { SUCCESS=1, GENERALERROR=-1, WRONGDIMENSION=-2, NUMERICAL_ERROR=-3 } error_type;
  typedef struct matrix_struct
  {
     int dim1;
     int dim2;
     double** value;
  } matrix;
  typedef struct vector_struct
  {
     int dim;
     double* value;
  } vector;

  void create_matrix(matrix* mat, int _dim1, int _dim2);
  void free_matrix(matrix* mat);
  void copy_matrix(matrix* new_mat, matrix old_vec);
  void print_matrix(matrix* mat);
  void create_vector(vector* vec, int _dim);
  void free_vector(vector* vec);
  void copy_vector(vector* new_vec, vector old_vec);
  void print_vector(vector* vec);

  /* implement multiplication result=AB */
  error_type mat_mat_mul(matrix result, matrix A, matrix B);

  /* implement multiplication result=AB^T */
  error_type mat_matT_mul(matrix result, matrix A, matrix B);

  /* implement multiplication result=Ax */
  error_type mat_vec_mul(vector result, matrix A, vector x);

  /* delete row i of matrix*/
  error_type delete_row(int i,matrix* A);

  /* delete column i of matrix*/
  error_type delete_column(int i,matrix* A);

  /* solve Ax=b */
  error_type solve(vector x, matrix A, vector b);
#endif

