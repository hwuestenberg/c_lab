#ifndef __DNS__H
#define __DNS__H
#include "struct.h"
#include <float.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "linops.h"

// Return 1 if matrix is computed without error
// else return 0
error_type calc_admitMatrix(int num_edges, Edge* edge_array, matrix* Yn);

#endif
